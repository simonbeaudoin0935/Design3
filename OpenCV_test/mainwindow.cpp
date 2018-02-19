//Self include
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Project includes
#include "define.h"

//OpenCV includes
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"

//Qt includes
#include <QDebug>
#include <QCameraInfo>
#include <QMessageBox>

//Standard library includes
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_timer(new QTimer),
    m_time(new QTime),
    m_camera(new Camera),
    m_detecteurCarres(new DetecteurCarres),
    m_isGameStarted(false)
{
    ui->setupUi(this);

    connect(m_timer,SIGNAL(timeout()),this,SLOT(dt_timeout()));




//    for(;;)
//    {

//        Mat frame;
//
//        cap >> frame; // get a new frame from camera

//       // cvtColor(frame, edges, COLOR_BGR2GRAY);
//        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
//       // Canny(edges, edges, 0, 100, 3);
//       // difference = time.elapsed() - difference;

//        findSquares(frame,squares);


//        square.push_back(squares.at(1));



//        drawSquare(frame,squares);


//        //imshow("edges", frame);
//        //waitKey(0);
//        if(waitKey(30) >= 0) break;
//    }


}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dt_timeout()
{
    if(m_camera->isCameraConnected()){



        cv::Mat src;
        *m_camera >> src;

        if(m_isGameStarted){
            ui->lcdNumber_Elapsed_Time->display((double)((double)m_time->elapsed() / 1000.0));

            std::vector< std::vector< cv::Point>> squares;
            m_detecteurCarres->detecterCarres(src,0,0,100000,1000000,squares);
            m_detecteurCarres->drawSquare(src,squares);
        }
        else{
            ui->lcdNumber_Elapsed_Time->display(0.0);
        }

        ui->label_Computed_Image->setPixmap(m_camera->Mat2QPixmap(src));
        ui->label_Computed_Image->show();
    }
}














// Slots des widgets de la tab du jeu

void MainWindow::on_pushButton_Start_Game_clicked()
{

    if(!m_isGameStarted)
    {
        if(m_camera->isCameraConnected()){
            m_isGameStarted = true;
            ui->pushButton_Start_Game->setText("Restart");
            m_time->restart();
        }
        else{
            QMessageBox::warning(this,"Camera", "Aucune caméra n'est connectée.");
        }

    }
    else if(m_isGameStarted)
    {
       m_isGameStarted = false;
       ui->pushButton_Start_Game->setText("Lancer");
    }
}


// Slots des widgets de la tab des settings de la camera

void MainWindow::on_pushButton_Scan_Cameras_clicked()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
      foreach (const QCameraInfo &cameraInfo, cameras){
          ui->listWidget_Connected_Cameras->addItem(cameraInfo.deviceName());
      }

}

void MainWindow::on_listWidget_Connected_Cameras_itemSelectionChanged()
{
    if(!m_camera->isCameraConnected()){
        ui->pushButton_Connect_Camera->setEnabled(true);
    }
    ui->textBrowser_Description_Camera->clear();
    ui->textBrowser_Description_Camera->
        setText(QCameraInfo(ui->
                            listWidget_Connected_Cameras->
                            currentItem()->
                            text().toUtf8()).description());
}

void MainWindow::on_pushButton_Connect_Camera_clicked()
{
   m_camera->connectCamera(ui->listWidget_Connected_Cameras->currentItem()->text());

   if(m_camera->isCameraConnected()){
       ui->pushButton_Connect_Camera->setEnabled(false);
       ui->pushButton_Disconnect_Camera->setEnabled(true);

       m_timer->start(DELTA_TIME_MS);
   }
}

void MainWindow::on_pushButton_Disconnect_Camera_clicked()
{
    if(m_camera->isCameraConnected()){
        ui->pushButton_Connect_Camera->setEnabled(true);
        ui->pushButton_Disconnect_Camera->setEnabled(false);

        m_camera->disconnectCamera();
    }
}

void MainWindow::on_actionInfo_triggered()
{


    QString v_information;
    v_information.append("OpenCV Major Version : ")
                 .append(QString::number(CV_MAJOR_VERSION))
                 .append("\nOpenCV Minor Version : ")
                 .append(QString::number(CV_MINOR_VERSION));
    QMessageBox::information(NULL,"Information", v_information);
}




