#ifndef PROJECT_LIGHTDARK_H
#define PROJECT_LIGHTDARK_H

/*********************************************************
  Function: rebright
		Called source code to change brightness of an image
	Input parameters:
		Mat img - Contains the image to rebright. By value.
	Output parameters:
		void
**********************************************************/
cv::Mat changebright(cv::Mat img);

/***************************************************************
  Function: changebright
		This function is called when there are a trackbar event
	Input parameters:
		int, void* - Presets the parameters to zero.
	Output parameters:
		void
***************************************************************/
void rebright(int, void*);

#endif
