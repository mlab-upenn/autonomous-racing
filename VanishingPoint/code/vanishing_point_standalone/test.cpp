#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>  
#include <string>


 using namespace cv;
 using namespace std;

 int width = 640;
 int height = 480;

 int main( int argc, char** argv ) 
 {

 	Mat image = imread("images/image_66_og.png");


 	float r = height/2.0, t = CV_PI/2;
    double cos_t = cos(t), sin_t = sin(t);
    double x0 = r*cos_t, y0 = r*sin_t;
    double alpha = 1000;

    Point pt1( cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t) );
    Point pt2( cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t) );
    line( image, pt1, pt2, Scalar(255,0,0), 1, CV_AA);

    imshow("image", image);
    waitKey(0);

    return 0;
 }