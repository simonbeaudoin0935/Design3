#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <QString>
#include <QPixmap>

enum TABLE{
    TABLE_1,
    TABLE_2,
    TABLE_3,
    TABLE_4,
    TABLE_5,
    TABLE_6
};


class Camera : public QObject
{

    Q_OBJECT

public:
    Camera(TABLE p_table = TABLE_6);
    virtual ~Camera();

    bool isCameraConnected() const;
    bool connectCamera(const QString& p_cameraName);
    bool disconnectCamera();
    void setTable(TABLE p_table);
    bool operator>>(cv::Mat& p_matrix);
    bool operator>>(QPixmap& p_pixmap);
    static QPixmap Mat2QPixmap(cv::Mat const& p_mat);
    static QImage Mat2QImage(const cv::Mat& p_mat);

signals:

    void cameraDisconnected();

private:
    bool m_cameraConnected;
    bool m_useUndistortion;
    cv::VideoCapture* m_videoCapture;
    cv::Mat* m_cameraMatrix;
    cv::Mat* m_distortionCoefficient;
};

#endif // CAMERA_H
