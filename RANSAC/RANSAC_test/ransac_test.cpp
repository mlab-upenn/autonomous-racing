#include <time.h>
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

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
  double cost;
  int flag;
} equation_parameters;

typedef enum angle_type {
  RADIAN=0, DEGREE=1
};

float ang_min_deg;
float ang_min_r;
float ang_max_deg;
float ang_max_r;
float ang_inc_deg =  .3515625;
int num_ranges = -1;
lidar_dist * ranges = NULL;

float m_buf[5];
float sum_m = 0.0;
int num_m = 0;

void init_ranges() {
	if(ranges != NULL) {
		free(ranges);
	}
  
  num_ranges = (ang_max_deg - ang_min_deg) / ang_inc_deg;

  if( (ranges = (lidar_dist *) malloc(num_ranges * (sizeof(lidar_dist)))) == NULL) {
		printf("Error: ranges malloc failed.\n");
	}
}

/* Generates an array of points given two endpoints of a line */
float to_radian(float angle) {
	return angle / 57.3;
}

float to_degree(float angle) {
	return angle * 57.3;
}

void make_line_by_endpoints() {
  float x1 = ang_min_r * cos(to_radian(ang_min_deg));
  float y1 = ang_min_r * sin(to_radian(ang_min_deg));
	
  float x2 = ang_max_r * cos(to_radian(ang_max_deg));
  float y2 = ang_max_r * sin(to_radian(ang_max_deg));

  float slope = (y2 - y1) / (x2 - x1);
  
  float intercept = y1 - slope*x1; 

  for(int i = 0; i < num_ranges; i++) {
	float ang_cur_rad = to_radian(ang_min_deg + i*ang_inc_deg);		
		
	/* Geometric equation to find r given theta */
  	float r = intercept / (sin(ang_cur_rad) - slope * cos(ang_cur_rad));
		
	/* Introduce noise */
	//r += (float) (rand() % 100 - 50) / (float) 500

	ranges[i].ang_rad = ang_cur_rad;
	ranges[i].range = r;
	ranges[i].dist_x = r*cos(ang_cur_rad);
	ranges[i].dist_y = r*sin(ang_cur_rad);
  }
}

/* Generates an array of points given the distance from it and an angle offset */
void make_line_by_r_and_tilt () {
}


void shift_into_buf(float *buf, int buf_size, float val) {
  int i;
  for(i = 0; i < buf_size - 1; i++) {
    buf[i] = buf[i+1];
  }
  buf[buf_size - 1] = val;
}

/* Returns the index of a specified angle in the range array */
int get_index(float angle, angle_type ang_type) {
  if(ang_type == RADIAN) {
    angle *= 57.3;
  }

	//printf("Angle: %f\n", angle);
  int index = (angle - ang_min_deg) / ang_inc_deg;

	//printf("%s returned %d\n", __func__, index);
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

//	printf("Random degree: %f\n", ang_low+(num_incs*ang_inc_deg)); 
  return ang_low + (num_incs * ang_inc_deg);
}

float get_random_radian(float ang_low, float ang_high) {
  return to_radian(get_random_degree(to_degree(ang_low), to_degree(ang_high)));
}

int get_random_index(int num_els) {
	return rand() % num_els;
}

float msac_dist(lidar_dist p1, lidar_dist p2, lidar_dist p_test) {
	float a = (p2.dist_y - p1.dist_y) * p_test.dist_x;
	float b = (p2.dist_x - p1.dist_x) * p_test.dist_y;
	float c = p2.dist_x * p1.dist_y - p2.dist_y * p1.dist_x;
	float d = sqrt(pow(p2.dist_y - p1.dist_y, 2) + pow(p2.dist_x - p1.dist_x, 2));

	float res = fabsf((p2.dist_y - p1.dist_y) * p_test.dist_x - 
						 (p2.dist_x - p1.dist_x) * p_test.dist_y +
						  p2.dist_x * p1.dist_y - p2.dist_y * p1.dist_x) /
						 (sqrt(pow(p2.dist_y - p1.dist_y, 2) + 
									 pow(p2.dist_x - p1.dist_x, 2))); 

	/*float a = (p2.dist_x - p1.dist_x)*(p1.dist_y - p_test.dist_y);
	float b = (p1.dist_x - p_test.dist_x)*(p2.dist_y - p1.dist_y);
	float c = sqrt( pow(p2.dist_x - p1.dist_x, 2) + pow(p2.dist_y - p1.dist_y, 2) );
	float res = fabsf(a - b) / c;*/

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
	//printf("MSAC: %f\n", best.m); 
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

	//printf("Regression results: %d inliers / %d points\n", num_inliers_best, max_ind - min_ind + 1);
			
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
		wall_dists[i].ang_rad = ranges[ranges_ind].ang_rad /*- to_radian(degree_center)*/;
		wall_dists[i].dist_x = wall_dists[i].range * cos(wall_dists[i].ang_rad);
		wall_dists[i].dist_y = wall_dists[i].range * sin(wall_dists[i].ang_rad);
	}

	/* Run MSAC and regression on rotated range measurements */
	equation_parameters res = run_msac_and_regression(wall_dists, num_dists, iter);
	free(wall_dists);
	return res;
}


float calc_slope (float x1, float x2, float y1, float y2) {
	return (y2 - y1) / (x2 - x1);
}

float calc_intercept (float x1, float y1, float m) {
	return y1 - x1 * m;
}

