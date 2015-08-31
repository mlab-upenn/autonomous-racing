#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "std_msgs/Int16.h"
#include "std_msgs/Float32.h"
#include <iostream>
#include <stdio.h>  
#include <string>

#define LP_WINDOW 10
#define DISPLAY_IMG 0

static const std::string OPENCV_WINDOW = "Vanishing point";
// topic where the error is being published
static const std::string VP_TOPIC = "vanishing_point_topic";
// topic where the image is being published
static const std::string VP_IMG_TOPIC = "/vp/output_video";


using namespace cv;
using namespace std;

class VanishingPoint
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;
  ros::Publisher vp_pub_; 
  std_msgs::Int16 error_;
  cv_bridge::CvImagePtr cv_ptr_;
  cv_bridge::CvImage out_msg_;

  // vanishing point algo parameters
  Mat frame, edges;
  Mat standard_hough;
  int min_threshold;
  int max_trackbar;
  // canny 
  int lowThreshold;
  int ratio;
  int kernel_size;
  // hough
  int s_trackbar;
  // image dimensions
  int width;
  int height;
  // ransac parameters
  int N_iterations; // # of iterations for ransac
  int threshold_ransac; // distance within which the hypothesis is classified as an inlier
  // low pass parameters
  //int window [LP_WINDOW][2];
  int **window;
  //int *window;
  int lp_pointer;
  // int running_sum [2];
  int *running_sum;

public:

  VanishingPoint(): it_(nh_)
  {
    // create a publisher object with topic: vanishing point
    vp_pub_ = nh_.advertise<std_msgs::Float32>(VP_TOPIC, 1000);
    // Subscribe to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/camera/image_raw", 1, &VanishingPoint::imageCB, this);
    image_pub_ = it_.advertise(VP_IMG_TOPIC, 1);

    // init vp parameters
    min_threshold = 50;
    max_trackbar = 150;
    // canny 
    lowThreshold = 60;
    ratio = 3;
    kernel_size = 3;
    // hough
    s_trackbar = 50;
    // image dimensions
    width = 640;
    height = 480;
    // ransac parameters
    N_iterations = 100; // # of iterations for ransac
    threshold_ransac = 10; // distance within which the hypothesis is classified as an inlier
    // low pass parameters
    lp_pointer = 0;
    // window [LP_WINDOW][2] = {};
    // running_sum [2] = {};
    //window = new int[LP_WINDOW][2]();
    
    window = new int*[LP_WINDOW];
    for (int i = 0; i < LP_WINDOW; i++) { 
      window[i] = new int[2](); 
    }
    //window = new int[LP_WINDOW*2]();

    running_sum = new int[2]();

    //cv::namedWindow(OPENCV_WINDOW);
  } 

  ~VanishingPoint()
  {
    //cv::destroyWindow(OPENCV_WINDOW);
    // delete arrays to avoid memory leaks
    for (int i = 0; i<2; i++) {
      delete [] window[i];
    }
    delete [] window;
    delete [] running_sum;
  }

  void imageCB(const sensor_msgs::ImageConstPtr& msg)
  {
    // convert ROS raw image to CV::mat (mono8) mono16 required?
    
    try
    {
      cv_ptr_ = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    // // Draw an example circle on the video stream
    // if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
    //   cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));
    frame = cv_ptr_->image;
    vp_detection();

    // Update GUI Window
    // cv::imshow(OPENCV_WINDOW, frame);
    cv::waitKey(30);

    // // compute vanishing point and error
    // error_.data = 10;
    // ROS_INFO("%d", error_.data);

    // // publish the error
    // vp_pub_.publish(error_);

  }

private:
  void vp_detection();
  bool findIntersectingPoint(float, float, float, float, Point&);
  int findInliers(const vector<Vec2f>&, const Point&);
  int* lowPass (int, int); 
};


