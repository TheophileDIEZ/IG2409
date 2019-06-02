#include <opencv2/opencv.hpp>
#include "LightDark.h"

using namespace cv;
using std::cin;
using std::cout;
using std::endl;

//Global variables 
Mat src = imread("van_gogh.jpg");
Mat dstRebright;
int alphaint = 100; /*< Simple contrast control */
int beta = 0;       /*< Simple brightness control */
Mat track(1, 290, CV_8U, Scalar::all(255));

//pre call
void changebright(Mat* image);

void changebright(Mat* image) {
	//imshow("New Image", new_image);
	//int alpha = 100; /*< Simple contrast control */
	//int beta = 0;       /*< Simple brightness control */

	// Create a window
	namedWindow("Trackbar", WINDOW_AUTOSIZE);

	createTrackbar("brightness, alpha", "New Image", &alphaint, 300, rebright);
	createTrackbar("white balance, beta","New Image", &beta, 100, rebright);
	rebright(0, 0);
}


void rebright(int, void*) {
	double alpha = 1.0 * alphaint / 100;
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			for (int c = 0; c < src.channels(); c++) {
				dstRebright.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha*src.at<Vec3b>(y, x)[c] + beta);
			}
		}
	}

	// Create a window
	namedWindow("Rebright", WINDOW_AUTOSIZE);

	//show the image
	imshow("Trackbar", track);
	imshow("New Image", dstRebright);

}
