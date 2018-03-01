#include "camera.h"

#include "define.h"

#include <QCameraInfo>
#include <QImage>

double table_1_camera_matrix[9] = TABLE_1_CAMERA_MATRIX;
double table_1_distortion_matrix[5] = TABLE_1_DISTORTION_MATRIX;

double table_2_camera_matrix[9] = TABLE_2_CAMERA_MATRIX;
double table_2_distortion_matrix[5] = TABLE_2_DISTORTION_MATRIX;

double table_3_camera_matrix[9] = TABLE_3_CAMERA_MATRIX;
double table_3_distortion_matrix[5] = TABLE_3_DISTORTION_MATRIX;

double table_4_camera_matrix[9] = TABLE_4_CAMERA_MATRIX;
double table_4_distortion_matrix[5] = TABLE_4_DISTORTION_MATRIX;

double table_5_camera_matrix[9] = TABLE_5_CAMERA_MATRIX;
double table_5_distortion_matrix[5] = TABLE_5_DISTORTION_MATRIX;

double table_6_camera_matrix[9] = TABLE_6_CAMERA_MATRIX;
double table_6_distortion_matrix[5] = TABLE_6_DISTORTION_MATRIX;

Camera::Camera(TABLE p_table):
    m_cameraConnected(false),
    m_useUndistortion(false)
{

    switch(p_table)
    {
    case TABLE_1:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_1_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_1_distortion_matrix);
        break;
    case TABLE_2:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_2_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_2_distortion_matrix);
        break;
    case TABLE_3:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_3_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_3_distortion_matrix);
        break;
    case TABLE_4:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_4_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_4_distortion_matrix);
        break;
    case TABLE_5:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_5_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_5_distortion_matrix);
        break;
    case TABLE_6:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_6_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_6_distortion_matrix);
        break;
    default:
        break;
    }
}

Camera::~Camera()
{
    m_videoCapture->release();
    delete m_videoCapture;
    delete m_cameraMatrix;
    delete m_distortionCoefficient;
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

void Camera::setTable(TABLE p_table)
{
    delete m_cameraMatrix;
    delete m_distortionCoefficient;

    switch(p_table)
    {
    case TABLE_1:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_1_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_1_distortion_matrix);
        break;
    case TABLE_2:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_2_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_2_distortion_matrix);
        break;
    case TABLE_3:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_3_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_3_distortion_matrix);
        break;
    case TABLE_4:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_4_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_4_distortion_matrix);
        break;
    case TABLE_5:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_5_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_5_distortion_matrix);
        break;
    case TABLE_6:
        m_cameraMatrix = new cv::Mat(3,3,CV_64F,table_6_camera_matrix);
        m_distortionCoefficient = new cv::Mat(1,5,CV_64F,table_6_distortion_matrix);
        break;
    default:
        break;
    }
}

bool Camera::operator>>(cv::Mat& p_matrix)
{
    if(m_cameraConnected)
    {
        cv::Mat v_tmp;

        bool v_success = m_videoCapture->read(v_tmp);

        if(!v_success)
        {
            emit cameraDisconnected();
            m_cameraConnected = false;
            return false;
        }

        if(m_useUndistortion)
        { 
            undistort(v_tmp, v_tmp, *m_cameraMatrix, *m_distortionCoefficient);
        }

        p_matrix = v_tmp;

    }


    return true;
}


bool Camera::operator>>(QPixmap& p_pixmap)
{
    if(m_cameraConnected)
    {
        cv::Mat v_tmp;

        bool v_success = m_videoCapture->read(v_tmp);

        if(!v_success)
        {
            emit cameraDisconnected();
            m_cameraConnected = false;
            return false;
        }

        if(m_useUndistortion)
        {
            undistort(v_tmp, v_tmp, *m_cameraMatrix, *m_distortionCoefficient);
        }

        cv::cvtColor(v_tmp, v_tmp ,cv::COLOR_BGR2RGB);

        p_pixmap = QPixmap::fromImage(QImage((unsigned char*) v_tmp.data, v_tmp.cols, v_tmp.rows, QImage::Format_RGB888));

    }

    return true;
}

QPixmap Camera::Mat2QPixmap(const cv::Mat& p_mat)
{
    cv::Mat v_tmp;

    cv::cvtColor(p_mat, v_tmp ,cv::COLOR_BGR2RGB);

    return QPixmap::fromImage(QImage((unsigned char*) v_tmp.data, v_tmp.cols, v_tmp.rows, QImage::Format_RGB888));
}

QImage Camera::Mat2QImage(const cv::Mat& p_mat)
{
    cv::Mat v_tmp;

    cv::cvtColor(p_mat, v_tmp ,cv::COLOR_BGR2RGB);

    return QImage((unsigned char*) v_tmp.data, v_tmp.cols, v_tmp.rows, QImage::Format_RGB888);
}




