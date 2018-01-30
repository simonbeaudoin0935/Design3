#ifndef OPENCVWORKERTHREAD_H
#define OPENCVWORKERTHREAD_H

#include <QThread>

class OpencvWorkerThread : public QThread
{
public:
    OpencvWorkerThread();
    void run() Q_DECL_OVERRIDE;


};

#endif // OPENCVWORKERTHREAD_H
