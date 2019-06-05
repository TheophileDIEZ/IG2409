#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Resize.h"
#include "Resize.cpp"
#include "Canny.h"
#include "Canny.cpp"
#include "Crop.cpp"
#include "Crop.h"
#include "ColorMap.cpp"
#include "ColorMap.h"
#include "DilaErod.h"
#include "StitcherMultimedia.cpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//Variables
	int option = 0;
	int exit = 0;
	Mat src = imread("sample.jpg", IMREAD_COLOR);
	Mat dst;

	do 
	{
		cout << "\n Press the number of the option that you want to implement" << endl;
		cout << "  1 - Dilatation / Erosion" << endl;
		cout << "  2 - Resizing" << endl;
		cout << "  3 - Ligthen / Darken" << endl;
		cout << "  4 - Panorama / Stitching" << endl;
		cout << "  5 - Canny edge detection" << endl;
		cout << "  6 - Crop" << endl;
		cout << "  7 - Color Map" << endl;
		cout << "  8 - EXIT" << endl;
		
		cin >> option;

		switch (option)
		{
			case 1:
				cout << " You have choosen the option number 1: Dilatation / Erosion" << endl;
				DilaErod::Erosion(src);
                		DilaErod::Dilatation(src);
				break;

			case 2:
				cout << " You have choosen the option number 2: Resizing" << endl;
				
				//Call resize function
				Resize(src);

				// Wait for any keystroke in the window
				waitKey(0);
				
				//destroy all opened windows
				destroyAllWindows();
				break;

			case 3:
				cout << " You have choosen the option number 3: Ligthen / Darken" << endl;
				
				//Call Lighten Darken function
				changebright(src);

				// Wait for any keystroke in the window
				waitKey(0);

				//destroy all opened windows
				destroyAllWindows();
				break;

			case 4:
				cout << " You have choosen the option number 4: Panorama / Stitching" << endl;
				stitcher(argc, argv);
				break;

			case 5:
				cout << " You have choosen the option number 5: Canny edge detection" << endl;

				//Call canny function
				Canny(src);
				// Wait for any keystroke in the window
				waitKey(0);

				//destroy all opened windows
				destroyAllWindows();
				break;

			case 6:
				cout << " You have choosen the option number 6: Crop" << endl;

				//Call crop function
				Crop(src);

				// Wait for any keystroke in the window
				waitKey(0);

				//destroy all opened windows
				destroyAllWindows();
				break;
				
			case 7:
				cout << " You have choosen the option number 7: ColorMap" << endl;

				//Call crop function
				ColorMap(src);

				// Wait for any keystroke in the window
				waitKey(0);

				//destroy all opened windows
				destroyAllWindows();
				break;

			case 8:
				cout << " You have choosen the option number 8: Exit and close the program " << endl;
				exit = 1;
				break;

			default:
				cout << "ERROR-There aren't any function with this number" << endl;
				break;
		}
	} while (exit == 0);

	return 0;
}
