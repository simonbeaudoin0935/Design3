#ifndef SERIALMOTIONSENDER_H
#define SERIALMOTIONSENDER_H

#include <QThread>



class SerialMotionSender : public QThread
{

    Q_OBJECT

public:
    SerialMotionSender(unsigned int p_sendIntervalMS = 100);

    void run() Q_DECL_OVERRIDE;

    void stopSending();
    void startSending();


signals:

    void timeout();

private:
    unsigned int m_sendIntervalMS;
    bool m_continueSenting;
};

#endif // SERIALMOTIONSENDER_H
