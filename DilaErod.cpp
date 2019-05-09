//
// Created by nathan on 18/04/19.
//

#include "DilaErod.h"


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
cv::Mat src;
cv::Mat dst;
int shape=0;
int ero=0;
int dil=0;
int const max_shape = 2;
int const max_kernel_size = 10;
int const shapes [] = {MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE};
String windowName;

Mat DilaErod::Erosion(Mat img) {
    dst.release();
    windowName = "Erosion";
    src=img;

    namedWindow( windowName, WINDOW_AUTOSIZE );
    createTrackbar("Shape (Rectangle/Cross/Ellipse)", windowName,&shape,max_shape);

    createTrackbar("Erosion", windowName,&ero,max_kernel_size,Ero);

    Ero(0,0);

    waitKey(0);
    destroyWindow(windowName);
    shape=0;
    ero=0;
    return dst;

}
Mat DilaErod::Dilatation(Mat img) {
    dst.release();
    windowName = "Dilatation";
    src=img;

    namedWindow( windowName, WINDOW_AUTOSIZE );
    createTrackbar("Shape (Rectangle/Cross/Ellipse)", windowName,&shape,max_shape);
    createTrackbar("Dilatation", windowName,&dil,max_kernel_size,Dil);
    Dil(0,0);

    waitKey(0);
    destroyWindow(windowName);
    shape=0;
    dil=0;
    return dst;

}



void DilaErod::Dil(int, void*) {
    Mat element = getStructuringElement(shapes[shape],Size(2* dil +1,2* dil +1),Point(dil,dil));
    dilate(src,dst,element);

    imshow(windowName,dst);
}
void DilaErod::Ero(int, void*) {
    Mat element = getStructuringElement(shapes[shape],Size(2* ero +1,2* ero +1),Point(ero,ero));
    erode(src,dst,element);
    imshow(windowName,dst);
}