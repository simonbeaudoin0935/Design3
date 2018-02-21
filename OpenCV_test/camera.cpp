#include "camera.h"

#include <QCameraInfo>
#include <QImage>



double c[9] = {5.7254083771647004e+02, 0., 320., 0., 5.7254083771647004e+02, 240., 0., 0., 1.};

double d[5] = {-1.7362703587024278e-01, 8.2552030882771299e-01,
               -4.3008418461358436e-04, -7.5739445839932886e-03,
               -1.0206943494686624e+00};

Camera::Camera():
    m_cameraConnected(false)
{
    m_cameraMatrix = new cv::Mat(3,3,CV_64F,c);


    m_distortionCoefficient = new cv::Mat(1,5,CV_64F,d);

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
        cv::Mat distorted;
        *m_videoCapture >> distorted;
        undistort(distorted, p_matrix, *m_cameraMatrix, *m_distortionCoefficient);
        //*m_videoCapture >> p_matrix;
    }
    return *this;
}

QPixmap Camera::Mat2QPixmap(const cv::Mat &mat)
{
    cv::Mat temp; // make the same cv::Mat
    cv::cvtColor(mat, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need


    return QPixmap::fromImage(QImage((unsigned char*) temp.data, temp.cols, temp.rows, QImage::Format_RGB888));
}





