#-------------------------------------------------
#
# Project created by QtCreator 2018-01-26T17:14:54
#
#-------------------------------------------------

QT       += core gui gamepad serialport multimedia multimediawidgets

CONFIG   += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Base_Station
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

macx:QT_CONFIG -= no-pkg-config
macx:CONFIG  += link_pkgconfig
macx:PKGCONFIG += opencv

unix:INCLUDEPATH += /usr/local/include
unix:LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    serialmotionsender.cpp \
    gamepadstate.cpp \
    opencvworkerthread.cpp

HEADERS += \
        mainwindow.h \
    serialmotionsender.h \
    gamepadstate.h \
    opencvworkerthread.h

FORMS += \
        mainwindow.ui
