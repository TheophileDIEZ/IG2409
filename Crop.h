#ifndef PROJECT_CROP_H
#define PROJECT_CROP_H

/*********************************************************
  Function: Crop
		Called source code to crop an image
	Input parameters:
		Mat img - Contains the image to crop. By value.
	Output parameters:
		void
**********************************************************/
cv::Mat Crop(cv::Mat img);


/*********************************************************
  Function: my_mouse_callback
		This function is called when a mouse event occurs
	Input parameters:
		int event - Type of mouse event. By value.
        int x - X coordinate of mouse event. By value.
        int y - Y coordinate of mouse event. By value.
        int flags - Specific condition whenever a mouse 
            event ocurrs. By value
        void* param - Any pointer passes to the "setMouseCallback" 
            function as the 3rd parameter. By reference
	Output parameters:
		void
**********************************************************/
void my_mouse_callback(int event, int x, int y, int flags, void* param);

#endif