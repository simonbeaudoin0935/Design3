#include "opencvworkerthread.h"

#include <opencv2/opencv.hpp>

OpencvWorkerThread::OpencvWorkerThread()
{
    cv::Mat inputImage = cv::imread(“/home/simon/Pictures/images.jpeg”);
    if(!inputImage.empty()) cv::imshow("Display Image", inputImage);
}

void OpencvWorkerThread::run()
{

}

