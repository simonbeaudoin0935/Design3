/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QAction *actionInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_View;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *v_layout_Whole_Game_View;
    QHBoxLayout *h_layout_Instruments_Game_View;
    QPushButton *pushButton_Start_Game;
    QLCDNumber *lcdNumber_Elapsed_Time;
    QLabel *label_Country;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QLabel *label_Computed_Image;
    QWidget *tab_Camera_Settings;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_choix_Table;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_Connected_Cameras;
    QTextBrowser *textBrowser_Description_Camera;
    QPushButton *pushButton_Scan_Cameras;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Connect_Camera;
    QPushButton *pushButton_Disconnect_Camera;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Connect_Robot;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_PLT_3105;
    QRadioButton *radioButton_PLT_3109;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *spinBox_Robot_Number;
    QSpinBox *spinBox_Robot_Port;
    QMenuBar *menuBar;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(763, 657);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_View = new QWidget();
        tab_View->setObjectName(QStringLiteral("tab_View"));
        verticalLayout_2 = new QVBoxLayout(tab_View);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        v_layout_Whole_Game_View = new QVBoxLayout();
        v_layout_Whole_Game_View->setSpacing(6);
        v_layout_Whole_Game_View->setObjectName(QStringLiteral("v_layout_Whole_Game_View"));
        h_layout_Instruments_Game_View = new QHBoxLayout();
        h_layout_Instruments_Game_View->setSpacing(6);
        h_layout_Instruments_Game_View->setObjectName(QStringLiteral("h_layout_Instruments_Game_View"));
        pushButton_Start_Game = new QPushButton(tab_View);
        pushButton_Start_Game->setObjectName(QStringLiteral("pushButton_Start_Game"));

        h_layout_Instruments_Game_View->addWidget(pushButton_Start_Game);

        lcdNumber_Elapsed_Time = new QLCDNumber(tab_View);
        lcdNumber_Elapsed_Time->setObjectName(QStringLiteral("lcdNumber_Elapsed_Time"));
        lcdNumber_Elapsed_Time->setSmallDecimalPoint(true);
        lcdNumber_Elapsed_Time->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Elapsed_Time->setProperty("intValue", QVariant(0));

        h_layout_Instruments_Game_View->addWidget(lcdNumber_Elapsed_Time);

        label_Country = new QLabel(tab_View);
        label_Country->setObjectName(QStringLiteral("label_Country"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Country->sizePolicy().hasHeightForWidth());
        label_Country->setSizePolicy(sizePolicy);

        h_layout_Instruments_Game_View->addWidget(label_Country);

        label = new QLabel(tab_View);
        label->setObjectName(QStringLiteral("label"));

        h_layout_Instruments_Game_View->addWidget(label);


        v_layout_Whole_Game_View->addLayout(h_layout_Instruments_Game_View);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(tab_View);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        checkBox = new QCheckBox(tab_View);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        checkBox_2 = new QCheckBox(tab_View);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_5->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(tab_View);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_5->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(tab_View);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_5->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(tab_View);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_5->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(tab_View);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout_5->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(tab_View);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_5->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(tab_View);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_5->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(tab_View);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        horizontalLayout_5->addWidget(checkBox_9);


        v_layout_Whole_Game_View->addLayout(horizontalLayout_5);

        label_Computed_Image = new QLabel(tab_View);
        label_Computed_Image->setObjectName(QStringLiteral("label_Computed_Image"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Computed_Image->sizePolicy().hasHeightForWidth());
        label_Computed_Image->setSizePolicy(sizePolicy1);

        v_layout_Whole_Game_View->addWidget(label_Computed_Image);


        verticalLayout_2->addLayout(v_layout_Whole_Game_View);

        tabWidget->addTab(tab_View, QString());
        tab_Camera_Settings = new QWidget();
        tab_Camera_Settings->setObjectName(QStringLiteral("tab_Camera_Settings"));
        verticalLayout_8 = new QVBoxLayout(tab_Camera_Settings);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(tab_Camera_Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_2);

        comboBox_choix_Table = new QComboBox(tab_Camera_Settings);
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->addItem(QString());
        comboBox_choix_Table->setObjectName(QStringLiteral("comboBox_choix_Table"));

        horizontalLayout_3->addWidget(comboBox_choix_Table);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget_Connected_Cameras = new QListWidget(tab_Camera_Settings);
        listWidget_Connected_Cameras->setObjectName(QStringLiteral("listWidget_Connected_Cameras"));

        horizontalLayout->addWidget(listWidget_Connected_Cameras);

        textBrowser_Description_Camera = new QTextBrowser(tab_Camera_Settings);
        textBrowser_Description_Camera->setObjectName(QStringLiteral("textBrowser_Description_Camera"));

        horizontalLayout->addWidget(textBrowser_Description_Camera);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton_Scan_Cameras = new QPushButton(tab_Camera_Settings);
        pushButton_Scan_Cameras->setObjectName(QStringLiteral("pushButton_Scan_Cameras"));

        verticalLayout_3->addWidget(pushButton_Scan_Cameras);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_Connect_Camera = new QPushButton(tab_Camera_Settings);
        pushButton_Connect_Camera->setObjectName(QStringLiteral("pushButton_Connect_Camera"));
        pushButton_Connect_Camera->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_Connect_Camera);

        pushButton_Disconnect_Camera = new QPushButton(tab_Camera_Settings);
        pushButton_Disconnect_Camera->setObjectName(QStringLiteral("pushButton_Disconnect_Camera"));
        pushButton_Disconnect_Camera->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_Disconnect_Camera);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_Connect_Robot = new QPushButton(tab_Camera_Settings);
        pushButton_Connect_Robot->setObjectName(QStringLiteral("pushButton_Connect_Robot"));
        sizePolicy1.setHeightForWidth(pushButton_Connect_Robot->sizePolicy().hasHeightForWidth());
        pushButton_Connect_Robot->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(pushButton_Connect_Robot);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton_PLT_3105 = new QRadioButton(tab_Camera_Settings);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_PLT_3105);
        radioButton_PLT_3105->setObjectName(QStringLiteral("radioButton_PLT_3105"));
        radioButton_PLT_3105->setChecked(true);

        verticalLayout_5->addWidget(radioButton_PLT_3105);

        radioButton_PLT_3109 = new QRadioButton(tab_Camera_Settings);
        buttonGroup->addButton(radioButton_PLT_3109);
        radioButton_PLT_3109->setObjectName(QStringLiteral("radioButton_PLT_3109"));

        verticalLayout_5->addWidget(radioButton_PLT_3109);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_3 = new QLabel(tab_Camera_Settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(tab_Camera_Settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(label_4);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        spinBox_Robot_Number = new QSpinBox(tab_Camera_Settings);
        spinBox_Robot_Number->setObjectName(QStringLiteral("spinBox_Robot_Number"));
        spinBox_Robot_Number->setMinimum(1);
        spinBox_Robot_Number->setMaximum(20);
        spinBox_Robot_Number->setValue(10);

        verticalLayout_7->addWidget(spinBox_Robot_Number);

        spinBox_Robot_Port = new QSpinBox(tab_Camera_Settings);
        spinBox_Robot_Port->setObjectName(QStringLiteral("spinBox_Robot_Port"));
        spinBox_Robot_Port->setMaximum(65535);
        spinBox_Robot_Port->setValue(20000);

        verticalLayout_7->addWidget(spinBox_Robot_Port);


        horizontalLayout_4->addLayout(verticalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_8->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_Camera_Settings, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 763, 22));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionInfo);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", nullptr));
        pushButton_Start_Game->setText(QApplication::translate("MainWindow", "Lancer", nullptr));
        label_Country->setText(QApplication::translate("MainWindow", "PAYS : ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Inconnu", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Afficher : ", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Table", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "Zone", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "Robot", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "1", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "2", nullptr));
        checkBox_6->setText(QApplication::translate("MainWindow", "3", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "4", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "5", nullptr));
        checkBox_9->setText(QApplication::translate("MainWindow", "6", nullptr));
        label_Computed_Image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_View), QApplication::translate("MainWindow", "Vue", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Table : ", nullptr));
        comboBox_choix_Table->setItemText(0, QApplication::translate("MainWindow", "Table 1", nullptr));
        comboBox_choix_Table->setItemText(1, QApplication::translate("MainWindow", "Table 2", nullptr));
        comboBox_choix_Table->setItemText(2, QApplication::translate("MainWindow", "Table 3", nullptr));
        comboBox_choix_Table->setItemText(3, QApplication::translate("MainWindow", "Table 4", nullptr));
        comboBox_choix_Table->setItemText(4, QApplication::translate("MainWindow", "Table 5", nullptr));
        comboBox_choix_Table->setItemText(5, QApplication::translate("MainWindow", "Table 6", nullptr));

        pushButton_Scan_Cameras->setText(QApplication::translate("MainWindow", "Scanner les cam\303\251ras du syst\303\250me", nullptr));
        pushButton_Connect_Camera->setText(QApplication::translate("MainWindow", "Connecter", nullptr));
        pushButton_Disconnect_Camera->setText(QApplication::translate("MainWindow", "D\303\251connecter", nullptr));
        pushButton_Connect_Robot->setText(QApplication::translate("MainWindow", "Connecter Robot", nullptr));
        radioButton_PLT_3105->setText(QApplication::translate("MainWindow", "PLT-3105", nullptr));
        radioButton_PLT_3109->setText(QApplication::translate("MainWindow", "PLT-3109", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "# Robot", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "# Port", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Camera_Settings), QApplication::translate("MainWindow", "R\303\251glages", nullptr));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
