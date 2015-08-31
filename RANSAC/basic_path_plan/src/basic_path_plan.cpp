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
  double cost;
  int flag;
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
const float STEERING_CMD_MAX = 2.0;
const float STEERING_CMD_MIN = -2.0;

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

int get_random_index(int num_els) {
	return rand() % num_els;
}

float msac_dist(lidar_dist p1, lidar_dist p2, lidar_dist p_test) {
	/*float a = (p2.dist_y - p1.dist_y) * p_test.dist_x;
	float b = (p2.dist_x - p1.dist_x) * p_test.dist_y;
	float c = p2.dist_x * p1.dist_y - p2.dist_y * p1.dist_x;
	float d = sqrt(pow(p2.dist_y - p1.dist_y, 2) + pow(p2.dist_x - p1.dist_x, 2));

	float res = fabsf((p2.dist_y - p1.dist_y) * p_test.dist_x - 
						 (p2.dist_x - p1.dist_x) * p_test.dist_y +
						  p2.dist_x * p1.dist_y - p2.dist_y * p1.dist_x) /
						 (sqrt(pow(p2.dist_y - p1.dist_y, 2) + 
									 pow(p2.dist_x - p1.dist_x, 2))); */

	float a = (p2.dist_x - p1.dist_x)*(p1.dist_y - p_test.dist_y);
	float b = (p1.dist_x - p_test.dist_x)*(p2.dist_y - p1.dist_y);
	float c = sqrt( pow(p2.dist_x - p1.dist_x, 2) + pow(p2.dist_y - p1.dist_y, 2) );
	float res = fabsf(a - b) / c;

	return res;
}

/* Finds best model for points [degree1, degree2] using the MSAC flavor of RANSAC
 * and a linear regression algorithm on the set inliers generated from MSAC */
equation_parameters run_msac_and_regression(lidar_dist* dists, int num_dists, int iter) {
  static const float dist_thresh = 0.05;	// Maximum allowable threshold, in meters for inlier classification

  equation_parameters temp;
  equation_parameters best;

  best.m = temp.m = 0;
  best.b = temp.m = 0;
  best.cost = 100000000;

  int num_inliers_cur, num_inliers_best = 0;
  lidar_dist p1_best, p2_best;

  int min_ind = 0;
  int max_ind = num_dists-1;

  /* Run MSAC to get best-fitting model */
  for(int i = 0; i < iter; i++) {
    temp.cost = 0;
	num_inliers_cur = 0;

    lidar_dist rd1 = dists[get_random_index(num_dists)];
    lidar_dist rd2 = dists[get_random_index(num_dists)];
    
    if(rd1.dist_x == rd2.dist_x && rd1.dist_y == rd2.dist_y){
    	continue;
    } else {   
      temp.m = (rd2.dist_y - rd1.dist_y )/(rd2.dist_x  - rd1.dist_x );
    }
	temp.b =  rd1.dist_y - temp.m*rd1.dist_x;
	    
	for(int j = min_ind; j <= max_ind; j++){
		lidar_dist dp = dists[j];

	    float dist_cur = msac_dist(rd1, rd2, dp);
	 
	    if(dist_cur < dist_thresh) {
			temp.cost += dist_cur;
			num_inliers_cur++; }
		else {
			temp.cost += dist_thresh;
		}
	}

	if(temp.cost < best.cost){
	    best = temp;
		p1_best = rd1;
		p2_best = rd2;
		num_inliers_best = num_inliers_cur;
	}
  }
	
  best.flag = 0;

  if(num_inliers_best != 0) {
	printf("MSAC: %f\n", best.m); 
	/* Generate set of inliers */	
	lidar_dist *inlier_set = (lidar_dist *)malloc(sizeof(lidar_dist) * num_inliers_best);
	if(!inlier_set) {
		printf("Warning; malloc failed in %s\n", __func__);
	}
	
	int inlier_count = 0;
	for(int i = 0; i < num_dists; i++) {
		lidar_dist p_test = dists[i];
		float dist_cur = msac_dist(p1_best, p2_best, p_test);
		if(dist_cur < dist_thresh) {
			inlier_set[inlier_count] = p_test;
			inlier_count++;
		}		
	}

	/* Get linear regression inputs */
	float x_avg = 0.0, y_avg = 0.0, xy_avg = 0.0, x2_avg = 0;
	for(int i = 0; i < num_inliers_best; i++) {
		/* Self-equality check to determine if a distance is NaN */
		if((inlier_set[i].dist_x == inlier_set[i].dist_x) && abs(inlier_set[i].dist_x) < 100000){
			x_avg += inlier_set[i].dist_x;
			x2_avg += inlier_set[i].dist_x * inlier_set[i].dist_x;
		}
		if((inlier_set[i].dist_y == inlier_set[i].dist_y) && abs(inlier_set[i].dist_y) < 100000){
			y_avg += inlier_set[i].dist_y;
			xy_avg += inlier_set[i].dist_x * inlier_set[i].dist_y;
		}
	}		 

	// printf("%d\n",num_inliers_best);

	x_avg /= num_inliers_best;
	y_avg /= num_inliers_best;
	xy_avg /= num_inliers_best;
	x2_avg /= num_inliers_best;

	/* Compute regression parameters */
	best.m = (xy_avg - (x_avg * y_avg)) /  (x2_avg - (x_avg * x_avg));
	best.b = y_avg - (best.m * x_avg);

	printf("Regression results: %d inliers / %d points\n", num_inliers_best, max_ind - min_ind + 1);
			
	lidar_dist origin;
	origin.dist_x = 0;
	origin.dist_y = 0;
	best.b = msac_dist(p1_best, p2_best, origin);
	free(inlier_set);
  }

  else {
	best.flag = 1;
	printf("=====================================================\n");
  }
  return best;
}

