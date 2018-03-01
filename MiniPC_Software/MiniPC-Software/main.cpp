#include "mainthread.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainThread v_mainThread;

    v_mainThread.start();

    return a.exec();
}
