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

    QByteArray v_data = m_tcpSocket->readAll();

    for(QByteArray::iterator it = v_data.begin(); it != v_data.end(); it++)
    {
        if(m_receiveStateMachine.parseMessage(*it))
        {
            unsigned char v_id = m_receiveStateMachine.getMessageId();


            switch(v_id)
            {
            case PING : handleCommand_Ping();
                    break;

            case DISPLACEMENT_X: handleCommand_Displacement_X();
                break;

            case DISPLACEMENT_Y: handleCommand_Displacement_Y();
                break;

            case DISPLACEMENT_R: handleCommand_Displacement_R();
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


        }
    }





}

void BaseStationHandler::handleCommand_Ping()
{

    QByteArray v_out;
    QByteArray v_data = m_receiveStateMachine.getMessageContent();
    intUnion_t v_union;

    v_union.bytes[0] = v_data.at(0);
    v_union.bytes[1] = v_data.at(1);
    v_union.bytes[2] = v_data.at(2);
    v_union.bytes[3] = v_data.at(3);

    qDebug() << "PING : " << v_union.integer << "\n";

    v_out.append('#')
         .append(PING_ACK)
         .append(0x04)
         .append(v_union.bytes[0])
         .append(v_union.bytes[1])
         .append(v_union.bytes[2])
         .append(v_union.bytes[3])
         .append('.');

    m_tcpSocket->write(v_out);
}

void BaseStationHandler::handleCommand_Displacement_X()
{
    QByteArray data;

    data.append('#')
        .append(DISPLACEMENT_X)
        .append(0x04)
        .append(m_receiveStateMachine.getMessageContent())
        .append('.');

    emit forwardToMotorController(data);
}

void BaseStationHandler::handleCommand_Displacement_Y()
{

}

void BaseStationHandler::handleCommand_Displacement_R()
{

}

void BaseStationHandler::handleCommand_Cancel_Displacement()
{

}

void BaseStationHandler::handleCommand_Change_LED_State()
{

}

void BaseStationHandler::handleCommand_Request_Country_Code()
{

}

void BaseStationHandler::handleCommand_Tilt_Camera_Left_Right()
{

}

void BaseStationHandler::handleCommand_Tilt_Camera_Up_Down()
{

}

void BaseStationHandler::handleCommand_Grip_Prehenser()
{

}

void BaseStationHandler::handleCommand_Release_Prehenser()
{

}

void BaseStationHandler::handleCommand_Activate_PID_Debug()
{

}

void BaseStationHandler::handleCommand_Store_PID_Values()
{

}

void BaseStationHandler::handleCommand_Request_PID_Values()
{

}
