/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Base_Station/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[630];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "dt_timeout"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 27), // "handleRobotConnectionStatus"
QT_MOC_LITERAL(4, 51, 8), // "p_status"
QT_MOC_LITERAL(5, 60, 17), // "PIDValuesReceived"
QT_MOC_LITERAL(6, 78, 15), // "PIDValuesStruct"
QT_MOC_LITERAL(7, 94, 3), // "pid"
QT_MOC_LITERAL(8, 98, 11), // "addPIDPoint"
QT_MOC_LITERAL(9, 110, 5), // "array"
QT_MOC_LITERAL(10, 116, 19), // "countryCodeReceived"
QT_MOC_LITERAL(11, 136, 4), // "code"
QT_MOC_LITERAL(12, 141, 18), // "cameraDisconnected"
QT_MOC_LITERAL(13, 160, 23), // "on_actionInfo_triggered"
QT_MOC_LITERAL(14, 184, 34), // "on_pushButton_Scan_Cameras_cl..."
QT_MOC_LITERAL(15, 219, 52), // "on_listWidget_Connected_Camer..."
QT_MOC_LITERAL(16, 272, 36), // "on_pushButton_Connect_Camera_..."
QT_MOC_LITERAL(17, 309, 39), // "on_pushButton_Disconnect_Came..."
QT_MOC_LITERAL(18, 349, 35), // "on_pushButton_Connect_Robot_c..."
QT_MOC_LITERAL(19, 385, 32), // "on_pushButton_Start_Game_clicked"
QT_MOC_LITERAL(20, 418, 36), // "on_pushButton_PID_Pause_Play_..."
QT_MOC_LITERAL(21, 455, 37), // "on_pushButton_Read_PID_Values..."
QT_MOC_LITERAL(22, 493, 38), // "on_pushButton_Store_PID_Value..."
QT_MOC_LITERAL(23, 532, 34), // "on_pushButton_PID_Activate_cl..."
QT_MOC_LITERAL(24, 567, 31), // "on_pushButton_PID_Start_clicked"
QT_MOC_LITERAL(25, 599, 30) // "on_pushButton_PID_Kill_clicked"

    },
    "MainWindow\0dt_timeout\0\0"
    "handleRobotConnectionStatus\0p_status\0"
    "PIDValuesReceived\0PIDValuesStruct\0pid\0"
    "addPIDPoint\0array\0countryCodeReceived\0"
    "code\0cameraDisconnected\0on_actionInfo_triggered\0"
    "on_pushButton_Scan_Cameras_clicked\0"
    "on_listWidget_Connected_Cameras_itemSelectionChanged\0"
    "on_pushButton_Connect_Camera_clicked\0"
    "on_pushButton_Disconnect_Camera_clicked\0"
    "on_pushButton_Connect_Robot_clicked\0"
    "on_pushButton_Start_Game_clicked\0"
    "on_pushButton_PID_Pause_Play_clicked\0"
    "on_pushButton_Read_PID_Values_clicked\0"
    "on_pushButton_Store_PID_Values_clicked\0"
    "on_pushButton_PID_Activate_clicked\0"
    "on_pushButton_PID_Start_clicked\0"
    "on_pushButton_PID_Kill_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    1,  110,    2, 0x0a /* Public */,
       5,    1,  113,    2, 0x0a /* Public */,
       8,    1,  116,    2, 0x0a /* Public */,
      10,    1,  119,    2, 0x0a /* Public */,
      12,    0,  122,    2, 0x08 /* Private */,
      13,    0,  123,    2, 0x08 /* Private */,
      14,    0,  124,    2, 0x08 /* Private */,
      15,    0,  125,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    0,  129,    2, 0x08 /* Private */,
      20,    0,  130,    2, 0x08 /* Private */,
      21,    0,  131,    2, 0x08 /* Private */,
      22,    0,  132,    2, 0x08 /* Private */,
      23,    0,  133,    2, 0x08 /* Private */,
      24,    0,  134,    2, 0x08 /* Private */,
      25,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::Char,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dt_timeout(); break;
        case 1: _t->handleRobotConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->PIDValuesReceived((*reinterpret_cast< PIDValuesStruct(*)>(_a[1]))); break;
        case 3: _t->addPIDPoint((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->countryCodeReceived((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 5: _t->cameraDisconnected(); break;
        case 6: _t->on_actionInfo_triggered(); break;
        case 7: _t->on_pushButton_Scan_Cameras_clicked(); break;
        case 8: _t->on_listWidget_Connected_Cameras_itemSelectionChanged(); break;
        case 9: _t->on_pushButton_Connect_Camera_clicked(); break;
        case 10: _t->on_pushButton_Disconnect_Camera_clicked(); break;
        case 11: _t->on_pushButton_Connect_Robot_clicked(); break;
        case 12: _t->on_pushButton_Start_Game_clicked(); break;
        case 13: _t->on_pushButton_PID_Pause_Play_clicked(); break;
        case 14: _t->on_pushButton_Read_PID_Values_clicked(); break;
        case 15: _t->on_pushButton_Store_PID_Values_clicked(); break;
        case 16: _t->on_pushButton_PID_Activate_clicked(); break;
        case 17: _t->on_pushButton_PID_Start_clicked(); break;
        case 18: _t->on_pushButton_PID_Kill_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
