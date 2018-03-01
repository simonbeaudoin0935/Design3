#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T22:04:23
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCV_test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:INCLUDEPATH += /usr/local/include
unix:LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_videoio

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    camera.cpp \
    detecteurzonejeu.cpp \
    detecteurcarres.cpp \
    pidchart.cpp \
    robotmanager.cpp \
    robotreceivestatemachine.cpp

HEADERS += \
        mainwindow.h \
    camera.h \
    define.h \
    detecteurzonejeu.h \
    detecteurcarres.h \
    cameracalibration.h \
    pidchart.h \
    robotmanager.h \
    robotreceivestatemachine.h \
    pidvaluesstruct.h

FORMS += \
        mainwindow.ui
