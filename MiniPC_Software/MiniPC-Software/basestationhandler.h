#ifndef BASESTATIONTHREAD_H
#define BASESTATIONTHREAD_H


#include <QtNetwork>

class BaseStationHandler : public QObject
{

    Q_OBJECT

public:
    explicit BaseStationHandler(QObject* p_parent = nullptr);
    virtual ~BaseStationHandler();

private slots:

    void incomingConnection();
    void readyRead();

private:

    QObject* m_parent;

    QTcpServer* m_tcpServer;
    QTcpSocket* m_tcpSocket;
    QDataStream* m_baseStationDataStream;

    void handleCommand_Ping();
    void handleCommand_Displacement_X();
    void handleCommand_Displacement_Y();
    void handleCommand_Displacement_R();
    void handleCommand_Cancel_Displacement();
    void handleCommand_Change_LED_State();
    void handleCommand_Request_Country_Code();
    void handleCommand_Tilt_Camera_Left_Right();
    void handleCommand_Tilt_Camera_Up_Down();
    void handleCommand_Grip_Prehenser();
    void handleCommand_Release_Prehenser();
    void handleCommand_Activate_PID_Debug();
    void handleCommand_Store_PID_Values();
    void handleCommand_Request_PID_Values();


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

};

#endif // BASESTATIONTHREAD_H
