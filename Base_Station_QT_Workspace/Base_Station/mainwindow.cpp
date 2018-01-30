#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QDebug>
#include <iostream>

#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_gamepadManager = QGamepadManager::instance();
    m_gamepad = 0;
    m_gamepadState = new GamepadState;
    m_serialPort = new QSerialPort;
    m_serialMotionSenderThread = new SerialMotionSender(100);
    m_cameraWorld = 0;
    m_isCameraConnected = false;

    connect(m_serialMotionSenderThread,
            SIGNAL(timeout()),
            this,
            SLOT(serial_send_on_timeout()));
    OpencvWorkerThread t();
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



        m_serialMotionSenderThread->startSending();
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
    Q_UNUSED(arg1)

    QCameraInfo v_cameraInfo(ui->comboBox_Camera_Selector->currentText().toUtf8());
    ui->textBrowser_Camera_Descriptor->clear();
    ui->textBrowser_Camera_Descriptor->append(v_cameraInfo.description());
}

void MainWindow::on_pushButton_Camera_Connect_clicked()
{
    m_cameraWorld = new QCamera(ui->comboBox_Camera_Selector->currentText().toUtf8());
    m_isCameraConnected = true;

    ui->widget_camera_viewFinder->show();

    m_cameraWorld->setViewfinder(ui->widget_camera_viewFinder);

//    imageCapture = new QCameraImageCapture(camera);

//    camera->setCaptureMode(QCamera::CaptureStillImage);
    m_cameraWorld->start();
}
