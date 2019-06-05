#include <opencv2/opencv.hpp>
#include "LightDark.h"

using namespace cv;
using std::cin;
using std::cout;
using std::endl;

//Global variables 
Mat srcLD;
Mat dstRebright;
int alpha = 100;		/*< Simple brightness control */
int beta = 0;       /*< Simple white balance control */
Mat trackLD(1, 290, CV_8U, Scalar::all(255));

//pre call
//void changebright(Mat* image);

Mat changebright(Mat image)
{
	srcLD = image;
	dstRebright = Mat::zeros(image.size(), image.type());

	// Create a window for the trackbar
	namedWindow("Trackbar", WINDOW_AUTOSIZE);

	createTrackbar("brightness, alpha", "Trackbar", &alpha, 300, rebright);
	createTrackbar("white balance, beta","Trackbar", &beta, 100, rebright);

	// Create a window
	namedWindow("Source", WINDOW_AUTOSIZE);

	//show the image
	imshow("Source", srcLD);

	rebright(0, 0);
	return dstRebright;
}

void rebright(int, void*) 
{        						
	for (int y = 0; y < srcLD.rows; y++) 
	{
		for (int x = 0; x < srcLD.cols; x++) 
		{
			for (int c = 0; c < srcLD.channels(); c++) 
			{
				dstRebright.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((alpha/100)*srcLD.at<Vec3b>(y, x)[c] + beta);
			}
		}
	}

	// Create a window
	namedWindow("Final", WINDOW_AUTOSIZE);

	//show the trackbar
	imshow("Trackbar", trackLD);

	//show the image
	imshow("Final", dstRebright);
}
