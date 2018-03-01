#include "mainthread.h"

MainThread::MainThread():
    m_baseStationHandler(new BaseStationHandler),
    m_motorControllerHandler(new MotorControllerHandler)
{
    QObject::connect(m_baseStationHandler,
                     SIGNAL(forwardToMotorController(QByteArray)),
                     m_motorControllerHandler,
                     SLOT(forwardMessage(QByteArray)));
}

MainThread::~MainThread()
{

}

void MainThread::run()
{

}
