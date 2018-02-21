#include "robotmanagerthread.h"

#include <QMessageBox>

RobotManagerThread::RobotManagerThread(QObject* p_parent):
    m_parent(p_parent),
    m_isConnectedToRobot(false),
    m_robotTcpSocket(new QTcpSocket(this))
{
    m_robotInputDataStream.setDevice(m_robotTcpSocket);
    m_robotInputDataStream.setVersion(QDataStream::Qt_5_10);


    QObject::connect(m_robotTcpSocket,
                     SIGNAL(connected()),
                     this,
                     SLOT(connected()));

    QObject::connect(m_robotTcpSocket,
                     SIGNAL(disconnected()),
                     this,
                     SLOT(disconnected()));

    QObject::connect(m_robotTcpSocket,
                     SIGNAL(readyRead()),
                     this,
                     SLOT(readyRead()));

    QObject::connect(m_robotTcpSocket,
                     QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                     [this](QAbstractSocket::SocketError socketError){this->error(socketError);});

}

RobotManagerThread::~RobotManagerThread()
{

}


//robot tcp socket slots

void RobotManagerThread::connected()
{
    m_isConnectedToRobot = true;
    emit robotConnectionStatus(ROBOT_CONNECTION::SUCCES);

}

void RobotManagerThread::disconnected()
{
    m_isConnectedToRobot = false;
    emit robotConnectionStatus(ROBOT_CONNECTION::FAILURE);
}


void RobotManagerThread::error(QAbstractSocket::SocketError p_socketError)
{
    switch (p_socketError) {

    case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::information((QWidget*) m_parent, tr("RemoteHostClosedError"),
                                 tr("L'hôte a fermé la connection."));
        break;

    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information((QWidget*) m_parent, tr("HostNotFoundError"),
                                 tr("L'hôte n'a pas pu être trouvé, vérifier l'adresse et le port."));
        break;

    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information((QWidget*) m_parent, tr("ConnectionRefusedError"),
                                 "La connection a été refusée par l'hôte");
        break;

    default:
        QMessageBox::information((QWidget*) m_parent, tr("Error"),
                                 tr("Erreur inconnue : %1.")
                                 .arg(m_robotTcpSocket->errorString()));
    }

    m_isConnectedToRobot = false;

    emit robotConnectionStatus(ROBOT_CONNECTION::FAILURE);

}

void RobotManagerThread::readyRead()
{
    qDebug() << "ready read tcp socket \n";
}

//public functions

bool RobotManagerThread::isConnectedToRobot() const
{
    return m_isConnectedToRobot;
}

void RobotManagerThread::connectToRobot(QString p_ipAdress, int p_port)
{
    m_isConnectedToRobot = false;
    m_robotTcpSocket->abort();
    m_robotTcpSocket->connectToHost(p_ipAdress, p_port);


}


//thread code


void RobotManagerThread::run()
{

}


