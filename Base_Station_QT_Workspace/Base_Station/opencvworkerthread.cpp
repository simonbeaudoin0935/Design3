#include "opencvworkerthread.h"

#include <opencv2/opencv.hpp>
#include <QDebug>

OpencvWorkerThread::OpencvWorkerThread()
{

}

void OpencvWorkerThread::run()
{

    cv::Mat inputImage = cv::imread("/home/simon/Pictures/images.jpeg");
   // if(!inputImage.empty()) cv::imshow("Display Image", inputImage);
}

