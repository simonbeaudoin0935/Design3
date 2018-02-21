#include "robotmanagerthread.h"
#include <QBuffer>
#include <QMessageBox>

RobotManagerThread::RobotManagerThread(QObject* p_parent):
    m_parent(p_parent),
    m_isConnectedToRobot(false),
    m_robotTcpSocket(new QTcpSocket(this))
{
    m_robotDataStream.setDevice(m_robotTcpSocket);
    m_robotDataStream.setVersion(QDataStream::Qt_5_10);


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
   // this->start();

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
    int index = 0;

    while(1)
    {
        qDebug() << "index : " << index << "\n";
        sendCommand_Ping(index++);

        sleep(1);

    }

}




bool RobotManagerThread::sendCommand_Ping(int p_index)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out  << p_index;



        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManagerThread::sendCommand_XDisplacement(float p_displacementCM)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        v_robotCommand.append(0x03);
    }

    return m_isConnectedToRobot;
}

bool RobotManagerThread::sendCommand_Pixmap(QPixmap &img)
{
    if(m_isConnectedToRobot)
    {

        QByteArray ba;
        QBuffer buff(&ba);

        buff.open(QIODevice::WriteOnly);

        img.save(&buff,"PNG");






        union
        {
            qint64 entier;
            char bytes[sizeof(qint64)];
        }v_data;

        v_data.entier = ba.size();

     //   for(int i = 0 ; i != sizeof(qint64); i++)
     //   {
     //          ba.prepend(v_data.bytes[i]);
      //  }

        qDebug() << "size of :" << v_data.entier << "\n";
        m_robotDataStream.writeRawData(v_data.bytes, sizeof(qint64));
        m_robotTcpSocket->write(ba);

        QImage img = QImage::fromData(ba,"PNG");
        img.save("/home/simon/yowasa.png", "PNG");
    }

    return m_isConnectedToRobot;
}
















































