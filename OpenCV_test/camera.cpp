#include "camera.h"

#include <QCameraInfo>
#include <QImage>

Camera::Camera():
    m_cameraConnected(false)
{

}

bool Camera::isCameraConnected() const
{
    return m_cameraConnected;
}

bool Camera::connectCamera(const QString &p_cameraName)
{
    QCameraInfo v_cameraInfo(p_cameraName.toUtf8());

    if(!v_cameraInfo.isNull())
    {

        m_videoCapture = new cv::VideoCapture();
        int v_cameraID = QString(p_cameraName.at(p_cameraName.size()-1)).toInt();
        m_videoCapture->open(v_cameraID);
        if(m_videoCapture->isOpened()){
           m_cameraConnected = true;

        }
        else{
           delete m_videoCapture;
           m_cameraConnected = false;
        }

    }

    else
    {
        m_cameraConnected = false;

    }

    return m_cameraConnected;

}

bool Camera::disconnectCamera()
{
    if(m_cameraConnected){
        m_videoCapture->release();
    }
    m_cameraConnected = false;

    return false;
}

Camera &Camera::operator>>(cv::Mat &p_matrix)
{
    if(m_cameraConnected){
        *m_videoCapture >> p_matrix;
    }
    return *this;
}

QPixmap Camera::Mat2QPixmap(const cv::Mat &mat)
{
    cv::Mat temp; // make the same cv::Mat
    cv::cvtColor(mat, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need


    return QPixmap::fromImage(QImage((unsigned char*) temp.data, temp.cols, temp.rows, QImage::Format_RGB888));
}





