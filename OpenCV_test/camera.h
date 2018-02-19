#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <QString>
#include <QPixmap>

class Camera
{
public:
    Camera();
    bool isCameraConnected() const;
    bool connectCamera(const QString& p_cameraName);
    bool disconnectCamera();
    Camera& operator>>(cv::Mat& p_matrix);
    static QPixmap Mat2QPixmap(cv::Mat const& mat);


private:
    bool m_cameraConnected;
    cv::VideoCapture* m_videoCapture;
};

#endif // CAMERA_H
