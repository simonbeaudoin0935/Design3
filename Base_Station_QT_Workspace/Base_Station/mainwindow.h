#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtGamepad/QGamepad>
#include <QtSerialPort/QtSerialPort>
#include <QCamera>

#include "gamepadstate.h"
#include "serialmotionsender.h"

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

    void on_pushButton_Camera_Scan_clicked();

    void on_comboBox_Camera_Selector_currentIndexChanged(const QString &arg1);

    void on_pushButton_Camera_Connect_clicked();

private:
    Ui::MainWindow *ui;

//gamepad members
    QGamepadManager *m_gamepadManager;
    QGamepad        *m_gamepad;
    GamepadState    *m_gamepadState;

//serial port members
    QSerialPort     *m_serialPort;

//serial motion sender
    SerialMotionSender *m_serialMotionSenderThread;

    QCamera *m_cameraWorld;

};

#endif // MAINWINDOW_H
