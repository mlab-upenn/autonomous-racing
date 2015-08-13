#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "math.h"
#include <stdlib.h>
#include <sstream>
#include "basic_path_plan/driveCmd.h"


/* Contains information about a particular lidar data point in polar and
 * Cartesian coordinates */
typedef struct lidar_dist {
  float ang_rad;
  float range;
  double dist_x;
  double dist_y;
} lidar_dist;

typedef struct equation_parameters {
  double m;
  double b;
  double avg_err;
} equation_parameters;

typedef enum angle_type {
  RADIAN=0, DEGREE=1
};

int hokuyo_data_set = 0;
float ang_min = 0;
float ang_max = 0;
float ang_inc_rad = -1;
float ang_inc_deg = -1;
int num_ranges = -1;
lidar_dist * ranges = NULL;

/* RANSAC result FIR */
float m_buf[5];
float sum_m = 0.0;
int num_m = 0;

/* Drive commands */
const float throttle_cmd = .4;	// Constant until we want to change it 
float steering_cmd;
const float STEERING_CMD_MAX = 5.0;
const float STEERING_CMD_MIN = -5.0;

ros::Publisher drive_cmd_publisher;

void shift_into_buf(float *buf, int buf_size, float val) {
  int i;
  for(i = 0; i < buf_size - 1; i++) {
    buf[i] = buf[i+1];
  }
  buf[buf_size - 1] = val;
}

float to_radian(float angle) {
  return angle / 57.3;
}

float to_degree(float angle) {
  return angle * 57.3;
}

/* Returns the index of a specified angle in the range array */
int get_index(float angle, angle_type ang_type) {
  if(ang_type == DEGREE) {
    angle /= 57.3;
  }
  float increment = (ang_max - ang_min) / num_ranges;
  int index = (angle - ang_min) / increment;

  return index;
}

/* Returns distance information given an index */
lidar_dist get_dist_from_ind(int index) {
  return ranges[index];
}

/* Returns the distance information associated with a given angle,
 * degree or radian, of the latest lidar scan */
lidar_dist get_dist_from_ang(float angle, angle_type ang_type) {
  return get_dist_from_ind(get_index(angle, ang_type));
}

/* Returns a random angle. Uses angle increment probided by hokuyo scan. */
float get_random_degree(float ang_low, float ang_high) {
  int increments = (ang_high - ang_low) / ang_inc_deg;
  int num_incs = (rand() % increments) + 1;

  return ang_low + (num_incs * ang_inc_deg);
}

float get_random_radian(float ang_low, float ang_high) {
  return to_radian(get_random_degree(to_degree(ang_low), to_degree(ang_high)));
}

equation_parameters calculate_linear_regression(float degree1, float degree2, int iter) {
  int nonzero_count = 0;
  equation_parameters temp;
  temp.avg_err = 0;
  equation_parameters best;
  best.m = temp.m = 0;
  best.b = temp.m = 0;
  best.avg_err = 100000000;

  for(int i = 0; i < iter; i++){
    temp.avg_err = 0;
    nonzero_count = 0;

    lidar_dist rd1 = get_dist_from_ang(get_random_degree(degree1, degree2), DEGREE);
    lidar_dist rd2 = get_dist_from_ang(get_random_degree(degree1, degree2), DEGREE);
    
    if(rd1.dist_x == rd2.dist_x && rd1.dist_y == rd2.dist_x){
      continue;
    } else {   
      temp.m = (rd2.dist_y - rd1.dist_y )/(rd2.dist_x  - rd1.dist_x );
    }
    temp.b =  rd1.dist_y -temp.m*rd1.dist_x;
    
    int j = get_index(degree1, DEGREE);

    int j_max = get_index(degree2, DEGREE);
    for(;j <= j_max; j++){
      lidar_dist dp = get_dist_from_ind(j);
      	/*temp.avg_err += abs( (rd2.dist_x - rd1.dist_x) * (rd1.dist_y - dp.dist_y) -
      						 (rd1.dist_x - dp.dist_x) * (rd2.dist_y - rd1.dist_y) ) /
      						  sqrt(pow(rd2.dist_y   - rd1.dist_y,2) + 
                                  pow(rd2.dist_x   - rd1.dist_x,2));*/
        temp.avg_err += abs((rd2.dist_y - rd1.dist_y) * dp.dist_x - 
                            (rd2.dist_x  - rd1.dist_x) * dp.dist_y +
                            rd2.dist_x  * rd1.dist_y - rd2.dist_y  * rd1.dist_x)/
                            (sqrt(pow(rd2.dist_y   - rd1.dist_y,2) + 
                                  pow(rd2.dist_x   - rd1.dist_x,2)));
        nonzero_count++;
    }
    temp.avg_err /= nonzero_count;
    if(temp.avg_err < best.avg_err){
      best.m = temp.m;
      best.b = temp.b;
      best.avg_err = temp.avg_err;
      
    } 
  }
  
  return best;
}

