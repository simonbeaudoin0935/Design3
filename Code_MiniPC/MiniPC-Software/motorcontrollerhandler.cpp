#include "motorcontrollerhandler.h"
#include <QDebug>
MotorControllerHandler::MotorControllerHandler() :
    m_isConnected(false),
    m_serialPort(new QSerialPort)
{
    m_serialPort->setPortName("/dev/ttyACM0");
    m_serialPort->setBaudRate(QSerialPort::Baud115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setStopBits(QSerialPort::OneStop);

    if(!m_serialPort->open(QIODevice::ReadWrite))
    {
        m_isConnected = false;
        qDebug() << "Error opening serialport : " << m_serialPort->errorString() << "\n";
    }
    else
    {
        m_isConnected = true;
        QObject::connect(m_serialPort,
                         SIGNAL(readyRead()),
                         this,
                         SLOT(dataReady()));
    }
}

void MotorControllerHandler::forwardMessage(QByteArray data)
{
    if(m_isConnected)
    {
        m_serialPort->write(data);
    }
}

void MotorControllerHandler::dataReady()
{

}
