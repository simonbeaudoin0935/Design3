#ifndef OPENCVWORKERTHREAD_H
#define OPENCVWORKERTHREAD_H

#include <QThread>

class OpencvWorkerThread : public QThread
{
public:
    OpencvWorkerThread();
    void run() Q_DECL_OVERRIDE;

   void setImageToCompute(QString p_imagePath);

private:

   QString m_imagePath;
};

#endif // OPENCVWORKERTHREAD_H
