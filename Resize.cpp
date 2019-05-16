#include <opencv2/opencv.hpp>
#include "Resize.h"

using namespace cv;
using namespace std;

// Global variables
Mat src, dstResize;
int fx = 100, fy = 100;
int k = 0;
Mat track(1, 290, CV_8U, Scalar::all(255));

void Resize(Mat img)
{
	// Load an image
	src = img;

	// Create a window
	namedWindow("Trackbar", WINDOW_AUTOSIZE);

	// Create a Trackbar for user to enter threshold
	createTrackbar("Resizing X Threshold:", "Trackbar", &fx, 200, resizing);
	createTrackbar("Resizing Y Threshold:", "Trackbar", &fy, 200, resizing);

	//Show the image modified with trackbar
	resizing(0, 0);
}

void resizing(int, void*)
{
	//Function resize
	resize(src, dstResize, Size(fx+200,fy+200), fx, fy, INTER_NEAREST);

	// Create a window
	namedWindow("Resizing dst", WINDOW_AUTOSIZE);

	//Show the images
	imshow("Trackbar", track);
	imshow("Resizing dst", dstResize);
}