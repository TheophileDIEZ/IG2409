//
// Created by nathan on 18/04/19.
//

#include "DilaErod.h"


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
cv::Mat srcDilaErod;
cv::Mat dstDilaErod;
int shape=0;
int ero=0;
int dil=0;
int const max_shape = 2;
int const max_kernel_size = 10;
int const shapes [] = {MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE};
String windowName;

Mat DilaErod::Erosion(Mat img) {
    dstDilaErod.release();
    windowName = "Erosion";
    srcDilaErod=img;

    namedWindow( windowName, WINDOW_AUTOSIZE );
    createTrackbar("Shape (Rectangle/Cross/Ellipse)", windowName,&shape,max_shape);

    createTrackbar("Erosion", windowName,&ero,max_kernel_size,Ero);

    Ero(0,0);

    waitKey(0);
    destroyWindow(windowName);
    shape=0;
    ero=0;
    return dstDilaErod;

}
Mat DilaErod::Dilatation(Mat img) {
    dstDilaErod.release();
    windowName = "Dilatation";
    srcDilaErod=img;

    namedWindow( windowName, WINDOW_AUTOSIZE );
    createTrackbar("Shape (Rectangle/Cross/Ellipse)", windowName,&shape,max_shape);
    createTrackbar("Dilatation", windowName,&dil,max_kernel_size,Dil);
    Dil(0,0);

    waitKey(0);
    destroyWindow(windowName);
    shape=0;
    dil=0;
    return dstDilaErod;

}



void DilaErod::Dil(int, void*) {
    Mat element = getStructuringElement(shapes[shape],Size(2* dil +1,2* dil +1),Point(dil,dil));
    dilate(srcDilaErod,dstDilaErod,element);

    imshow(windowName,dstDilaErod);
}
void DilaErod::Ero(int, void*) {
    Mat element = getStructuringElement(shapes[shape],Size(2* ero +1,2* ero +1),Point(ero,ero));
    erode(srcDilaErod,dstDilaErod,element);
    imshow(windowName,dstDilaErod);
}
