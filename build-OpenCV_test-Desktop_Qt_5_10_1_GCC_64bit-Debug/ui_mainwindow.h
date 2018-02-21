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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
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
    QLabel *label_Computed_Image;
    QWidget *tab_Camera_Settings;
    QVBoxLayout *verticalLayout_6;
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
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(669, 630);
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

        h_layout_Instruments_Game_View->addWidget(label_Country);

        label = new QLabel(tab_View);
        label->setObjectName(QStringLiteral("label"));

        h_layout_Instruments_Game_View->addWidget(label);


        v_layout_Whole_Game_View->addLayout(h_layout_Instruments_Game_View);

        label_Computed_Image = new QLabel(tab_View);
        label_Computed_Image->setObjectName(QStringLiteral("label_Computed_Image"));

        v_layout_Whole_Game_View->addWidget(label_Computed_Image);


        verticalLayout_2->addLayout(v_layout_Whole_Game_View);

        tabWidget->addTab(tab_View, QString());
        tab_Camera_Settings = new QWidget();
        tab_Camera_Settings->setObjectName(QStringLiteral("tab_Camera_Settings"));
        verticalLayout_6 = new QVBoxLayout(tab_Camera_Settings);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(tab_Camera_Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

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
        pushButton = new QPushButton(tab_Camera_Settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        radioButton = new QRadioButton(tab_Camera_Settings);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout_5->addWidget(radioButton);

        lineEdit = new QLineEdit(tab_Camera_Settings);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radioButton_2 = new QRadioButton(tab_Camera_Settings);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_6->addWidget(radioButton_2);

        lineEdit_2 = new QLineEdit(tab_Camera_Settings);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);


        verticalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_Camera_Settings, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 669, 22));
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", nullptr));
        pushButton_Start_Game->setText(QApplication::translate("MainWindow", "Lancer", nullptr));
        label_Country->setText(QApplication::translate("MainWindow", "PAYS : ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Inconnu", nullptr));
        label_Computed_Image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_View), QApplication::translate("MainWindow", "Vue du Jeu", nullptr));
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
        pushButton->setText(QApplication::translate("MainWindow", "Connecter Robot", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "PLT-3105", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "PLT-3109", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Camera_Settings), QApplication::translate("MainWindow", "R\303\251glages Camera", nullptr));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
