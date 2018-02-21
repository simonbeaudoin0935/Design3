#ifndef ROBOTMANAGER_H
#define ROBOTMANAGER_H

#include <QThread>
#include <QString>
#include <QTcpSocket>
#include <QDataStream>

enum ROBOT_CONNECTION{
    SUCCES,
    FAILURE
};




class RobotManagerThread : public QThread
{
    Q_OBJECT

public:
    RobotManagerThread(QObject* p_parent = nullptr);
    virtual ~RobotManagerThread();

    bool isConnectedToRobot() const;

    void connectToRobot(QString p_ipAdress, int p_port);


    bool sendCommand_Ping(int p_index);
    bool sendCommand_XDisplacement(float p_displacementCM);
    bool sendCommand_Pixmap(QPixmap &img);

protected:
    void run();

signals:
    void robotConnectionStatus(ROBOT_CONNECTION p_connectionStatus);


private slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError p_socketError);
    void readyRead();

private:
    QObject* m_parent;

    bool     m_isConnectedToRobot;
    QTcpSocket* m_robotTcpSocket;
    QDataStream m_robotDataStream;

};

#endif // ROBOTMANAGER_H




