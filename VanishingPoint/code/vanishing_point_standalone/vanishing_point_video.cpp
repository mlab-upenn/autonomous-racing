/**
 * @file vanishing_point_video.cpp
 * @brief Detecting vanishing point in a video stream
 * @author Dhruva Kumar
 THIS FILE NEEDS TO BE DOCUMENTED BETTER. 
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>  
#include <string>

// #include "FlyCapture2.h"

 using namespace cv;
 using namespace std;

/* ---------------------------------- Parameters ----------------------------------*/
 Mat frame, edges;
 Mat frame_gray;
 Mat standard_hough;
 int min_threshold = 50;
 int max_trackbar = 150;
 // canny 
 int lowThreshold = 60;
 int const max_lowThreshold = 100;
 int ratio = 3;
 int kernel_size = 3;
 // hough
 int s_trackbar = 50;
 const char* standard_name = "Standard Hough Lines Demo";
 // image dimensions
 int width = 640;
 int height = 480;

 // ransac parameters
 int N_iterations = 50; // # of iterations for ransac
 int threshold_ransac = 10; // distance within which the hypothesis is classified as an inlier

 // low pass parameters
 const int lowPass_window = 10;
 int window [lowPass_window][2] = {};
 int lp_pointer = 0;
 int running_sum [2] = {};

 // Function Headers
 void help();
 void Standard_Hough( int, void* );

/* -------------------------------------- main --------------------------------------------*/
 int main( int argc, char** argv )
 {
  // read the video
  string filename = "output2.avi";
  VideoCapture capture(filename);

  if( !capture.isOpened() )
    throw "Error when reading video";

    // capture loop
    char key = 0;
    while(key != 'q')
    {
        capture >> frame;
        if(frame.empty())
            break;

        // convert the frame to grayscale
        cvtColor( frame, frame_gray, COLOR_RGB2GRAY );

        // create trackbars(canny & hough) for thresholds
        char thresh_label[50];
        sprintf( thresh_label, "Hough thresh: %d + input", min_threshold );

        namedWindow( standard_name, WINDOW_AUTOSIZE );
        //createTrackbar( "Canny threshold", standard_name, &lowThreshold, max_lowThreshold, Standard_Hough);
        //createTrackbar( thresh_label, standard_name, &s_trackbar, max_trackbar, Standard_Hough);
        
        // initialize
        Standard_Hough(0, 0);

        key = cv::waitKey(30);        
    }

    return 0;
}

/* -------------------------------------- findIntersectingPt --------------------------------------------*/
// find intersecting point between two lines using crammer's rule. 
// if no intersecting point (parallel lines/same line) return false
// i/p: lines: [rho_1;theta_1] & [rho_2;theta_2] and intersectingPt
bool findIntersectingPoint(float r_1, float t_1, float r_2, float t_2, Point& intersectingPt) 
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

int findInliers(const vector<Vec2f>& s_lines, const Point& intersectingPt) 
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
 // const int lowPass_window = 20;
 // int window [lowPass_window][2] = {};
 // int lp_pointer = 0;
 // int sum [2] = {};
int* lowPass (int vp_x, int vp_y) 
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
  avg[0] = (int) (float)running_sum[0]/lowPass_window;
  avg[1] = (int) (float)running_sum[1]/lowPass_window;

  // increment lp_pointer and keep within bounds
  lp_pointer++;
  if (lp_pointer >= lowPass_window) lp_pointer = 0;

  return avg;
}

/* -------------------------------------- vp detection --------------------------------------------*/
 void Standard_Hough( int, void* )
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
  for( size_t i = 0; i < s_lines.size(); i++ )
  {
    float r = s_lines[i][0], t = s_lines[i][1];
    double cos_t = cos(t), sin_t = sin(t);
    double x0 = r*cos_t, y0 = r*sin_t;
    double alpha = 1000;

    Point pt1( cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t) );
    Point pt2( cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t) );
    line( standard_hough, pt1, pt2, Scalar(255,0,0), 1, CV_AA);
  }
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
    if (vp.y > height) vp.y = height;

    // apply low pass filter over frames
    int *avg = lowPass (vp.x, vp.y);
    vp_lp.x = *(avg);
    vp_lp.y = *(avg + 1);
    free(avg); // free avg to avoid memory leaks

    // compute error signal 
    int error = (vp_lp.x - cvRound(width/2.0));
    cout << "Vanishing point = " << vp.x << "," << vp.y << "| Inliers: " << maxInliers << "| error: "<< error << endl;

    // plot vanishing point on images
    circle(standard_hough, vp, 2,  Scalar(0,0,255), 2, 8, 0 );
    circle(frame, vp, 3,  Scalar(0,0,255), 2, 8, 0 );
    circle(standard_hough, vp_lp, 2,  Scalar(0,255,0), 2, 8, 0 );
    circle(frame, vp_lp, 3,  Scalar(0,255,0), 2, 8, 0 );

  } // end of ransac (if > 2 lines available)

  // draw cross hair
  Point pt1_v( cvRound(width/2.0), 0);
  Point pt2_v( cvRound(width/2.0), height);
  line( standard_hough, pt1_v, pt2_v, Scalar(0,255,255), 1, CV_AA);
  Point pt1_h( 0, cvRound(height/2.0));
  Point pt2_h( width, cvRound(height/2.0));
  line( standard_hough, pt1_h, pt2_h, Scalar(0,255,255), 1, CV_AA);

  imshow( standard_name, standard_hough );
  imshow("Original", frame);
}