float saturate_float(float val, float min, float max) {
	return (val < min ? min : (val > max ? max : val));
}

/* Todo:	1. either make ang_des an argument or allow it to be changed elsewhere 
*					2. reset function for integral term if using it  */ 
float pid_steering(float cur_slope) {
	static const float kp = 0.0;
	static const float kd = 0.0;
	static const float ki = 0.0;

	static const float ang_des = 0.0;

	static float err_cur = 0.0;
	static float err_old = 0.0;
	static float err_sum = 0.0;	

	err_old = err_cur;
	err_sum += err_cur;
	err_cur = ang_des - cur_slope;

	float err_change = err_cur - err_old;

	float out = kp*err_cur + ki * err_sum - kd*err_change;

	return saturate_float(out, STEERING_CMD_MIN, STEERING_CMD_MAX);
}

void scanReceiveCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
	//ROS_INFO("%f %f %d", msg->angle_min, msg->angle_max, msg->ranges.size());

  /* Maybe make code to change range array if any of these three values changes ?*/
  if(!hokuyo_data_set) {
    ang_min = msg->angle_min;
    ang_max = msg->angle_max;
    ang_inc_rad = msg->angle_increment;
    ang_inc_deg = ang_inc_rad * 57.3;
    num_ranges = msg->ranges.size();

    hokuyo_data_set = 1;
  }

  if(ranges == NULL) {
    if( (ranges = (lidar_dist *)malloc(sizeof(lidar_dist) * msg->ranges.size())) == NULL) {
      ROS_INFO("malloc failed for range array. exiting.");
      exit(1);
    }
  }

  for(int i = 0; i < num_ranges; i++) {
    float ang_cur = ang_min + i*ang_inc_rad;
    float range_cur = msg->ranges[i];

    ranges[i].ang_rad = ang_cur;
    ranges[i].range = range_cur;
    ranges[i].dist_x = range_cur * sin(ang_cur);
    ranges[i].dist_y = range_cur * cos(ang_cur);
  }

  //ROS_INFO("==%f==", get_dist_from_ang(0.0, DEGREE).range);
  equation_parameters temp = calculate_linear_regression(-110, -80, 5000);
  if(num_m < 5) {
    m_buf[4-num_m] = temp.m;
    num_m++;
  }
  else {
    sum_m -= m_buf[4];
    shift_into_buf(m_buf, 5, temp.m);
  }
  sum_m += temp.m;

  float res = -.08f +  (sum_m/num_m);	
	printf("%1.3f %.3f\n", res, temp.b);
	printf("%f\n", m_buf[4] - m_buf[3]);
	printf("---\n");
	//ROS_INFO("%1.3f %.3f", res, temp.b);
  //ROS_INFO("%d", msg->ranges.size());  

  basic_path_plan::driveCmd drive_cmd;
	drive_cmd.throttle = throttle_cmd;
	drive_cmd.steering = pid_steering(sum_m / num_m); 	
	drive_cmd_publisher.publish(drive_cmd);
}

int main(int argc, char **argv)
{
	/* Initialize node */
  ros::init(argc, argv, "planner");
  ros::NodeHandle n;

	/* Initialize subscriber */
  ros::Subscriber sub = n.subscribe("scan", 1000, scanReceiveCallback);

	/* Initialize publisher */
	drive_cmd_publisher = n.advertise<basic_path_plan::driveCmd>("lidar_path_plan", 1000);


	ros::spin();

  free(ranges);
	return 0;
}

/* To do: 
 * 1. pid for angle
 *		a. determine whether or not to scale readings
 *		b. determine direction to turn
 *		c. gains
 * 2. motor command interface 
 *		a. what message to publish
 * 3. see what happens on the car with the noisy RANSAC measurement. Some ways
 *		to potentially improve the algorithm:
 *		a. ignore bad data - seems risky, lose current info
 *    b. check point against data, if it's bad, factor it into the current average but keep it
 *		   out of the buffer
 *    c. if a point is a freak outlier, place it in a loser's buffer. if the next point is close
 *			 add the origina point to the buffer. Else, discard it.
 *    d. increase ransac cycles - limited amount of computation, though, and may not be worth devoting so
 *			 many clock cycles to RANSAC
 */