/* -------------------------------------- vp detection --------------------------------------------*/
void VanishingPoint::vp_detection() 
{
  vector<Vec2f> s_lines;

  // 1(a) Reduce noise with a kernel 3x3
  blur( frame, edges, Size(3,3) );

  // 1(b) Apply Canny edge detector
  Canny( edges, edges, lowThreshold, lowThreshold*ratio, kernel_size);

  cvtColor( edges, standard_hough, CV_GRAY2BGR );

  // 2. Use Standard Hough Transform
  HoughLines(edges, s_lines, 1, CV_PI/180, min_threshold + s_trackbar, 0, 0 );


  //preprocessing: remove vertical lines within +-3 degrees
  for (int i = static_cast<int> (s_lines.size()) - 1; i>=0; i--) 
  {
    int t_deg = s_lines[i][1] * 180/CV_PI;
    // it looks like theta ranges from 0 to 180 degrees
    if (t_deg < 5 || t_deg > 175)  s_lines.erase(s_lines.begin() + i);
  }

  ////////////////////////////////////////////////////
  /// Show the result
  //print//printf("number of lines: %zu\n",s_lines.size());
  // for( size_t i = 0; i < s_lines.size(); i++ )
  // {
  //   float r = s_lines[i][0], t = s_lines[i][1];
  //   double cos_t = cos(t), sin_t = sin(t);
  //   double x0 = r*cos_t, y0 = r*sin_t;
  //   double alpha = 1000;

  //   Point pt1( cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t) );
  //   Point pt2( cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t) );
  //   line( standard_hough, pt1, pt2, Scalar(255,0,0), 1, CV_AA);
  // }
  ////////////////////////////////////////////////////

  // 3. RANSAC if > 2 lines available
  if (static_cast<int>(s_lines.size()) > 1) 
  {
    // ransac
    // input: s_lines | 
    //Mat tempImg;
    //cout << "Size of image: " << standard_hough.rows << ", "<< standard_hough.cols << endl;
    int maxInliers = 0;
    Point vp, vp_lp;
    for (int i = 0; i<N_iterations; i++) 
    {
      //tempImg = standard_hough.clone();;
      // 1. randomly select 2 lines
      int a = rand() % static_cast<int>(s_lines.size());
      int b = rand() % static_cast<int>(s_lines.size());

      // 2. find intersecting point (x_v, y_v)
      Point intersectingPt;
      float r_1 = s_lines[a][0], t_1 = s_lines[a][1];
      float r_2 = s_lines[b][0], t_2 = s_lines[b][1];
      bool found= findIntersectingPoint(r_1, t_1, r_2, t_2, intersectingPt);

      // skip if not found
      if (!found) continue;
      
    // else 
    // {
    //   //print//cout << "Point: " << intersectingPt.x << ", " << intersectingPt.y << endl;
    // }

    // // // draw for debugging purposes
    // double alpha = 1000;
    // double cos_t = cos(t_1), sin_t = sin(t_1);
    // Point pt1( cvRound(r_1*cos_t + alpha*(-sin_t)), cvRound(r_1*sin_t + alpha*cos_t) );
    // Point pt2( cvRound(r_1*cos_t - alpha*(-sin_t)), cvRound(r_1*sin_t - alpha*cos_t) );
    // line(tempImg, pt1, pt2, Scalar(255,255,0), 2, CV_AA);

    // cos_t = cos(t_2); sin_t = sin(t_2);
    // Point pt11( cvRound(r_2*cos_t + alpha*(-sin_t)), cvRound(r_2*sin_t + alpha*cos_t) );
    // Point pt22( cvRound(r_2*cos_t - alpha*(-sin_t)), cvRound(r_2*sin_t - alpha*cos_t) );
    // line(tempImg, pt11, pt22, Scalar(255,255,0), 2, CV_AA);

    // circle(tempImg, intersectingPt, 2,  Scalar(0,0,255), 2, 8, 0 );
    // imshow("temp", tempImg);
    // waitKey(0);

      // 3. find error for each line (shortest distance b/w point above and line: perpendicular bisector)
      // 4. find # inliers (error < threshold)
      //int inliers = findInliers(s_lines, intersectingPt, tempImg);
      int inliers = findInliers(s_lines, intersectingPt);
      //print//cout << "Num of inliers: " << inliers << endl;

      // 5. if # inliers > maxInliers, save model
      if (inliers > maxInliers) 
      {
        maxInliers = inliers;
        vp.x = intersectingPt.x; 
        vp.y = intersectingPt.y;
      }

    } // end of ransac iterations
    
    // limit vanishing point to be within image bounds
    if (vp.x > width) vp.x = width;
    if (vp.x < 0) vp.x = 0;
    if (vp.y > height) vp.y = height;
    if (vp.y < 0) vp.y = 0;

    // apply low pass filter over frames
    int *avg = lowPass (vp.x, vp.y);
    vp_lp.x = *(avg);
    vp_lp.y = *(avg + 1);
    free(avg); // free avg to avoid memory leaks

    // compute error signal 
    float error = (vp_lp.x - cvRound(width/2.0)) / width;
    // cout << "Vanishing point = " << vp.x << "," << vp.y << "| Inliers: " << maxInliers << "| error: "<< error << endl;
    // cout << "VP_LP_x: " << vp_lp.x << " | " << "center: " << cvRound(width/2.0) << endl;
    error_.data = error;
    ROS_INFO("Error: %.4f | VP_LP_x: %d | center_x: %d ", error_.data, vp_lp.x, (width/2.0));

    // publish the error to topic defined before (vanishing_point_topic)
    vp_pub_.publish(error_);

    // plot vanishing point on images
    // circle(standard_hough, vp, 2,  Scalar(0,0,255), 2, 8, 0 );
    // circle(frame, vp, 3,  Scalar(0,0,255), 2, 8, 0 );
    // circle(standard_hough, vp_lp, 2,  Scalar(0,255,0), 2, 8, 0 );
    // circle(frame, vp_lp, 3,  Scalar(0,255,0), 2, 8, 0 );

  } // end of ransac (if > 2 lines available)

  // draw cross hair
  // Point pt1_v( cvRound(width/2.0), 0);
  // Point pt2_v( cvRound(width/2.0), height);
  // line( standard_hough, pt1_v, pt2_v, Scalar(0,255,255), 1, CV_AA);
  // Point pt1_h( 0, cvRound(height/2.0));
  // Point pt2_h( width, cvRound(height/2.0));
  // line( standard_hough, pt1_h, pt2_h, Scalar(0,255,255), 1, CV_AA);

  // display edge+hough+vp for degbugging
  if (DISPLAY_IMG)
  {
    imshow( "houghlines", standard_hough );
    imshow("Original", frame);
  }
  
  // Debugging: Output modified video stream
  //out_msg_->header = cv_ptr_->header;
  //out_msg_->encoding = sensor_msgs::image_encodings::BGR8;
  //out_msg_->image = standard_hough;

  //out_msg_.header = cv_ptr_->header;
  //out_msg_.encoding = sensor_msgs::image_encodings::BGR8;
  //out_msg_.image = standard_hough;

  //image_pub_.publish(out_msg_.toImageMsg());
}

