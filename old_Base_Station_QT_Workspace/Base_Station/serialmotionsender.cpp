#include "serialmotionsender.h"
#include <QDebug>
#include <iostream>

SerialMotionSender::SerialMotionSender(unsigned int p_sendIntervalMS):
    m_sendIntervalMS(p_sendIntervalMS),
    m_continueSenting(false)
{

}

void SerialMotionSender::run()
{
    do
    {
        this->msleep(m_sendIntervalMS);
        emit timeout();

    }while(m_continueSenting);
}

void SerialMotionSender::stopSending()
{
    m_continueSenting = false;
}

void SerialMotionSender::startSending()
{
    if(m_continueSenting == true){
        return;
    }
    else{
        m_continueSenting = true;
        this->start();
    }

}


