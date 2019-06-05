#include <opencv2/opencv.hpp>
#include "ColorMap.h"

using namespace cv;

//void showInfo();

//Global Variables
Mat srcColorMap, dstColorMap;
int option;

Mat ColorMap(Mat img)
{
	// Load an image
    srcColorMap = img;
	Mat info = imread("colorMap.jpg", IMREAD_COLOR);
	int info_flag = 0;

	showInfo();
	
	switch (option)
    {
		case 0:
			// Create a window
			namedWindow("Information Color Map", WINDOW_AUTOSIZE);
			info_flag = 1;
			
			break;
        case 1: //COLORMAP_AUTUMN
            // Apply the colormap
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_AUTUMN);
            break;
        case 2: //COLORMAP_BONE
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_BONE);
            break;
        case 3: //COLORMAP_COOL
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_COOL);
            break;
        case 4: //COLORMAP_HOT
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_HOT);
            break;
        case 5: //COLORMAP_HSV
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_HSV);
            break;
        case 6: //COLORMAP_JET
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_JET);
            break;
        case 7: //COLORMAP_OCEAN
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_OCEAN);
            break;
        case 8: //COLORMAP_PINK
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_PINK);
            break;
        case 9: //COLORMAP_RAINBOW
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_RAINBOW);
            break;
        case 10: //COLORMAP_SPRING
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_SPRING);
            break;
        case 11: //COLORMAP_SUMMER
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_SUMMER);
            break;
        case 12: //COLORMAP_WINTER
            applyColorMap(srcColorMap, dstColorMap, COLORMAP_WINTER);
            break;
        default:
			cout << "       This color map does not exist" << endl;
			break;
    }

	if (info_flag)
	{
		//Show the images
		imshow("Information Color Map", info);
	}
	else {
		// Create a window and show source image
		namedWindow("Color Map src", WINDOW_AUTOSIZE);
		imshow("Color Map src", srcColorMap);

		// Create a window and show destination image
		namedWindow("Color Map dst", WINDOW_AUTOSIZE);
		imshow("Color Map dst", dstColorMap);
	}
	return dstColorMap;

}

void showInfo()
{
	cout << "       Choose a color map to apply" << endl;
	cout << "		0 - INFORMATION COLOR MAPS" << endl;
	cout << "			 1 - COLORMAP_AUTUMN" << endl;
	cout << "			 2 - COLORMAP_BONE" << endl;
	cout << "			 3 - COLORMAP_COOL" << endl;
	cout << "			 4 - COLORMAP_HOT" << endl;
	cout << "			 5 - COLORMAP_HSV" << endl;
	cout << "			 6 - COLORMAP_JET" << endl;
	cout << "			 7 - COLORMAP_OCEAN" << endl;
	cout << "			 8 - COLORMAP_PINK" << endl;
	cout << "			 9 - COLORMAP_RAINBOW" << endl;
	cout << "			10 - COLORMAP_SPRING" << endl;
	cout << "			11 - COLORMAP_SUMMER" << endl;
	cout << "			12 - COLORMAP_WINTER" << endl;
	cout << "       Choice: ";

	cin >> option;
}