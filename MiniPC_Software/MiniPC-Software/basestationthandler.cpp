#include "basestationhandler.h"

BaseStationHandler::BaseStationHandler(QObject *p_parent):
    m_parent(p_parent),
    m_tcpServer(new QTcpServer(this)),
    m_tcpSocket(0),
    m_baseStationDataStream(new QDataStream())
{

    m_baseStationDataStream->setVersion(QDataStream::Qt_5_10);

    QObject::connect(m_tcpServer,
                     SIGNAL(newConnection()),
                     this,
                     SLOT(incomingConnection()));


    if(!m_tcpServer->listen(QHostAddress::Any, 20000))
    {
        qDebug() << "probleme de serveur";
    }

}

BaseStationHandler::~BaseStationHandler()
{
    m_tcpServer->close();
    m_tcpSocket->close();

    delete m_tcpServer;
    delete m_tcpSocket;
    delete m_baseStationDataStream;
}

void BaseStationHandler::incomingConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();

    m_baseStationDataStream->setDevice(m_tcpSocket);

    QObject::connect(m_tcpSocket,
                     SIGNAL(readyRead()),
                     this,
                     SLOT(readyRead()));

    qDebug() << "Incoming ! Adress : "
             << m_tcpSocket->peerName()
             << " Adress : "
             << m_tcpSocket->peerAddress().toString()
             << " Port : "
             << QString::number(m_tcpSocket->peerPort());

}

void BaseStationHandler::readyRead()
{
    qDebug() << "READY READ\n";
    m_baseStationDataStream->startTransaction();

    qint8 v_bsCommand = 0x00;

    *m_baseStationDataStream >> v_bsCommand;

    switch(v_bsCommand)
    {
    case PING : handleCommand_Ping();
            break;

    case DISPLACEMENT_X:

        break;

    case DISPLACEMENT_Y:

        break;

    case DISPLACEMENT_R:

        break;

    case CANCEL_DISPLACEMENT:

        break;

    case CHANGE_LED_STATE:
        break;

    case REQUEST_COUNTRY_CODE:
        break;

    case TILT_CAMERA_LEFT_RIGHT:
        break;

    case TILT_CAMERA_UP_DOWN:
        break;

    case GRIP_PREHENSER:
        break;

    case RELEASE_PREHENSER:
        break;

    case ACTIVATE_PID_DEBUG:
        break;

    case STORE_PID_VALUES:
        break;

    case REQUEST_PID_VALUES:
        break;

    default:
        break;

    }


    if(!m_baseStationDataStream->commitTransaction())
    {
        return;
    }


}

void BaseStationHandler::handleCommand_Ping()
{
    int v_pingIndex;

    *m_baseStationDataStream >> v_pingIndex;

    qDebug() << "PING : " << v_pingIndex << "\n";

    QByteArray v_toBaseStation;
    QDataStream v_out(&v_toBaseStation, QIODevice::WriteOnly);
    v_out.setVersion(QDataStream::Qt_5_10);

    v_out << (char) PING_ACK
          << v_pingIndex;

    m_tcpSocket->write(v_toBaseStation);

}