equation_parameters determine_wall_slope(float degree1, float degree2, int iter) {
	/* 1. determine central angle of sweep and rotate all measurements */
	float degree_center = (degree1 + degree2) / 2.0;
	int ind_min = get_index(degree1, DEGREE);
	int ind_max = get_index(degree2, DEGREE);

	if(ind_min > ind_max) { 
		int t = ind_min;
		ind_min = ind_max;
		ind_max = t;
	}

	int num_dists = ind_max - ind_min + 1;
	lidar_dist *wall_dists = (lidar_dist *)malloc(sizeof(lidar_dist) * num_dists);
	if(wall_dists == NULL) {
		printf("malloc failed in function %s; returning 0\n", __func__);
		equation_parameters res;
		res.m = 0;
		res.b = 0;
		res.cost = 0;
		return res;
	}

	for(int i = 0; i < num_dists; i++) {
		int ranges_ind = i + ind_min;

		wall_dists[i].range = ranges[ranges_ind].range;
		wall_dists[i].ang_rad = ranges[ranges_ind].ang_rad;
		wall_dists[i].dist_x = wall_dists[i].range * cos(wall_dists[i].ang_rad);
		wall_dists[i].dist_y = wall_dists[i].range * sin(wall_dists[i].ang_rad);
	}

	/* Run MSAC and regression on rotated range measurements */
	equation_parameters res = run_msac_and_regression(wall_dists, num_dists, iter);
	free(wall_dists);
	return res;
}

float saturate_float(float val, float min, float max) {
	return (val < min ? min : (val > max ? max : val));
}

/* Todo:	1. either make ang_des an argument or allow it to be changed elsewhere 
*					2. reset function for integral term if using it  */ 
float pid_steering(float cur_slope) {
	static const float kp = .1;
	static const float kd = 0.0;
	static const float ki = 0.0;

	static const float ang_des = 5;

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

  if(!hokuyo_data_set) {
    ang_min = msg->angle_min;
    ang_max = msg->angle_max;
    ang_inc_rad = msg->angle_increment;
    ang_inc_deg = ang_inc_rad * 57.3;
    num_ranges = msg->ranges.size();

    hokuyo_data_set = 1;
  }

	/* On first receipt of scan data, create an array to hold the incoming data */	
  if(ranges == NULL) {
    if( (ranges = (lidar_dist *)malloc(sizeof(lidar_dist) * num_ranges)) == NULL) {
      ROS_INFO("malloc failed for range array. exiting.");
      exit(1);
    }
		else {
			ROS_INFO("Now storing range data for %d points", num_ranges);
		}
	}
 
	/* Store incoming data in polar and cartesian coordinates */
  for(int i = 0; i < num_ranges; i++) {
    float ang_cur = ang_min + i*ang_inc_rad;
    float range_cur = msg->ranges[i];

    ranges[i].ang_rad = ang_cur;
    ranges[i].range = range_cur;
    ranges[i].dist_x = range_cur * sin(ang_cur);
    ranges[i].dist_y = range_cur * cos(ang_cur);
  }

	/* Check for a wall */
  //ROS_INFO("==%f==", get_dist_from_ang(0.0, DEGREE).range);
  equation_parameters temp = determine_wall_slope(70, 110, 500);
  if(num_m < 5) {
    m_buf[4-num_m] = temp.m;
    num_m++;
  }
  else {
    sum_m -= m_buf[4];
    shift_into_buf(m_buf, 5, temp.m);
  }
  if(temp.m != temp.m ){
  	sum_m += temp.m;
	}

  float res = (sum_m/num_m);
  float steering_correction = pid_steering(temp.m);
  printf("%f %f, %f\n\n", temp.m, temp.b, steering_correction);

  basic_path_plan::driveCmd drive_cmd;
	drive_cmd.throttle = throttle_cmd;
	drive_cmd.steering = steering_correction; 	
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
	if(ranges){
  		free(ranges);
  	}
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
