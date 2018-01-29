/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QProgressBar *progressBar_2;
    QDial *dial_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLCDNumber *lcdNumber_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QDial *dial;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLCDNumber *lcdNumber_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QProgressBar *progressBar_3;
    QDial *dial_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLCDNumber *lcdNumber_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QProgressBar *progressBar_4;
    QDial *dial_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLCDNumber *lcdNumber;
    QFrame *line_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QComboBox *comboBox_Camera_Selector;
    QPushButton *pushButton_Camera_Scan;
    QPushButton *pushButton_Camera_Connect;
    QPushButton *pushButton_Camera_Disconnect;
    QTextBrowser *textBrowser_Camera_Descriptor;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QComboBox *comboBox_Serial_Selector;
    QPushButton *pushButton_Serial_Scan;
    QPushButton *pushButton_Serial_Connect;
    QPushButton *pushButton_Serial_Disconnect;
    QPushButton *pushButton_Serial_Send1;
    QTextBrowser *textBrowser_Serial_Description;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_Gamepad_Connect;
    QPushButton *pushButton_Gamepad_Disconnect;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_6;
    QProgressBar *progressBar_Left_Stick_X;
    QProgressBar *progressBar_Left_Stick_Y;
    QProgressBar *progressBar_Right_Stick_X;
    QProgressBar *progressBar_Right_Stick_Y;
    QProgressBar *progressBar_Left_Trigger;
    QProgressBar *progressBar_Right_Trigger;
    QHBoxLayout *horizontalLayout_12;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Gamepad_DOWN;
    QPushButton *pushButton_Gamepad_UP;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_15;
    QPushButton *pushButton_Gamepad_RIGHT;
    QPushButton *pushButton_Gamepad_LEFT;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_Gamepad_A;
    QPushButton *pushButton_Gamepad_X;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_Gamepad_B;
    QPushButton *pushButton_Gamepad_Y;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_Gamepad_WHITE;
    QPushButton *pushButton_Gamepad_BLACK;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_Gamepad_LEFT_STICK;
    QPushButton *pushButton_Gamepad_RIGHT_STICK;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_Gamepad_START;
    QPushButton *pushButton_Gamepad_BACK;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(589, 518);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 223, 288));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        progressBar_2 = new QProgressBar(gridLayoutWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(24);

        verticalLayout_2->addWidget(progressBar_2);

        dial_2 = new QDial(gridLayoutWidget);
        dial_2->setObjectName(QStringLiteral("dial_2"));

        verticalLayout_2->addWidget(dial_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        lcdNumber_4 = new QLCDNumber(gridLayoutWidget);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));

        horizontalLayout_5->addWidget(lcdNumber_4);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        dial = new QDial(gridLayoutWidget);
        dial->setObjectName(QStringLiteral("dial"));

        verticalLayout->addWidget(dial);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lcdNumber_3 = new QLCDNumber(gridLayoutWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));

        horizontalLayout_4->addWidget(lcdNumber_3);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        progressBar_3 = new QProgressBar(gridLayoutWidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setValue(24);

        verticalLayout_3->addWidget(progressBar_3);

        dial_3 = new QDial(gridLayoutWidget);
        dial_3->setObjectName(QStringLiteral("dial_3"));

        verticalLayout_3->addWidget(dial_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lcdNumber_2 = new QLCDNumber(gridLayoutWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout_3->addWidget(lcdNumber_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        progressBar_4 = new QProgressBar(gridLayoutWidget);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setValue(24);

        verticalLayout_4->addWidget(progressBar_4);

        dial_4 = new QDial(gridLayoutWidget);
        dial_4->setObjectName(QStringLiteral("dial_4"));

        verticalLayout_4->addWidget(dial_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lcdNumber = new QLCDNumber(gridLayoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 2, 2, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_13 = new QVBoxLayout(tab_4);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        comboBox_Camera_Selector = new QComboBox(tab_4);
        comboBox_Camera_Selector->setObjectName(QStringLiteral("comboBox_Camera_Selector"));

        verticalLayout_12->addWidget(comboBox_Camera_Selector);

        pushButton_Camera_Scan = new QPushButton(tab_4);
        pushButton_Camera_Scan->setObjectName(QStringLiteral("pushButton_Camera_Scan"));

        verticalLayout_12->addWidget(pushButton_Camera_Scan);

        pushButton_Camera_Connect = new QPushButton(tab_4);
        pushButton_Camera_Connect->setObjectName(QStringLiteral("pushButton_Camera_Connect"));

        verticalLayout_12->addWidget(pushButton_Camera_Connect);

        pushButton_Camera_Disconnect = new QPushButton(tab_4);
        pushButton_Camera_Disconnect->setObjectName(QStringLiteral("pushButton_Camera_Disconnect"));

        verticalLayout_12->addWidget(pushButton_Camera_Disconnect);

        textBrowser_Camera_Descriptor = new QTextBrowser(tab_4);
        textBrowser_Camera_Descriptor->setObjectName(QStringLiteral("textBrowser_Camera_Descriptor"));

        verticalLayout_12->addWidget(textBrowser_Camera_Descriptor);


        verticalLayout_13->addLayout(verticalLayout_12);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_11 = new QVBoxLayout(tab_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        comboBox_Serial_Selector = new QComboBox(tab_2);
        comboBox_Serial_Selector->setObjectName(QStringLiteral("comboBox_Serial_Selector"));

        verticalLayout_10->addWidget(comboBox_Serial_Selector);

        pushButton_Serial_Scan = new QPushButton(tab_2);
        pushButton_Serial_Scan->setObjectName(QStringLiteral("pushButton_Serial_Scan"));

        verticalLayout_10->addWidget(pushButton_Serial_Scan);

        pushButton_Serial_Connect = new QPushButton(tab_2);
        pushButton_Serial_Connect->setObjectName(QStringLiteral("pushButton_Serial_Connect"));

        verticalLayout_10->addWidget(pushButton_Serial_Connect);

        pushButton_Serial_Disconnect = new QPushButton(tab_2);
        pushButton_Serial_Disconnect->setObjectName(QStringLiteral("pushButton_Serial_Disconnect"));

        verticalLayout_10->addWidget(pushButton_Serial_Disconnect);

        pushButton_Serial_Send1 = new QPushButton(tab_2);
        pushButton_Serial_Send1->setObjectName(QStringLiteral("pushButton_Serial_Send1"));

        verticalLayout_10->addWidget(pushButton_Serial_Send1);

        textBrowser_Serial_Description = new QTextBrowser(tab_2);
        textBrowser_Serial_Description->setObjectName(QStringLiteral("textBrowser_Serial_Description"));

        verticalLayout_10->addWidget(textBrowser_Serial_Description);


        verticalLayout_11->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_9 = new QVBoxLayout(tab_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        pushButton_Gamepad_Connect = new QPushButton(tab_3);
        pushButton_Gamepad_Connect->setObjectName(QStringLiteral("pushButton_Gamepad_Connect"));
        pushButton_Gamepad_Connect->setEnabled(true);
        pushButton_Gamepad_Connect->setCheckable(false);

        horizontalLayout_13->addWidget(pushButton_Gamepad_Connect);

        pushButton_Gamepad_Disconnect = new QPushButton(tab_3);
        pushButton_Gamepad_Disconnect->setObjectName(QStringLiteral("pushButton_Gamepad_Disconnect"));
        pushButton_Gamepad_Disconnect->setEnabled(false);

        horizontalLayout_13->addWidget(pushButton_Gamepad_Disconnect);


        verticalLayout_9->addLayout(horizontalLayout_13);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        progressBar_Left_Stick_X = new QProgressBar(tab_3);
        progressBar_Left_Stick_X->setObjectName(QStringLiteral("progressBar_Left_Stick_X"));
        progressBar_Left_Stick_X->setEnabled(false);
        progressBar_Left_Stick_X->setValue(50);

        verticalLayout_6->addWidget(progressBar_Left_Stick_X);

        progressBar_Left_Stick_Y = new QProgressBar(tab_3);
        progressBar_Left_Stick_Y->setObjectName(QStringLiteral("progressBar_Left_Stick_Y"));
        progressBar_Left_Stick_Y->setEnabled(false);
        progressBar_Left_Stick_Y->setValue(50);

        verticalLayout_6->addWidget(progressBar_Left_Stick_Y);

        progressBar_Right_Stick_X = new QProgressBar(tab_3);
        progressBar_Right_Stick_X->setObjectName(QStringLiteral("progressBar_Right_Stick_X"));
        progressBar_Right_Stick_X->setEnabled(false);
        progressBar_Right_Stick_X->setValue(50);

        verticalLayout_6->addWidget(progressBar_Right_Stick_X);

        progressBar_Right_Stick_Y = new QProgressBar(tab_3);
        progressBar_Right_Stick_Y->setObjectName(QStringLiteral("progressBar_Right_Stick_Y"));
        progressBar_Right_Stick_Y->setEnabled(false);
        progressBar_Right_Stick_Y->setValue(50);

        verticalLayout_6->addWidget(progressBar_Right_Stick_Y);

        progressBar_Left_Trigger = new QProgressBar(tab_3);
        progressBar_Left_Trigger->setObjectName(QStringLiteral("progressBar_Left_Trigger"));
        progressBar_Left_Trigger->setEnabled(false);
        progressBar_Left_Trigger->setValue(0);

        verticalLayout_6->addWidget(progressBar_Left_Trigger);

        progressBar_Right_Trigger = new QProgressBar(tab_3);
        progressBar_Right_Trigger->setObjectName(QStringLiteral("progressBar_Right_Trigger"));
        progressBar_Right_Trigger->setEnabled(false);
        progressBar_Right_Trigger->setValue(0);

        verticalLayout_6->addWidget(progressBar_Right_Trigger);


        horizontalLayout_6->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_Gamepad_DOWN = new QPushButton(tab_3);
        pushButton_Gamepad_DOWN->setObjectName(QStringLiteral("pushButton_Gamepad_DOWN"));
        pushButton_Gamepad_DOWN->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Gamepad_DOWN, 3, 1, 1, 1);

        pushButton_Gamepad_UP = new QPushButton(tab_3);
        pushButton_Gamepad_UP->setObjectName(QStringLiteral("pushButton_Gamepad_UP"));
        pushButton_Gamepad_UP->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Gamepad_UP, 0, 1, 1, 1);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 0, 0, 1, 1);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 3, 2, 1, 1);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 0, 2, 1, 1);

        pushButton_Gamepad_RIGHT = new QPushButton(tab_3);
        pushButton_Gamepad_RIGHT->setObjectName(QStringLiteral("pushButton_Gamepad_RIGHT"));
        pushButton_Gamepad_RIGHT->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Gamepad_RIGHT, 2, 2, 1, 1);

        pushButton_Gamepad_LEFT = new QPushButton(tab_3);
        pushButton_Gamepad_LEFT->setObjectName(QStringLiteral("pushButton_Gamepad_LEFT"));
        pushButton_Gamepad_LEFT->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Gamepad_LEFT, 2, 0, 1, 1);

        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 3, 0, 1, 1);


        horizontalLayout_12->addLayout(gridLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_Gamepad_A = new QPushButton(tab_3);
        pushButton_Gamepad_A->setObjectName(QStringLiteral("pushButton_Gamepad_A"));
        pushButton_Gamepad_A->setEnabled(false);

        horizontalLayout_7->addWidget(pushButton_Gamepad_A);

        pushButton_Gamepad_X = new QPushButton(tab_3);
        pushButton_Gamepad_X->setObjectName(QStringLiteral("pushButton_Gamepad_X"));
        pushButton_Gamepad_X->setEnabled(false);

        horizontalLayout_7->addWidget(pushButton_Gamepad_X);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_Gamepad_B = new QPushButton(tab_3);
        pushButton_Gamepad_B->setObjectName(QStringLiteral("pushButton_Gamepad_B"));
        pushButton_Gamepad_B->setEnabled(false);

        horizontalLayout_8->addWidget(pushButton_Gamepad_B);

        pushButton_Gamepad_Y = new QPushButton(tab_3);
        pushButton_Gamepad_Y->setObjectName(QStringLiteral("pushButton_Gamepad_Y"));
        pushButton_Gamepad_Y->setEnabled(false);

        horizontalLayout_8->addWidget(pushButton_Gamepad_Y);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_Gamepad_WHITE = new QPushButton(tab_3);
        pushButton_Gamepad_WHITE->setObjectName(QStringLiteral("pushButton_Gamepad_WHITE"));
        pushButton_Gamepad_WHITE->setEnabled(false);

        horizontalLayout_9->addWidget(pushButton_Gamepad_WHITE);

        pushButton_Gamepad_BLACK = new QPushButton(tab_3);
        pushButton_Gamepad_BLACK->setObjectName(QStringLiteral("pushButton_Gamepad_BLACK"));
        pushButton_Gamepad_BLACK->setEnabled(false);

        horizontalLayout_9->addWidget(pushButton_Gamepad_BLACK);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_Gamepad_LEFT_STICK = new QPushButton(tab_3);
        pushButton_Gamepad_LEFT_STICK->setObjectName(QStringLiteral("pushButton_Gamepad_LEFT_STICK"));
        pushButton_Gamepad_LEFT_STICK->setEnabled(false);

        horizontalLayout_10->addWidget(pushButton_Gamepad_LEFT_STICK);

        pushButton_Gamepad_RIGHT_STICK = new QPushButton(tab_3);
        pushButton_Gamepad_RIGHT_STICK->setObjectName(QStringLiteral("pushButton_Gamepad_RIGHT_STICK"));
        pushButton_Gamepad_RIGHT_STICK->setEnabled(false);

        horizontalLayout_10->addWidget(pushButton_Gamepad_RIGHT_STICK);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton_Gamepad_START = new QPushButton(tab_3);
        pushButton_Gamepad_START->setObjectName(QStringLiteral("pushButton_Gamepad_START"));
        pushButton_Gamepad_START->setEnabled(false);

        horizontalLayout_11->addWidget(pushButton_Gamepad_START);

        pushButton_Gamepad_BACK = new QPushButton(tab_3);
        pushButton_Gamepad_BACK->setObjectName(QStringLiteral("pushButton_Gamepad_BACK"));
        pushButton_Gamepad_BACK->setEnabled(false);

        horizontalLayout_11->addWidget(pushButton_Gamepad_BACK);


        verticalLayout_7->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_12);


        verticalLayout_9->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Motor 2", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "RPM:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Motor 1", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "RPM:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Motor 3", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "RPM:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Motor 4", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "RPM:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Motors", nullptr));
        pushButton_Camera_Scan->setText(QApplication::translate("MainWindow", "Scan Cameras", nullptr));
        pushButton_Camera_Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Camera_Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Camera Settings", nullptr));
        pushButton_Serial_Scan->setText(QApplication::translate("MainWindow", "Scan", nullptr));
        pushButton_Serial_Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Serial_Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButton_Serial_Send1->setText(QApplication::translate("MainWindow", "Send 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Motor Controller Serial Link", nullptr));
        pushButton_Gamepad_Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Gamepad_Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Left Stick X : ", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Left Stick Y : ", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Right Stick X : ", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Right Stick Y : ", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Left Trigger : ", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Right Trigger : ", nullptr));
        pushButton_Gamepad_DOWN->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        pushButton_Gamepad_UP->setText(QApplication::translate("MainWindow", "UP", nullptr));
        label_16->setText(QString());
        label_17->setText(QString());
        label_15->setText(QString());
        pushButton_Gamepad_RIGHT->setText(QApplication::translate("MainWindow", "RIGHT", nullptr));
        pushButton_Gamepad_LEFT->setText(QApplication::translate("MainWindow", "LEFT", nullptr));
        label_18->setText(QString());
        pushButton_Gamepad_A->setText(QApplication::translate("MainWindow", "A", nullptr));
        pushButton_Gamepad_X->setText(QApplication::translate("MainWindow", "X", nullptr));
        pushButton_Gamepad_B->setText(QApplication::translate("MainWindow", "B", nullptr));
        pushButton_Gamepad_Y->setText(QApplication::translate("MainWindow", "Y", nullptr));
        pushButton_Gamepad_WHITE->setText(QApplication::translate("MainWindow", "WHITE", nullptr));
        pushButton_Gamepad_BLACK->setText(QApplication::translate("MainWindow", "BLACK", nullptr));
        pushButton_Gamepad_LEFT_STICK->setText(QApplication::translate("MainWindow", "LEFT STICK", nullptr));
        pushButton_Gamepad_RIGHT_STICK->setText(QApplication::translate("MainWindow", "RIGHT STICK", nullptr));
        pushButton_Gamepad_START->setText(QApplication::translate("MainWindow", "START", nullptr));
        pushButton_Gamepad_BACK->setText(QApplication::translate("MainWindow", "BACK", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Gamepad Config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
