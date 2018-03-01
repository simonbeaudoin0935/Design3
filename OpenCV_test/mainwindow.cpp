//Self include
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Project includes
#include "define.h"
#include "pidvaluesstruct.h"

//OpenCV includes
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"

//Qt includes
#include <QDebug>
#include <QCameraInfo>
#include <QMessageBox>
#include <QChartView>

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
    m_statusBarCameraLabel(new QLabel("CAMERA STATUS : ")),
    m_statusBarCameraStatus(new QLabel("Disconnected")),
    m_statusBarRobotLabel(new QLabel("ROBOT STATUS : ")),
    m_statusBarRobotStatus(new QLabel("Disconnected")),
    m_isGameStarted(false),
    m_camera(new Camera),
    m_detecteurCarres(new DetecteurCarres),
    m_robotManager(new RobotManager(this))

{
    ui->setupUi(this);

    m_pidChart = new PIDChart();
    m_pidChart->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    QChartView *chartView = new QChartView(m_pidChart);
    chartView->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout_19->addWidget(chartView);

    QObject::connect(m_timer,
                     SIGNAL(timeout()),
                     this,
                     SLOT(dt_timeout()));

    QObject::connect(m_robotManager,
                     SIGNAL(robotConnectionStatus(RobotManager::ROBOT_CONNECTION)),
                     this,
                     SLOT(handleRobotConnectionStatus(RobotManager::ROBOT_CONNECTION)));

    QObject::connect(m_camera,
                     SIGNAL(cameraDisconnected()),
                     this,
                     SLOT(cameraDisconnected()));

    m_statusBarCameraStatus->setStyleSheet("QLabel { background-color : white; color : blue; }");
    m_statusBarRobotStatus->setStyleSheet("QLabel { background-color : white; color : blue; }");

    statusBar()->addWidget(m_statusBarCameraLabel);
    statusBar()->addWidget(m_statusBarCameraStatus);
    statusBar()->addWidget(m_statusBarRobotLabel);
    statusBar()->addWidget(m_statusBarRobotStatus);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dt_timeout()
{

    if(m_camera->isCameraConnected()){



        cv::Mat src;
        if (!(*m_camera >> src)) return;

        if(m_isGameStarted){
            ui->lcdNumber_Elapsed_Time->display((double)((double)m_time->elapsed() / 1000.0));

            std::vector< std::vector< cv::Point>> squares;
            m_detecteurCarres->detecterCarres(src,0,0,100000,1000000,squares);
            m_detecteurCarres->drawSquare(src,squares);


            QPixmap pix = m_camera->Mat2QPixmap(src);
            ui->label_Computed_Image->setPixmap(pix);
            ui->label_Computed_Image->show();
        }
        else{
            ui->lcdNumber_Elapsed_Time->display(0.0);
        }

    }
}





void MainWindow::handleRobotConnectionStatus(RobotManager::ROBOT_CONNECTION p_status)
{
    switch(p_status)
    {
    case RobotManager::SUCCES:
        ui->pushButton_Connect_Robot->setText("Connecté !");
        m_statusBarRobotStatus->setText("Connected");
        m_statusBarRobotStatus->setStyleSheet("QLabel { background-color : white; color : green; }");
        break;

    case RobotManager::FAILURE:
        m_statusBarRobotStatus->setText("Connection error");
        m_statusBarRobotStatus->setStyleSheet("QLabel { background-color : white; color : red; }");
        ui->pushButton_Connect_Robot->setText("Réessayer...");
        ui->pushButton_Connect_Robot->setEnabled(true);
        break;

    default:
        break;
    }
}

void MainWindow::cameraDisconnected()
{
    m_isGameStarted = false;

    ui->pushButton_Connect_Camera->setEnabled(false);
    ui->pushButton_Disconnect_Camera->setEnabled(false);
    ui->listWidget_Connected_Cameras->clear();
    ui->textBrowser_Description_Camera->clear();

    m_statusBarCameraStatus->setText("Camera Error");
    m_statusBarCameraStatus->setStyleSheet("QLabel { background-color : white; color : red; }");


}







/*
 * Slots des widgets de la tab du jeu
 */

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



/*
 * Slots des widgets de la tab des settings
 */


void MainWindow::on_pushButton_Scan_Cameras_clicked()
{
    ui->listWidget_Connected_Cameras->clear();
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

       m_statusBarCameraStatus->setStyleSheet("QLabel { background-color : white; color : green; }");
       m_statusBarCameraStatus->setText("Connected");

       m_timer->start(DELTA_TIME_MS);
   }
}

