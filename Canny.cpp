#include "pch.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "Canny.h"

using namespace cv;
using namespace std;

/// Global variables
Mat srcCanny, dstBlur, dstCanny;
int lowThreshold;

void Canny(Mat img)
{
	// Load an image
	srcCanny = img;

	/// Create a matrix of the same type and size as src (for dst)
	dstBlur.create(srcCanny.size(), srcCanny.type());

	// Create a window
	namedWindow("Edge Detection dst", WINDOW_AUTOSIZE);

	/// Create a Trackbar for user to enter threshold
	createTrackbar("Canny Threshold:", "Edge Detection dst", &lowThreshold, 100, edgeDetection);

	//Show the image modified with trackbar
	edgeDetection(0, 0);
}

void edgeDetection(int, void*)
{
	// Reduce noise with a kernel 3x3
	blur(srcCanny, dstBlur, Size(3, 3));

	// Function Canny detector
	Canny(dstBlur, dstCanny, lowThreshold, lowThreshold*3, 3, true);

	// Create a window
	namedWindow("Edge Detection src", WINDOW_AUTOSIZE);

	//Show the images
	imshow("Edge Detection src", srcCanny);
	imshow("Edge Detection dst", dstCanny);
}