/* -------------------------------------- findIntersectingPt --------------------------------------------*/
// find intersecting point between two lines using crammer's rule. 
// if no intersecting point (parallel lines/same line) return false
// i/p: lines: [rho_1;theta_1] & [rho_2;theta_2] and intersectingPt
bool VanishingPoint::findIntersectingPoint(float r_1, float t_1, float r_2, float t_2, Point& intersectingPt) 
{
  double determinant = (cos(t_1) * sin(t_2)) - (cos(t_2) * sin(t_1));
  if (determinant != 0) {
    intersectingPt.x = (int) (sin(t_2)*r_1 - sin(t_1)*r_2) / determinant;
    intersectingPt.y = (int) (cos(t_1)*r_2 - cos(t_2)*r_1) / determinant;
    return true;
  }
  // else no point found (parallel lines/same line) 
  return false;
}

/* ------------------------------------------findInliers --------------------------------------------*/

int VanishingPoint::findInliers(const vector<Vec2f>& s_lines, const Point& intersectingPt) 
{
  int inliers = 0;
  //print//cout << "Distance: ";
  for (int i = 0; i < static_cast<int>(s_lines.size()); i++) {
    //Mat tmp = tempImg.clone();
    // find error: shortest distance between intersectingPt and line
    float r = s_lines[i][0], t = s_lines[i][1];
    double a = cos(t), b = sin(t);
    int x = intersectingPt.x, y = intersectingPt.y;
    double d = abs(a*x + b*y - r) / sqrt(pow(a,2) + pow(b,2));

    // // debugging
    // double alpha = 1000;
    // double cos_t = cos(t), sin_t = sin(t);
    // double x0 = r*cos_t, y0 = r*sin_t;
    // Point pt1( cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t) );
    // Point pt2( cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t) );
    // line( tmp, pt1, pt2, Scalar(0,255,255), 2, CV_AA);

    // imshow("temp_", tmp);
    // waitKey(0);

    // find inliers
    if (d < threshold_ransac) { inliers++; }
  }
  //print//cout << endl;
  return inliers;
}

/* -----------------------------------------LPF --------------------------------------------*/

 // // low pass parameters
 // const int LP_WINDOW = 20;
 // int window [LP_WINDOW][2] = {};
 // int lp_pointer = 0;
 // int sum [2] = {};
int* VanishingPoint::lowPass (int vp_x, int vp_y) 
{
  // remove element from running sum
  running_sum[0] -= window[lp_pointer][0];
  running_sum[1] -= window[lp_pointer][1];

  // update window with new vanishing point
  window[lp_pointer][0] = vp_x;
  window[lp_pointer][1] = vp_y;

  // update sum
  running_sum[0] += window[lp_pointer][0];
  running_sum[1] += window[lp_pointer][1];

  // update running avg
  int *avg = (int *) malloc(sizeof (int) * 2);
  avg[0] = (int) (float)running_sum[0]/LP_WINDOW;
  avg[1] = (int) (float)running_sum[1]/LP_WINDOW;

  // increment lp_pointer and keep within bounds
  lp_pointer++;
  if (lp_pointer >= LP_WINDOW) lp_pointer = 0;

  return avg;
}



/* -------------------------------------- main --------------------------------------------*/

int main(int argc, char** argv)
{
  // initialize ros node for publishing vanishing point error
  ros::init(argc, argv, "vanishing_point_publisher");

  VanishingPoint vp;
  ros::spin();
  return 0;

  // -------------------------------//
  // // initialize node handle
  // ros::NodeHandle nh;

  // // create a publisher object with topic: vanishing point
  // ros::Publisher vp_pub = n.advertise<std_msgs::Int8>("vanishing_point_topic", 1000);

  // // frequency of publishing: 10 Hz
  // ros::Rate loop_rate(10);

  // image_transport::ImageTransport it (nh);
  // image_transport::Subscriber image_sub;
  // std_msgs::Int8 error;

  // // Subscribe to input video feed and publish output video feed
  // image_sub = it.subscribe("/camera/image_raw", 1, imageCallBack);

  // while (ros::ok())
  // { 
  //   // compute vanishing point and error
  //   error.data = 10;
  //   ROS_INFO("%d", error.data);

  //   // publish the error
  //   vp_pub.publish(error);

  //   ros::spinOnce();
  //   loop_rate.sleep();
  // }

}
