#ifndef PROJECT_COLORMAP_H
#define PROJECT_COLORMAP_H

/*********************************************************
  Function: ColorMap
		Call source code to apply a specific color map
		to an image
	Input parameters:
		Mat img - Contains the image to apply the color 
		map. By value.
	Output parameters:
		void
**********************************************************/
void ColorMap(cv::Mat img);

/*********************************************************
  Function: showInfo
		Show on command line the different color map to choose
	Input parameters:
		void
	Output parameters:
		void
**********************************************************/
void showInfo();

#endif