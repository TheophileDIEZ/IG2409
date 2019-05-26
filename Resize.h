#ifndef PROJECT_RESIZE_H
#define PROJECT_RESIZE_H

/*********************************************************
  Function: Resize
		Called source code to resize an image
	Input parameters:
		Mat img - Contains the image to resize. By value.
	Output parameters:
		void
**********************************************************/
void Resize(cv::Mat img);

/***************************************************************
  Function: resizing
		This function is called when there are a trackbar event
	Input parameters:
		int, void* - Presets the parameters to zero.
	Output parameters:
		void
***************************************************************/
void resizing(int, void*);

#endif
