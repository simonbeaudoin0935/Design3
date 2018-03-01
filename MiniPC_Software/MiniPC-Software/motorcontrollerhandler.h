#ifndef MOTORCONTROLLERHANDLER_H
#define MOTORCONTROLLERHANDLER_H

#include <QtSerialPort/QSerialPort>
#include "receivestatemachine.h"

class MotorControllerHandler : public QObject
{

    Q_OBJECT

public:
    MotorControllerHandler();

public slots :
    void forwardMessage(QByteArray data);

private slots:
    void dataReady();

private:
    bool m_isConnected;
    QSerialPort* m_serialPort;
    ReceiveStateMachine m_receiveStateMachine;


};

#endif // MOTORCONTROLLERHANDLER_H
