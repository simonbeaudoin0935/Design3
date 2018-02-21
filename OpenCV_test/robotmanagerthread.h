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
    QDataStream m_robotInputDataStream;

};

#endif // ROBOTMANAGER_H




