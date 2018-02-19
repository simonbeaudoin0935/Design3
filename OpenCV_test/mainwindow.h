#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

#include "camera.h"
#include "detecteurcarres.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void dt_timeout();

private slots:

    void on_actionInfo_triggered();

//Slots des widgets de la tab des settings de la camera
    void on_pushButton_Scan_Cameras_clicked();

    void on_listWidget_Connected_Cameras_itemSelectionChanged();

    void on_pushButton_Connect_Camera_clicked();

    void on_pushButton_Disconnect_Camera_clicked();

//slots des widghets de la tab du jeu

    void on_pushButton_Start_Game_clicked();

private:

//Qt library objects
    Ui::MainWindow* ui;
    QTimer*         m_timer;
    QTime*          m_time;

//custom objetc
    Camera*         m_camera;
    DetecteurCarres* m_detecteurCarres;
    bool            m_isGameStarted;
};

#endif // MAINWINDOW_H
