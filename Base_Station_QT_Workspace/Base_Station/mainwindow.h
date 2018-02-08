#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtGamepad/QGamepad>
#include <QtSerialPort/QtSerialPort>
#include <QCamera>

#include "gamepadstate.h"
#include "serialmotionsender.h"
#include "opencvworkerthread.h"
#include "serialreceivestatemachine.h"
#include "pid_chart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

//gamepad tab widget slots
    void on_pushButton_Gamepad_Connect_clicked();

//gamepad inputs change slots
    void gamepad_Left_Stick_X_Changed(double p_value);
    void gamepad_Left_Stick_Y_Changed(double p_value);
    void gamepad_Right_Stick_X_Changed(double p_value);
    void gamepad_Right_Stick_Y_Changed(double p_value);
    void gamepad_Left_Trigger_Changed(double p_value);
    void gamepad_Right_Trigger_Changed(double p_value);
    void gamepad_UP_Changed(bool p_value);
    void gamepad_DOWN_Changed(bool p_value);
    void gamepad_LEFT_Changed(bool p_value);
    void gamepad_RIGHT_Changed(bool p_value);
    void gamepad_A_Changed(bool p_value);
    void gamepad_B_Changed(bool p_value);
    void gamepad_X_Changed(bool p_value);
    void gamepad_Y_Changed(bool p_value);
    void gamepad_WHITE_Changed(bool p_value);
    void gamepad_BLACK_Changed(bool p_value);
    void gamepad_LEFT_STICK_Changed(bool p_value);
    void gamepad_RIGHT_STICK_Changed(bool p_value);
    void gamepad_START_Changed(bool p_value);
    void gamepad_BACK_Changed(bool p_value);



//serial tab widget slots
    void on_pushButton_Serial_Connect_clicked();
    void on_pushButton_Serial_Scan_clicked();
    void on_comboBox_Serial_Selector_currentIndexChanged(const QString &arg1);


    void serial_send_on_timeout();

//Camera tab widget slots
    void on_pushButton_Camera_Scan_clicked();

    void on_comboBox_Camera_Selector_currentIndexChanged(const QString &arg1);

    void on_pushButton_Camera_Connect_clicked();

//Motor tab slots

    void serial_data_received();


    void on_pushButton_Serial_Disconnect_clicked();

    void on_pushButton_Reset_PID_clicked();

    void on_pushButton_PID_Pause_Play_clicked();

    void on_pushButton_Read_PID_clicked();

    void on_pushButton_Store_PID_clicked();

private:
    Ui::MainWindow *ui;

    bool                m_isSerialPortConnected;
    QSerialPort*        m_serialPort;
    SerialMotionSender* m_serialMotionSenderThread;
    SerialReceiveStateMachine m_serialReceiveStateMachine;

    bool                m_isGamepadConnected;
    QGamepad*           m_gamepad;
    QGamepadManager*    m_gamepadManager;
    GamepadState*       m_gamepadState;

    bool             m_isCameraConnected;
    QCamera*         m_cameraWorld;

    PID_Chart       *m_pid_chart;



};

#endif // MAINWINDOW_H
