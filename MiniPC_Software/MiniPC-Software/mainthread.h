#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QThread>

#include "basestationhandler.h"
#include "motorcontrollerhandler.h"

class MainThread : public QThread
{

    Q_OBJECT

public:
    explicit MainThread();
    virtual ~MainThread();

    void run() Q_DECL_OVERRIDE ;

private:
    BaseStationHandler* m_baseStationHandler;
    MotorControllerHandler* m_motorControllerHandler;
};

#endif // MAINTHREAD_H
