#include "robotmanager.h"
#include <QBuffer>
#include <QMessageBox>



RobotManager::RobotManager(QObject* p_parent):
    m_parent(p_parent),
    m_isConnectedToRobot(false),
    m_robotTcpSocket(new QTcpSocket(this)),
    m_robotReceiveStateMachine(new RobotReceiveStateMachine)
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
    QByteArray v_receivedData = m_robotTcpSocket->readAll();

    for(auto v_it = v_receivedData.begin(); v_it != v_receivedData.end(); v_it++)
    {
        if(m_robotReceiveStateMachine->parseMessage(*v_it))
        {

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
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)PING;
        out << p_index;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_X(float p_cm, float p_vmax, float p_amax)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)DISPLACEMENT_X
            << p_cm
            << p_vmax
            << p_amax;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_Y(float p_cm, float p_vmax, float p_amax)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)DISPLACEMENT_Y
            << p_cm
            << p_vmax
            << p_amax;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Displacement_R(float p_deg, float p_vmax, float p_amax)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)DISPLACEMENT_R
            << p_deg
            << p_vmax
            << p_amax;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Cancel_Displacement()
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)CANCEL_DISPLACEMENT;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Change_LED_State(bool p_on_off)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)CHANGE_LED_STATE
            << p_on_off;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Request_Country_Code()
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)REQUEST_COUNTRY_CODE;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Tilt_Camera_Left_Right(float p_angle)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)TILT_CAMERA_LEFT_RIGHT
            << p_angle;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Tilt_Camera_Up_Down(float p_angle)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)TILT_CAMERA_UP_DOWN
            << p_angle;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Grip_Prehenser()
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)GRIP_PREHENSER;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Release_Prehenser()
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)RELEASE_PREHENSER;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Activate_PID_Debug(bool p_activate)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)ACTIVATE_PID_DEBUG
            << p_activate;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Store_PID_Values(PIDValuesStruct p_pidValues)
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)STORE_PID_VALUES

            << p_pidValues.position_X_PKp
            << p_pidValues.position_X_PKi
            << p_pidValues.position_X_PKd
            << p_pidValues.position_X_Vmax
            << p_pidValues.position_X_Amax

            << p_pidValues.position_Y_PKp
            << p_pidValues.position_Y_PKi
            << p_pidValues.position_Y_PKd
            << p_pidValues.position_Y_Vmax
            << p_pidValues.position_Y_Amax

            << p_pidValues.position_R_PKp
            << p_pidValues.position_R_PKi
            << p_pidValues.position_R_PKd
            << p_pidValues.position_R_Vmax
            << p_pidValues.position_R_Amax

            << p_pidValues.motor_1_VKp
            << p_pidValues.motor_1_VKi
            << p_pidValues.motor_1_VKd

            << p_pidValues.motor_2_VKp
            << p_pidValues.motor_2_VKi
            << p_pidValues.motor_2_VKd

            << p_pidValues.motor_3_VKp
            << p_pidValues.motor_3_VKi
            << p_pidValues.motor_3_VKd

            << p_pidValues.motor_4_VKp
            << p_pidValues.motor_4_VKi
            << p_pidValues.motor_4_VKd

            << p_pidValues.dt

            << p_pidValues.wheel_diameter;


        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

bool RobotManager::sendCommand_Request_PID_Values()
{
    if(m_isConnectedToRobot)
    {
        QByteArray v_robotCommand;
        QDataStream out(&v_robotCommand, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (char)REQUEST_PID_VALUES;

        m_robotTcpSocket->write(v_robotCommand);
    }

    return m_isConnectedToRobot;
}

























































