#include <opencv2/opencv.hpp>
#include "Crop.h"

using namespace cv;
using namespace std;

//Global Variables
Mat srcCrop;
Rect roi; //Region Of Interest
bool drawing_box = false;

void Crop(Mat img)
{
	// Load an image
    srcCrop = img;
    
	// Create a window and show source image
	namedWindow("Crop src", WINDOW_AUTOSIZE);
	imshow("Crop src", srcCrop);
	
	// When a mouse event occurred, my_mouse_callback function is called 
	setMouseCallback("Crop src", my_mouse_callback, (void*)&srcCrop);
}


void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	switch (event)
	{
		case EVENT_MOUSEMOVE:
		
			if (drawing_box) 
			{
				roi.width = x - roi.x;
				roi.height = y - roi.y;
			}
		
			break;
		case EVENT_LBUTTONDOWN:
		
			drawing_box = true;
			roi = Rect(x, y, 0, 0);
		
			break;

		case EVENT_LBUTTONUP:
		
			drawing_box = false;
			if (roi.width < 0) 
			{
				roi.x += roi.width;
				roi.width *= -1;
			}

			if (roi.height < 0) 
			{
				roi.y += roi.height;
				roi.height *= -1;
			}

			//Create a new image with specific roi
			Mat dstCrop(srcCrop, roi);
			
			// Create a window and show result image
			namedWindow("Crop dst", WINDOW_AUTOSIZE);
			imshow("Crop dst", dstCrop);

			break;
	}
}
