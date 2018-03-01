#ifndef ROBOTMANAGER_H
#define ROBOTMANAGER_H


#include <QString>
#include <QTcpSocket>
#include <QDataStream>


#include "robotreceivestatemachine.h"
#include "pidvaluesstruct.h"





class RobotManager : public QObject
{

    Q_OBJECT

public:

    enum ROBOT_CONNECTION{
        SUCCES,
        FAILURE
    };

    RobotManager(QObject* p_parent = nullptr);
    virtual ~RobotManager();

    bool isConnectedToRobot() const;
    void connectToRobot(QString p_ipAdress, int p_port);

//commandes
    bool sendCommand_Ping(int p_index);                                                   //demande de ping
    bool sendCommand_Displacement_X(float p_cm, float p_vmax = 0.0, float p_amax = 0.0);  //déplacement en X
    bool sendCommand_Displacement_Y(float p_cm, float p_vmax = 0.0, float p_amax = 0.0);  //déplacement en Y
    bool sendCommand_Displacement_R(float p_deg, float p_vmax = 0.0, float p_amax = 0.0); //rotation en degrés
    bool sendCommand_Cancel_Displacement();                                               //cancel un déplacement en cour
    bool sendCommand_Change_LED_State(bool p_on_off);                                     //change l'état de la led de status
    bool sendCommand_Request_Country_Code();                                              //Réclame le code de pays
    bool sendCommand_Tilt_Camera_Left_Right(float p_angle);                               //faire tourner la caméra de gauche à droite
    bool sendCommand_Tilt_Camera_Up_Down(float p_angle);                                  //faire tourner la caméra de haut en bas
    bool sendCommand_Grip_Prehenser();
    bool sendCommand_Release_Prehenser();
    bool sendCommand_Activate_PID_Debug(bool p_activate);
    bool sendCommand_Store_PID_Values(PIDValuesStruct p_pidValues);
    bool sendCommand_Request_PID_Values();

signals:
    void robotConnectionStatus(RobotManager::ROBOT_CONNECTION);


private slots:


    //liés au socket
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError p_socketError);
    void readyRead();

private:
    QObject* m_parent;


    bool     m_isConnectedToRobot;
    QTcpSocket* m_robotTcpSocket;
    RobotReceiveStateMachine m_robotReceiveStateMachine;






    enum TO_ROBOT_COMMAND_ID
    {
        PING                   = 0x01,
        DISPLACEMENT_X         = 0x03,
        DISPLACEMENT_Y         = 0x05,
        DISPLACEMENT_R         = 0x07,
        CANCEL_DISPLACEMENT    = 0x09,
        CHANGE_LED_STATE       = 0x0B,
        REQUEST_COUNTRY_CODE   = 0x0D,
        TILT_CAMERA_LEFT_RIGHT = 0x0F,
        TILT_CAMERA_UP_DOWN    = 0x11,
        GRIP_PREHENSER         = 0x13,
        RELEASE_PREHENSER      = 0x15,
        ACTIVATE_PID_DEBUG     = 0x17,
        STORE_PID_VALUES       = 0x19,
        REQUEST_PID_VALUES     = 0x1B
    };

    enum FROM_ROBOT_COMMAND_ID
    {
        PING_ACK               = 0x02,
        DISPLACEMENT_X_ACK     = 0x04,
        DISPLACEMENT_Y_ACK     = 0x06,
        DISPLACEMENT_R_ACK     = 0x08,

        COUNTRY_CODE           = 0x0E,

        REQUESTED_PID_VALUES   = 0x10,

        PID_OUTPUT             = 0x12
    };

    void handleReply_PingACK();
    void handleReply_Displacement_X_ACK();
    void handleReply_Displacement_Y_ACK();
    void handleReply_Displacement_R_ACK();
    void handleReply_Country_Code();
    void handleReply_Requested_PID_Values();
    void handleReply_PID_Output();

};



#endif // ROBOTMANAGER_H




