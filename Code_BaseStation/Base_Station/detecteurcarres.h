#ifndef DETECTEURCARRES_H
#define DETECTEURCARRES_H

#include <QVector>
#include <QPoint>

#include <opencv2/opencv.hpp>

class DetecteurCarres
{
public:
    DetecteurCarres();

    bool detecterCarres(cv::Mat& p_matSource,
                        int p_nombreCarresMinimum,
                        int p_nombreCarresMaximum,
                        int p_airMinimum,
                        int p_airMaximum,
                        std::vector< std::vector< cv::Point>>& p_vecteurDeCarres);

   void drawSquare( cv::Mat& image, const std::vector< std::vector< cv::Point> >& squares );

private:
    double angle( cv::Point pt1, cv::Point pt2, cv::Point pt0 );

private:
    int thresh;
    int N;
};

#endif // DETECTEURCARRES_H