void show_range_stats() {
	float sum_slopes = 0;
	float sum_intercepts = 0;
	int num_lines = 0;

	int slope_err_count[21];

	for(int i = 0; i < 21; i++) { 
		slope_err_count[i] = 0;
	}

	float slope_ref = calc_slope(ranges[0].dist_x, ranges[0].dist_y,
					  ranges[num_ranges-1].dist_x, ranges[num_ranges-1].dist_y);

	float intercept_ref = calc_intercept(ranges[0].dist_x, ranges[0].dist_y, slope_ref);
	
	for(int i = 0; i < num_ranges-1; i++) {
		for(int j = i+1; j < num_ranges; j++) {
			if(i == j) continue;
		
			num_lines++;			

			float x1 = ranges[i].dist_x;
			float y1 = ranges[i].dist_y;
			float x2 = ranges[j].dist_x;
			float y2 = ranges[j].dist_y;

			float slope = calc_slope(x1, x2, y1, y2);
			float intercept = calc_intercept(x1, y1, slope);

			sum_slopes += slope;
			sum_intercepts += intercept;

			float slope_diff = abs(slope - slope_ref) / slope_ref * 100;
			float intercept_diff = abs(intercept - intercept_ref) / intercept_ref * 100;

			if(slope_diff > 100) {
				slope_err_count[20]++;
				printf("%d %d: %.3f\n\n", i, j, slope_diff);
			}	
			else {
				slope_err_count[(int)(slope_diff/5)]++;
			}
		}
	}

	printf("Range statistics:\n\n");
	printf("\tAverage slope: %f\n", sum_slopes/num_lines);
	printf("\tAverage intercept: %f\n\n", sum_intercepts/num_lines);
	printf("\tSlope Distribution: \n");
	
	for(int i = 0; i < 20; i++) {
		printf("\t\t < %d%%: %d\n", 5*(i+1), slope_err_count[i]);
	}
	printf("\t\t > 100%%: %d\n", slope_err_count[20]);
}

/* Tests algorithm over a set of walls with varying r and th */
void test_algorithm_with_walls () {
	float th_st = -110.0;	/* Start angle */
	float th_sw = 40.0;	/* Angle you want to sweep from th_st */
	float th_w_st = -60.0;	/* Starting wall angle */
	float th_w_end = 60.0;	/* Ending wall angle */
	float th_w_inc = 1.0;	/* How much you want to vary the wall angle between iterations */
	float r_w = 3.0; 			/* Distance from the wall */

	ang_min_deg = th_st;
	ang_max_deg = th_st + th_sw;

	int max_iter = (int)(fabsf(th_w_end - th_w_st) / th_w_inc);

	/* Show output header */
	printf("====================================================================\n");
	printf("===================== RANSAC TEST BENCHERONIS ======================\n");
	printf("====================================================================\n\n");
	printf("Testing algorithm with following parameters:\n");
	printf("\t1. Sweeping from %.2f to %.2f degrees\n", ang_min_deg, ang_max_deg);
	printf("\t2. Distance from wall = %.2f meters\n", r_w);
	printf("\t3. Wall angle ranges from %.2f to %.2f degrees\n\n", th_w_st, th_w_end); 

	for(int i = 0; i <= max_iter; i++) {
		/* Calculate endpoints of wall in polar coordinates */
		float th_w = th_w_st + i*th_w_inc;

		ang_min_r = (r_w * (90.0 - th_w)) / (90 + th_w - fabsf(th_sw) / 2);
		ang_max_r = (r_w * (90.0 + th_w)) / (90 - th_w - fabsf(th_sw) / 2);

		/* Generate points */
		init_ranges();
		make_line_by_endpoints();

		/* Calculate expected slope and intercept */
		float th_0 = ranges[0].ang_rad - to_radian((ang_max_deg + ang_min_deg) / 2.0);
		float r_0 = ang_min_r;
		float th_f = ranges[num_ranges-1].ang_rad - to_radian((ang_max_deg + ang_min_deg) / 2.0);
		float r_f = ang_max_r;

		float slope_ref = calc_slope(r_0 * cos(th_0), r_f * cos(th_f),
					  	  r_0 * sin(th_0), r_f * sin(th_f));

		float intercept_ref = fabsf(calc_intercept(r_0 * cos(th_0), r_0 * sin(th_0), slope_ref));
	
		/* Run Al Gore's rhythm */
		equation_parameters res = determine_wall_slope(ang_min_deg, ang_max_deg, 500);

		/* Output results*/
		printf("\tResults for wall angle = %.2f degrees\n", th_w);
		printf("\t\tExpected slope, intercept = \t%.4f, %.4f\n", slope_ref, intercept_ref);
		printf("\t\tEndpoints (r, th_deg): {(%.4f, %.2f), (%.4f, %.2f)}\n", ang_min_r, ang_min_deg, ang_max_r, ang_max_deg);
		printf("\t\tAlgorithm slope, intercept = \t%.4f, %.4f\n\n", res.m, res.b);
	}

}

int main(int argc, char **argv)
{
	printf("\n");
	srand(time(NULL));
	
	clock_t t;


	/*for(int i = 0; i < 10; i++) {	
		t = clock();
		equation_parameters results = calculate_linear_regression(ang_min_deg, ang_max_deg, 1000);
		t = clock() - t;
		printf("RANSAC Results: \n");
		printf("\tSlope: %f\n", results.m);
		printf("\tIntercept: %f\n", results.b);
		printf("\tCycle time: %f\n", ((float) t)/CLOCKS_PER_SEC);
		printf("\n");
	}*/

	test_algorithm_with_walls();

	printf("\n");
  exit(0);
}

/* Iteration times:
 * 10000 cycles: 160 ms 
 * 1000 cycles: 16 ms 
 */
