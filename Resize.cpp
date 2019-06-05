#include <opencv2/opencv.hpp>
#include "Resize.h"

using namespace cv;
using namespace std;

// Global variables
Mat srcResize, dstResize;
int fx = 100, fy = 100, factor = 30;
Mat track(1, 290, CV_8U, Scalar::all(255));

Mat Resize(Mat img)
{
	// Load an image
	srcResize= img;

	// Create a window
	namedWindow("Trackbar", WINDOW_AUTOSIZE);

	// Create a Trackbar for user to enter threshold
	createTrackbar("Resizing X Threshold:", "Trackbar", &factor, 100, resizing);

	// Two trackbars
	//createTrackbar("Resizing X Threshold:", "Trackbar", &fx, 200, resizing);
	//createTrackbar("Resizing Y Threshold:", "Trackbar", &fy, 200, resizing);

	//Show the image modified with trackbar
	resizing(0, 0);
	return dstResize;
}

void resizing(int, void*)
{
	//Function resize
	resize(srcResize, dstResize, Size(((srcResize.cols)/30)*factor+20, ((srcResize.rows)/30)*factor+20), factor, factor, INTER_NEAREST);
		
	// For two trackbars
	//resize(srcResize, dstResize, Size(fx+200,fy+200), fx, fy, INTER_NEAREST);

	// Create a window
	namedWindow("Resizing dst", WINDOW_AUTOSIZE);

	//Show the images
	imshow("Trackbar", track);
	imshow("Resizing dst", dstResize);
}