void MainWindow::on_pushButton_Disconnect_Camera_clicked()
{
    if(m_camera->isCameraConnected()){
        ui->pushButton_Connect_Camera->setEnabled(true);
        ui->pushButton_Disconnect_Camera->setEnabled(false);

        m_statusBarCameraStatus->setStyleSheet("QLabel { background-color : white; color : blue; }");
        m_statusBarCameraStatus->setText("Disconnected");

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

void MainWindow::on_pushButton_Connect_Robot_clicked()
{
    ui->pushButton_Connect_Robot->setText("Connexion ...");
    ui->pushButton_Connect_Robot->setEnabled(false);

    QString v_ipAdress;

    if(ui->radioButton_PLT_3105->isChecked())
    {
        v_ipAdress.append("192.168.1.1");
    }
    else
    {
        v_ipAdress.append("192.168.0.1");
    }

    v_ipAdress.append(QString::number(ui->spinBox_Robot_Number->value()));



    m_robotManager->connectToRobot(v_ipAdress, ui->spinBox_Robot_Port->value());
}


/*
 * slots des widgets de la tab PID
 */

void MainWindow::on_pushButton_PID_Pause_Play_clicked()
{
    if(ui->pushButton_PID_Pause_Play->text() == "Pause"){
        ui->pushButton_PID_Pause_Play->setText("Play");
        m_pidChart->play_pause(false);
    }
    else{
         ui->pushButton_PID_Pause_Play->setText("Pause");
         m_pidChart->play_pause(true);
    }
}

void MainWindow::on_pushButton_PID_Activate_clicked()
{
    if(ui->pushButton_PID_Activate->text() == "Activer"){
        ui->pushButton_PID_Activate->setText("Desactiver");
        m_robotManager->sendCommand_Activate_PID_Debug(true);
    }
    else{
        ui->pushButton_PID_Activate->setText("Activer");
        m_robotManager->sendCommand_Activate_PID_Debug(true);
    }
}

void MainWindow::on_pushButton_PID_Start_clicked()
{
    if(ui->radioButton_Deplacement_X->isChecked())
    {
        m_robotManager->sendCommand_Displacement_X((float) ui->doubleSpinBox_Deplacement_X->value());
    }
    else if(ui->radioButton_Deplacement_Y->isChecked())
    {
        m_robotManager->sendCommand_Displacement_Y((float) ui->doubleSpinBox_Deplacement_Y->value());
    }
    else if(ui->radioButton_Deplacement_R->isChecked())
    {
        m_robotManager->sendCommand_Displacement_R((float) ui->doubleSpinBox_Deplacement_R->value());
    }
}

void MainWindow::on_pushButton_PID_Kill_clicked()
{
    m_robotManager->sendCommand_Cancel_Displacement();
}

void MainWindow::on_pushButton_Read_PID_Values_clicked()
{
    m_robotManager->sendCommand_Request_PID_Values();
}

void MainWindow::on_pushButton_Store_PID_Values_clicked()
{
    PIDValuesStruct v_pidValues;

    v_pidValues.position_X_PKp  = (float) ui->doubleSpinBox_Position_X_PKp->value();
    v_pidValues.position_X_PKi  = (float) ui->doubleSpinBox_Position_X_PKi->value();
    v_pidValues.position_X_PKd  = (float) ui->doubleSpinBox_Position_X_PKd->value();
    v_pidValues.position_X_Vmax = (float) ui->doubleSpinBox_Position_X_Vmax->value();
    v_pidValues.position_X_Amax = (float) ui->doubleSpinBox_Position_X_Amax->value();

    v_pidValues.position_Y_PKp  = (float) ui->doubleSpinBox_Position_Y_PKp->value();
    v_pidValues.position_Y_PKi  = (float) ui->doubleSpinBox_Position_Y_PKi->value();
    v_pidValues.position_Y_PKd  = (float) ui->doubleSpinBox_Position_Y_PKd->value();
    v_pidValues.position_Y_Vmax = (float) ui->doubleSpinBox_Position_Y_Vmax->value();
    v_pidValues.position_Y_Amax = (float) ui->doubleSpinBox_Position_Y_Amax->value();

    v_pidValues.position_R_PKp  = (float) ui->doubleSpinBox_Position_R_PKp->value();
    v_pidValues.position_R_PKi  = (float) ui->doubleSpinBox_Position_R_PKi->value();
    v_pidValues.position_R_PKd  = (float) ui->doubleSpinBox_Position_R_PKd->value();
    v_pidValues.position_R_Vmax = (float) ui->doubleSpinBox_Position_R_Vmax->value();
    v_pidValues.position_R_Amax = (float) ui->doubleSpinBox_Position_R_Amax->value();

    v_pidValues.motor_1_VKp = (float) ui->doubleSpinBox_Motor_1_VKp->value();
    v_pidValues.motor_1_VKi = (float) ui->doubleSpinBox_Motor_1_VKi->value();
    v_pidValues.motor_1_VKd = (float) ui->doubleSpinBox_Motor_1_VKd->value();

    v_pidValues.motor_2_VKp = (float) ui->doubleSpinBox_Motor_2_VKp->value();
    v_pidValues.motor_2_VKi = (float) ui->doubleSpinBox_Motor_2_VKi->value();
    v_pidValues.motor_2_VKd = (float) ui->doubleSpinBox_Motor_2_VKd->value();

    v_pidValues.motor_3_VKp = (float) ui->doubleSpinBox_Motor_3_VKp->value();
    v_pidValues.motor_3_VKi = (float) ui->doubleSpinBox_Motor_3_VKi->value();
    v_pidValues.motor_3_VKd = (float) ui->doubleSpinBox_Motor_3_VKd->value();

    v_pidValues.motor_4_VKp = (float) ui->doubleSpinBox_Motor_4_VKp->value();
    v_pidValues.motor_4_VKi = (float) ui->doubleSpinBox_Motor_4_VKi->value();
    v_pidValues.motor_4_VKd = (float) ui->doubleSpinBox_Motor_4_VKd->value();

    v_pidValues.dt = (float) ui->doubleSpinBox_dT->value();
    v_pidValues.wheel_diameter = (float) ui->doubleSpinBox_wheelDiameter->value();

    m_robotManager->sendCommand_Store_PID_Values(v_pidValues);

}






