//
// Created by nathan on 18/04/19.
//

#ifndef PROJECT_DILAEROD_H
#define PROJECT_DILAEROD_H


#include <opencv2/core/mat.hpp>


class DilaErod {

public:
    static cv::Mat Erosion(cv::Mat img);
    static cv::Mat Dilatation(cv::Mat img);

private:
    static void Dil(int, void*);
    static void Ero(int, void*);
};


#endif //PROJECT_DILAEROD_H
