#include "robotmanager.h"
#include <QBuffer>
#include <QMessageBox>



RobotManager::RobotManager(QObject* p_parent):
    m_parent(p_parent),
    m_isConnectedToRobot(false),
    m_robotTcpSocket(new QTcpSocket(this))


{



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

RobotManager::~RobotManager()
{

}


//robot tcp socket slots

void RobotManager::connected()
{
    m_isConnectedToRobot = true;
    emit robotConnectionStatus(ROBOT_CONNECTION::SUCCES);
   // this->start();

}

void RobotManager::disconnected()
{
    m_isConnectedToRobot = false;
    emit robotConnectionStatus(ROBOT_CONNECTION::FAILURE);
}

void RobotManager::error(QAbstractSocket::SocketError p_socketError)
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

void RobotManager::readyRead()
{
    QByteArray v_data = m_robotTcpSocket->readAll();

    for(QByteArray::iterator it = v_data.begin(); it != v_data.end(); it++)
    {
        if(m_robotReceiveStateMachine.parseMessage(*it))
        {
            unsigned char v_messageID = m_robotReceiveStateMachine.getMessageId();

            switch(v_messageID)
            {
            case PING_ACK : handleReply_PingACK(); break;

            case DISPLACEMENT_X_ACK : handleReply_Displacement_X_ACK(); break;

            case DISPLACEMENT_Y_ACK : handleReply_Displacement_Y_ACK(); break;

            case DISPLACEMENT_R_ACK : handleReply_Displacement_R_ACK(); break;

            case COUNTRY_CODE : handleReply_Country_Code(); break;

            case REQUESTED_PID_VALUES : handleReply_Requested_PID_Values(); break;

            case PID_OUTPUT : handleReply_PID_Output(); break;

            default : break;


            }
        }
    }

}



//public functions

bool RobotManager::isConnectedToRobot() const
{
    return m_isConnectedToRobot;
}

void RobotManager::connectToRobot(QString p_ipAdress, int p_port)
{
    m_isConnectedToRobot = false;

    m_robotTcpSocket->abort();

    m_robotTcpSocket->connectToHost(p_ipAdress, p_port);
}



//Commandes




bool RobotManager::sendCommand_Ping(int p_index)
{
    if(m_isConnectedToRobot)
    {
        //qDebug() << "PING : " << p_index << "\n";
        QByteArray v_robotMsg;

        intUnion_t v_union;

        v_union.integer = p_index;

        v_robotMsg.append('#')
                  .append(PING)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_X(float p_cm, float p_vmax, float p_amax)
{
    Q_UNUSED(p_vmax)
    Q_UNUSED(p_amax)

    if(m_isConnectedToRobot)
    {
        qDebug() << "DISPLACEMENT_X : " << p_cm << "\n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;

        v_union.floating = p_cm;

        v_robotMsg.append('#')
                  .append(DISPLACEMENT_X)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_Y(float p_cm, float p_vmax, float p_amax)
{
    Q_UNUSED(p_vmax)
    Q_UNUSED(p_amax)

    if(m_isConnectedToRobot)
    {
        qDebug() << "DISPLACEMENT_Y : " << p_cm << "\n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;

        v_union.floating = p_cm;

        v_robotMsg.append('#')
                  .append(DISPLACEMENT_Y)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_R(float p_deg, float p_vmax, float p_amax)
{
    Q_UNUSED(p_vmax)
    Q_UNUSED(p_amax)

    if(m_isConnectedToRobot)
    {
        qDebug() << "DISPLACEMENT_R : " << p_deg << "\n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;

        v_union.floating = p_deg;

        v_robotMsg.append('#')
                  .append(DISPLACEMENT_R)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Cancel_Displacement()
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "CANCEL_DISPLACEMENT\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(CANCEL_DISPLACEMENT)
                  .append((char)0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Change_LED_State(bool p_on_off)
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "CHANGE_LED_STATE\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(CHANGE_LED_STATE)
                  .append(0x01)
                  .append(p_on_off ? 0x01 : 0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Request_Country_Code()
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "REQUEST_COUNTRY_CODE\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(REQUEST_COUNTRY_CODE)
                  .append((char)0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Tilt_Camera_Left_Right(float p_angle)
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "TILT_CAMERA_LEFT_RIGHT : " << p_angle << "\n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;

        v_union.floating = p_angle;

        v_robotMsg.append('#')
                  .append(TILT_CAMERA_LEFT_RIGHT)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Tilt_Camera_Up_Down(float p_angle)
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "TILT_CAMERA_UP_DOWN\n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;

        v_union.floating = p_angle;

        v_robotMsg.append('#')
                  .append(TILT_CAMERA_UP_DOWN)
                  .append(0x04)
                  .append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Grip_Prehenser()
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "GRIP_PREHENSER\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(GRIP_PREHENSER)
                  .append((char)0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Release_Prehenser()
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "RELEASE_PREHENSER\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(RELEASE_PREHENSER)
                  .append((char)0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Activate_PID_Debug(bool p_activate)
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "ACTIVATE_PID_DEBUG : " << p_activate << "\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(ACTIVATE_PID_DEBUG)
                  .append(0x01)
                  .append(p_activate ? 0x01 : 0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Store_PID_Values(PIDValuesStruct p_pidValues)
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "STORE_PID_VALUES \n";
        QByteArray v_robotMsg;

        floatUnion_t v_union;



        v_robotMsg.append('#')
                  .append(STORE_PID_VALUES)
                  .append(0x74);
        //position x
        v_union.floating = p_pidValues.position_X_PKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_X_PKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_X_PKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_X_Vmax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_X_Amax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //position y

        v_union.floating = p_pidValues.position_Y_PKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_Y_PKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_Y_PKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_Y_Vmax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_Y_Amax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //position r

        v_union.floating = p_pidValues.position_R_PKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_R_PKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_R_PKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_R_Vmax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.position_R_Amax;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //motor 1

        v_union.floating = p_pidValues.motor_1_VKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_1_VKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_1_VKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //motor 2

        v_union.floating = p_pidValues.motor_2_VKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_2_VKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_2_VKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //motor 3
        v_union.floating = p_pidValues.motor_3_VKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_3_VKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_3_VKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //motor 4

        v_union.floating = p_pidValues.motor_4_VKp;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_4_VKi;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        v_union.floating = p_pidValues.motor_4_VKd;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //dt

        v_union.floating = p_pidValues.dt;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3]);

        //wheel diameter

        v_union.floating = p_pidValues.wheel_diameter;
        v_robotMsg.append(v_union.bytes[0])
                  .append(v_union.bytes[1])
                  .append(v_union.bytes[2])
                  .append(v_union.bytes[3])
                  .append('.');




        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;











}

bool RobotManager::sendCommand_Request_PID_Values()
{
    if(m_isConnectedToRobot)
    {
        qDebug() << "REQUEST_PID_VALUES\n";
        QByteArray v_robotMsg;


        v_robotMsg.append('#')
                  .append(REQUEST_PID_VALUES)
                  .append((char)0x00)
                  .append('.');

        m_robotTcpSocket->write(v_robotMsg);
    }

    return m_isConnectedToRobot;
}





void RobotManager::handleReply_PingACK()
{
    intUnion_t v_intUnion;

    QByteArray v_content = m_robotReceiveStateMachine.getMessageContent();

    v_intUnion.bytes[0] = v_content.at(0);
    v_intUnion.bytes[1] = v_content.at(1);
    v_intUnion.bytes[2] = v_content.at(2);
    v_intUnion.bytes[3] = v_content.at(3);

    qDebug() << "PING ACK : " << v_intUnion.integer << "\n";
}

void RobotManager::handleReply_Displacement_X_ACK()
{

}

void RobotManager::handleReply_Displacement_Y_ACK()
{

}

void RobotManager::handleReply_Displacement_R_ACK()
{

}

void RobotManager::handleReply_Country_Code()
{

}

void RobotManager::handleReply_Requested_PID_Values()
{
    PIDValuesStruct pid;
    floatUnion_t un;
    QByteArray data = m_robotReceiveStateMachine.getMessageContent();

    int i = 0;

    //position X
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_X_PKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_X_PKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_X_PKd = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_X_Vmax = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_X_Amax = un.floating;


    //position Y
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_Y_PKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_Y_PKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_Y_PKd = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_Y_Vmax = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_Y_Amax = un.floating;



    //position R
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_R_PKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_R_PKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_R_PKd = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_R_Vmax = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.position_R_Amax = un.floating;


    //motor 1
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_1_VKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_1_VKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_1_VKd = un.floating;


    //motor 2
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_2_VKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_2_VKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_2_VKd = un.floating;


    //motor 13
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_3_VKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_3_VKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_3_VKd = un.floating;



    //motor 4
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_4_VKp = un.floating;


    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_4_VKi = un.floating;

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.motor_4_VKd = un.floating;


    //dt
    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.dt = un.floating;

    //wheel diameter

    un.bytes[0] = data.at(i); i++;
    un.bytes[1] = data.at(i); i++;
    un.bytes[2] = data.at(i); i++;
    un.bytes[3] = data.at(i); i++;
    pid.wheel_diameter = un.floating;

    emit PIDValuesReceived(pid);

}

void RobotManager::handleReply_PID_Output()
{
    emit PIDOutputReceived(m_robotReceiveStateMachine.getMessageContent());
}



















































