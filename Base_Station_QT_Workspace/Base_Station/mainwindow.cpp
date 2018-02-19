#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QDebug>
#include <iostream>

#include <QImage>
#include <QCameraInfo>
#include <QImageEncoderSettings>

#include <QtCharts/QChartView>

#include "opencvworkerthread.h"



//#include "opencvworkerthread.h"
//#include <opencv2/opencv.hpp>
//using namespace cv;




void send_float_value(QByteArray &array, float p_value){
    typedef union{
        float floating;
        char  bytes[4];
    }float_t;

    float_t v_float;

    v_float.floating = p_value;

    array.append(v_float.bytes[0]);
    array.append(v_float.bytes[1]);
    array.append(v_float.bytes[2]);
    array.append(v_float.bytes[3]);
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_isSerialPortConnected(false),
    m_isGamepadConnected(false),
    m_isCameraConnected(false)
{
    ui->setupUi(this);

    m_pid_chart = new PID_Chart();
    m_pid_chart->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    QChartView *chartView = new QChartView(m_pid_chart);
    chartView->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->tab_8->layout()->addWidget(chartView);


    //ui->graphicsView_PID->setViewport(chartView);
    //ui->graphicsView_PID->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));

    m_gamepadManager = QGamepadManager::instance();
    m_gamepad = 0;
    m_gamepadState = new GamepadState;
    m_serialPort = new QSerialPort;
    m_serialMotionSenderThread = new SerialMotionSender(100);
    m_cameraWorld = 0;


    connect(m_serialMotionSenderThread,
            SIGNAL(timeout()),
            this,
            SLOT(serial_send_on_timeout()));




    m_openCVWorkerThread = new OpencvWorkerThread();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_Gamepad_Connect_clicked()
{
    auto gamepads = m_gamepadManager->connectedGamepads();
    if (gamepads.isEmpty()) {
        QMessageBox::warning(this,"Gamepad Connection", "No gamepad found.");
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
    m_isGamepadConnected = true;

//left stick
    connect(m_gamepad,
            SIGNAL(axisLeftXChanged(double)),
            this,
            SLOT(gamepad_Left_Stick_X_Changed(double)));

    connect(m_gamepad,
            SIGNAL(axisLeftYChanged(double)),
            this,
            SLOT(gamepad_Left_Stick_Y_Changed(double)));

//right stick
    connect(m_gamepad,
            SIGNAL(axisRightXChanged(double)),
            this,
            SLOT(gamepad_Right_Stick_X_Changed(double)));

    connect(m_gamepad,
            SIGNAL(axisRightYChanged(double)),
            this,
            SLOT(gamepad_Right_Stick_Y_Changed(double)));

//triggers
    connect(m_gamepad,
            SIGNAL(buttonL2Changed(double)),
            this,
            SLOT(gamepad_Left_Trigger_Changed(double)));

    connect(m_gamepad,
            SIGNAL(buttonR2Changed(double)),
            this,
            SLOT(gamepad_Right_Trigger_Changed(double)));


//cross buttons
    connect(m_gamepad,
            SIGNAL(buttonUpChanged(bool)),
            this,
            SLOT(gamepad_UP_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonDownChanged(bool)),
            this,
            SLOT(gamepad_DOWN_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonLeftChanged(bool)),
            this,
            SLOT(gamepad_LEFT_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonRightChanged(bool)),
            this,
            SLOT(gamepad_RIGHT_Changed(bool)));

//buttons
    connect(m_gamepad,
            SIGNAL(buttonAChanged(bool)),
            this,
            SLOT(gamepad_A_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonBChanged(bool)),
            this,
            SLOT(gamepad_B_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonXChanged(bool)),
            this,
            SLOT(gamepad_X_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonYChanged(bool)),
            this,
            SLOT(gamepad_Y_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonStartChanged(bool)),
            this,
            SLOT(gamepad_START_Changed(bool)));

    connect(m_gamepad,
            SIGNAL(buttonSelectChanged(bool)),
            this,
            SLOT(gamepad_BACK_Changed(bool)));




    ui->pushButton_Gamepad_Connect->setEnabled(false);
    ui->pushButton_Gamepad_Disconnect->setEnabled(true);

    ui->progressBar_Left_Stick_X->setEnabled(true);
    ui->progressBar_Left_Stick_Y->setEnabled(true);

    ui->progressBar_Right_Stick_X->setEnabled(true);
    ui->progressBar_Right_Stick_Y->setEnabled(true);


    ui->progressBar_Left_Trigger->setEnabled(true);
    ui->progressBar_Right_Trigger->setEnabled(true);

    ui->pushButton_Gamepad_UP->setEnabled(true);
    ui->pushButton_Gamepad_DOWN->setEnabled(true);
    ui->pushButton_Gamepad_LEFT->setEnabled(true);
    ui->pushButton_Gamepad_RIGHT->setEnabled(true);

    ui->pushButton_Gamepad_A->setEnabled(true);
    ui->pushButton_Gamepad_B->setEnabled(true);
    ui->pushButton_Gamepad_X->setEnabled(true);
    ui->pushButton_Gamepad_Y->setEnabled(true);

    ui->pushButton_Gamepad_LEFT_STICK->setEnabled(true);
    ui->pushButton_Gamepad_RIGHT_STICK->setEnabled(true);

    ui->pushButton_Gamepad_BLACK->setEnabled(true);
    ui->pushButton_Gamepad_WHITE->setEnabled(true);

    ui->pushButton_Gamepad_START->setEnabled(true);
    ui->pushButton_Gamepad_BACK->setEnabled(true);

    if(m_isSerialPortConnected){
        m_serialMotionSenderThread->startSending();
    }
}

    //GAMEPAD INPUT CHANGES SLOTS
void MainWindow::gamepad_Left_Stick_X_Changed(double p_value)
{
    int v_val = 50 + (int)(p_value*50);
    ui->progressBar_Left_Stick_X->setValue(v_val);
    m_gamepadState->setLeft_stick_x((signed char)(p_value*100.0));
}

void MainWindow::gamepad_Left_Stick_Y_Changed(double p_value)
{
    int v_val = 50 + (int)(p_value*50);
    ui->progressBar_Left_Stick_Y->setValue(v_val);
    m_gamepadState->setLeft_stick_y((signed char)(p_value*100.0));
}

void MainWindow::gamepad_Right_Stick_X_Changed(double p_value)
{
    int v_val = 50 + (int)(p_value*50);
    ui->progressBar_Right_Stick_X->setValue(v_val);
    m_gamepadState->setRight_stick_x((signed char)(p_value*100.0));
}

void MainWindow::gamepad_Right_Stick_Y_Changed(double p_value)
{
    int v_val = 50 + (int)(p_value*50);
    ui->progressBar_Right_Stick_Y->setValue(v_val);
    m_gamepadState->setRight_stick_y((signed char)(p_value*100.0));
}

void MainWindow::gamepad_Left_Trigger_Changed(double p_value)
{
    int v_val = (int)(p_value *100);
    ui->progressBar_Left_Trigger->setValue(v_val);
    m_gamepadState->setLeft_trigger((signed char)(p_value*100.0));
}

void MainWindow::gamepad_Right_Trigger_Changed(double p_value)
{
    int v_val = (int)(p_value *100);
    ui->progressBar_Right_Trigger->setValue(v_val);
    m_gamepadState->setRight_trigger((signed char)(p_value*100.0));
}

void MainWindow::gamepad_UP_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_DOWN_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_LEFT_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_RIGHT_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_A_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_B_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_X_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_Y_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_WHITE_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_BLACK_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_LEFT_STICK_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_RIGHT_STICK_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_START_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}

void MainWindow::gamepad_BACK_Changed(bool p_value)
{
    Q_UNUSED(p_value)
}






void MainWindow::on_pushButton_Serial_Connect_clicked()
{
    m_serialPort->setPortName(ui->comboBox_Serial_Selector->currentText());
    m_serialPort->setBaudRate(QSerialPort::Baud115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setReadBufferSize(255);

    if (!m_serialPort->open(QIODevice::ReadWrite)) {
        QString v_error_string;
        if(m_serialPort->error() == 2) v_error_string = "An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open.";
        QMessageBox::warning(this,"Serial Port", tr("Can't open %1, error code %2 : \n").arg(ui->comboBox_Serial_Selector->currentText()).arg(m_serialPort->error()) + v_error_string);
        return;
    }
    else
    {

        ui->pushButton_Serial_Connect->setEnabled(false);
        ui->pushButton_Serial_Disconnect->setEnabled(true);

        connect(m_serialPort,
                SIGNAL(readyRead()),
                this,
                SLOT(serial_data_received()));

        m_isSerialPortConnected = true;

        if(m_isGamepadConnected){
            m_serialMotionSenderThread->startSending();
        }

    }
}

void MainWindow::on_pushButton_Serial_Scan_clicked()
{
    ui->comboBox_Serial_Selector->clear();

    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {

        ui->comboBox_Serial_Selector->addItem(info.portName());

    }
}

void MainWindow::on_comboBox_Serial_Selector_currentIndexChanged(const QString &arg1)
{
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {

        if(info.portName() == arg1)
        {
            QString s = QObject::tr("Port: ") + info.portName() + "\n"
                      + QObject::tr("Location: ") + info.systemLocation() + "\n"
                      + QObject::tr("Description: ") + info.description() + "\n"
                      + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                      + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                      + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                      + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                      + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
            ui->textBrowser_Serial_Description->clear();
            ui->textBrowser_Serial_Description->append(s);
            QTextCursor cursor = ui->textBrowser_Serial_Description->textCursor();
            cursor.setPosition(0);
            ui->textBrowser_Serial_Description->setTextCursor(cursor);
        }


    }
}

void MainWindow::serial_send_on_timeout()
{
    QByteArray v_message;
    v_message.append('#');
    v_message.append(0x02);
    v_message.append(0x06);
    v_message.append(m_gamepadState->left_stick_x());
    v_message.append(m_gamepadState->left_stick_y());
    v_message.append(m_gamepadState->right_stick_x());
    v_message.append(m_gamepadState->right_stick_y());
    v_message.append(m_gamepadState->left_trigger());
    v_message.append(m_gamepadState->right_trigger());
    v_message.append('.');

    qDebug()<<v_message<<"\n";
    m_serialPort->write(v_message);
    if(m_serialPort->error() != 0){
        std::cout << "Error : " << m_serialPort->error() << "\n";
    }
}





float receive_float_value(QByteArray::Iterator &it){
    typedef union{
        float floating;
        char  bytes[4];
    }float_t;

    float_t v_float;

    v_float.bytes[0] = *it; it++;
    v_float.bytes[1] = *it; it++;
    v_float.bytes[2] = *it; it++;
    v_float.bytes[3] = *it; it++;

    return v_float.floating;
}

void MainWindow::serial_data_received()
{

    QByteArray v_bytes = m_serialPort->readAll();
    for(int i = 0; i < v_bytes.count(); i++){
        if(m_serialReceiveStateMachine.parseMessage(v_bytes.at(i))){

            QByteArray v_data = m_serialReceiveStateMachine.getMessageContent();

            typedef union{
                int   integer;
                float floating;
                char  bytes[sizeof(int)]; //[4]
            }type_u;




            switch(m_serialReceiveStateMachine.getMessageId()){

            case 0x01:





                break;

            case 0x02:
                break;

             case 0x03:

                m_pid_chart->addPIDOutputPoint(v_data);
                break;

             case 0x04:
                {

                    QByteArray::iterator byte_array_it = v_data.begin();
                    ui->doubleSpinBox_Motor_1_PKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_PKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_PKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_VKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_VKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_VKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_Amax->setValue( (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_1_Vmax->setValue( (double)(receive_float_value(byte_array_it)));

                    ui->doubleSpinBox_Motor_2_PKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_PKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_PKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_VKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_VKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_VKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_Amax->setValue( (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_2_Vmax->setValue( (double)(receive_float_value(byte_array_it)));

                    ui->doubleSpinBox_Motor_3_PKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_PKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_PKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_VKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_VKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_VKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_Amax->setValue( (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_3_Vmax->setValue( (double)(receive_float_value(byte_array_it)));

                    ui->doubleSpinBox_Motor_4_PKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_PKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_PKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_VKp->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_VKi->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_VKd->setValue(  (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_Amax->setValue( (double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_Motor_4_Vmax->setValue( (double)(receive_float_value(byte_array_it)));

                    ui->doubleSpinBox_dT->setValue((double)(receive_float_value(byte_array_it)));
                    ui->doubleSpinBox_wheelDiameter->setValue((double)(receive_float_value(byte_array_it)));

                }
                break;


            default:
                break;
            }
        }
    }
}

void MainWindow::on_pushButton_Serial_Disconnect_clicked()
{
    this->m_serialMotionSenderThread->stopSending();

    ui->pushButton_Serial_Connect->setEnabled(true);
    ui->pushButton_Serial_Disconnect->setEnabled(false);

    disconnect(m_serialPort,
                SIGNAL(readyRead()),
                this,
                SLOT(serial_data_received()));



    this->m_serialPort->disconnect();
    this->m_isSerialPortConnected = false;
}

void MainWindow::on_pushButton_PID_Pause_Play_clicked()
{
    if(ui->pushButton_PID_Pause_Play->text() == "Pause"){
        ui->pushButton_PID_Pause_Play->setText("Play");
        m_pid_chart->play_pause(false);
    }
    else{
         ui->pushButton_PID_Pause_Play->setText("Pause");
         m_pid_chart->play_pause(true);
    }
}

void MainWindow::on_pushButton_Reset_PID_clicked()
{
    if(!m_isSerialPortConnected){
        return;
    }

    QByteArray data;

    data.append('#');
    data.append((char)0x03);
    data.append((char)0x05);

    if(ui->radioButton_Deplacement_X->isChecked()){
        data.append((char)0x01);
         send_float_value(data, (float)(ui->doubleSpinBox_Deplacement_X->value()));
    }
    else if(ui->radioButton_Deplacement_Y->isChecked()){
        data.append((char)0x02);
        send_float_value(data, (float)(ui->doubleSpinBox_Deplacement_Y->value()));
    }
    else if(ui->radioButton_Deplacement_R->isChecked()){
        data.append((char)0x03);
        send_float_value(data, (float)(ui->doubleSpinBox_Deplacement_R->value()));
    }
    else{
        return;
    }

    data.append('.');

    m_serialPort->write(data);
}

void MainWindow::on_pushButton_Read_PID_clicked()
{
    QByteArray data;
    data.append('#');
    data.append(0x01);
    data.append((char)0x00);
    data.append('.');

    m_serialPort->write(data);
}

void MainWindow::on_pushButton_Store_PID_clicked()
{
    QByteArray data;

    data.append('#');
    data.append(0x02);
    data.append(0x88); //size

    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_PKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_PKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_PKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_VKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_VKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_VKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_Amax->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_1_Vmax->value()));

    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_PKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_PKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_PKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_VKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_VKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_VKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_Amax->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_2_Vmax->value()));

    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_PKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_PKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_PKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_VKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_VKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_VKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_Amax->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_3_Vmax->value()));

    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_PKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_PKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_PKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_VKp->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_VKi->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_VKd->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_Amax->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_Motor_4_Vmax->value()));

    send_float_value(data, (float)(ui->doubleSpinBox_dT->value()));
    send_float_value(data, (float)(ui->doubleSpinBox_wheelDiameter->value()));

    data.append('.');

    m_serialPort->write(data);

}

void MainWindow::on_pushButton_Take_Image_clicked()
{
    qDebug() << "Desc : " << m_cameraImageCapture->supportedBufferFormats() << "\n" ;
    if(m_isCameraConnected){
        if(m_cameraImageCapture->isReadyForCapture()){
            m_cameraImageCapture->capture(ui->lineEdit_Camera_Image_Name->text());
            //m_cameraImageCapture->capture("home/simon/Pictures/wasaboy.png");
        }
        else{
            QMessageBox::warning(this,"camera", "camera not ready for image capture");
        }
    }
    else{
        QMessageBox::warning(this,"camera","camera non connectée");
    }

}

void MainWindow::image_saved(int p_int, QString p_string)
{
    Q_UNUSED(p_int);

    QMessageBox::information(this,"Image","Image saved as : " + p_string);

    m_openCVWorkerThread->setImageToCompute(p_string);
    m_openCVWorkerThread->start();
}


void MainWindow::on_pushButton_Camera_Scan_clicked()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
      foreach (const QCameraInfo &cameraInfo, cameras){
          qDebug() << cameraInfo.deviceName();
          ui->comboBox_Camera_Selector->addItem(cameraInfo.deviceName());
      }


}

void MainWindow::on_comboBox_Camera_Selector_currentIndexChanged(const QString &arg1)
{
    QCameraInfo v_cameraInfo(arg1.toUtf8());
    ui->textBrowser_Camera_Descriptor->clear();
    ui->textBrowser_Camera_Descriptor->append(v_cameraInfo.description());
}

void MainWindow::on_pushButton_Camera_Connect_clicked()
{
    m_cameraWorld = new QCamera(ui->comboBox_Camera_Selector->currentText().toUtf8());
    m_isCameraConnected = true;

    m_cameraWorld->setViewfinder(ui->widget_camera_viewFinder);

    m_cameraImageCapture = new QCameraImageCapture(m_cameraWorld);

   // QImageEncoderSettings v_imageSettings;
   // v_imageSettings.setCodec("PNG");
   // v_imageSettings.setQuality(QMultimedia::VeryHighQuality);
    //v_imageSettings.setQuality(QMultimedia::VeryLowQuality);
    //v_imageSettings.setResolution(1600,1200);
   // m_cameraImageCapture->setEncodingSettings(v_imageSettings);
    m_cameraWorld->setCaptureMode(QCamera::CaptureStillImage);

    connect(m_cameraImageCapture, SIGNAL(imageSaved(int,QString)),this,SLOT(image_saved(int,QString)));

    m_cameraWorld->start();
}

