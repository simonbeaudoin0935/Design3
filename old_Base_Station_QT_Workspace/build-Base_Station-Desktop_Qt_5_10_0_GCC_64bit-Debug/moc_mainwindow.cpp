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
    QByteArrayData data[42];
    char stringdata0[1051];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 37), // "on_pushButton_Gamepad_Connect..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 28), // "gamepad_Left_Stick_X_Changed"
QT_MOC_LITERAL(4, 79, 7), // "p_value"
QT_MOC_LITERAL(5, 87, 28), // "gamepad_Left_Stick_Y_Changed"
QT_MOC_LITERAL(6, 116, 29), // "gamepad_Right_Stick_X_Changed"
QT_MOC_LITERAL(7, 146, 29), // "gamepad_Right_Stick_Y_Changed"
QT_MOC_LITERAL(8, 176, 28), // "gamepad_Left_Trigger_Changed"
QT_MOC_LITERAL(9, 205, 29), // "gamepad_Right_Trigger_Changed"
QT_MOC_LITERAL(10, 235, 18), // "gamepad_UP_Changed"
QT_MOC_LITERAL(11, 254, 20), // "gamepad_DOWN_Changed"
QT_MOC_LITERAL(12, 275, 20), // "gamepad_LEFT_Changed"
QT_MOC_LITERAL(13, 296, 21), // "gamepad_RIGHT_Changed"
QT_MOC_LITERAL(14, 318, 17), // "gamepad_A_Changed"
QT_MOC_LITERAL(15, 336, 17), // "gamepad_B_Changed"
QT_MOC_LITERAL(16, 354, 17), // "gamepad_X_Changed"
QT_MOC_LITERAL(17, 372, 17), // "gamepad_Y_Changed"
QT_MOC_LITERAL(18, 390, 21), // "gamepad_WHITE_Changed"
QT_MOC_LITERAL(19, 412, 21), // "gamepad_BLACK_Changed"
QT_MOC_LITERAL(20, 434, 26), // "gamepad_LEFT_STICK_Changed"
QT_MOC_LITERAL(21, 461, 27), // "gamepad_RIGHT_STICK_Changed"
QT_MOC_LITERAL(22, 489, 21), // "gamepad_START_Changed"
QT_MOC_LITERAL(23, 511, 20), // "gamepad_BACK_Changed"
QT_MOC_LITERAL(24, 532, 36), // "on_pushButton_Serial_Connect_..."
QT_MOC_LITERAL(25, 569, 33), // "on_pushButton_Serial_Scan_cli..."
QT_MOC_LITERAL(26, 603, 47), // "on_comboBox_Serial_Selector_c..."
QT_MOC_LITERAL(27, 651, 4), // "arg1"
QT_MOC_LITERAL(28, 656, 22), // "serial_send_on_timeout"
QT_MOC_LITERAL(29, 679, 33), // "on_pushButton_Camera_Scan_cli..."
QT_MOC_LITERAL(30, 713, 47), // "on_comboBox_Camera_Selector_c..."
QT_MOC_LITERAL(31, 761, 36), // "on_pushButton_Camera_Connect_..."
QT_MOC_LITERAL(32, 798, 20), // "serial_data_received"
QT_MOC_LITERAL(33, 819, 39), // "on_pushButton_Serial_Disconne..."
QT_MOC_LITERAL(34, 859, 31), // "on_pushButton_Reset_PID_clicked"
QT_MOC_LITERAL(35, 891, 36), // "on_pushButton_PID_Pause_Play_..."
QT_MOC_LITERAL(36, 928, 30), // "on_pushButton_Read_PID_clicked"
QT_MOC_LITERAL(37, 959, 31), // "on_pushButton_Store_PID_clicked"
QT_MOC_LITERAL(38, 991, 32), // "on_pushButton_Take_Image_clicked"
QT_MOC_LITERAL(39, 1024, 11), // "image_saved"
QT_MOC_LITERAL(40, 1036, 5), // "p_int"
QT_MOC_LITERAL(41, 1042, 8) // "p_string"

    },
    "MainWindow\0on_pushButton_Gamepad_Connect_clicked\0"
    "\0gamepad_Left_Stick_X_Changed\0p_value\0"
    "gamepad_Left_Stick_Y_Changed\0"
    "gamepad_Right_Stick_X_Changed\0"
    "gamepad_Right_Stick_Y_Changed\0"
    "gamepad_Left_Trigger_Changed\0"
    "gamepad_Right_Trigger_Changed\0"
    "gamepad_UP_Changed\0gamepad_DOWN_Changed\0"
    "gamepad_LEFT_Changed\0gamepad_RIGHT_Changed\0"
    "gamepad_A_Changed\0gamepad_B_Changed\0"
    "gamepad_X_Changed\0gamepad_Y_Changed\0"
    "gamepad_WHITE_Changed\0gamepad_BLACK_Changed\0"
    "gamepad_LEFT_STICK_Changed\0"
    "gamepad_RIGHT_STICK_Changed\0"
    "gamepad_START_Changed\0gamepad_BACK_Changed\0"
    "on_pushButton_Serial_Connect_clicked\0"
    "on_pushButton_Serial_Scan_clicked\0"
    "on_comboBox_Serial_Selector_currentIndexChanged\0"
    "arg1\0serial_send_on_timeout\0"
    "on_pushButton_Camera_Scan_clicked\0"
    "on_comboBox_Camera_Selector_currentIndexChanged\0"
    "on_pushButton_Camera_Connect_clicked\0"
    "serial_data_received\0"
    "on_pushButton_Serial_Disconnect_clicked\0"
    "on_pushButton_Reset_PID_clicked\0"
    "on_pushButton_PID_Pause_Play_clicked\0"
    "on_pushButton_Read_PID_clicked\0"
    "on_pushButton_Store_PID_clicked\0"
    "on_pushButton_Take_Image_clicked\0"
    "image_saved\0p_int\0p_string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x08 /* Private */,
       3,    1,  195,    2, 0x08 /* Private */,
       5,    1,  198,    2, 0x08 /* Private */,
       6,    1,  201,    2, 0x08 /* Private */,
       7,    1,  204,    2, 0x08 /* Private */,
       8,    1,  207,    2, 0x08 /* Private */,
       9,    1,  210,    2, 0x08 /* Private */,
      10,    1,  213,    2, 0x08 /* Private */,
      11,    1,  216,    2, 0x08 /* Private */,
      12,    1,  219,    2, 0x08 /* Private */,
      13,    1,  222,    2, 0x08 /* Private */,
      14,    1,  225,    2, 0x08 /* Private */,
      15,    1,  228,    2, 0x08 /* Private */,
      16,    1,  231,    2, 0x08 /* Private */,
      17,    1,  234,    2, 0x08 /* Private */,
      18,    1,  237,    2, 0x08 /* Private */,
      19,    1,  240,    2, 0x08 /* Private */,
      20,    1,  243,    2, 0x08 /* Private */,
      21,    1,  246,    2, 0x08 /* Private */,
      22,    1,  249,    2, 0x08 /* Private */,
      23,    1,  252,    2, 0x08 /* Private */,
      24,    0,  255,    2, 0x08 /* Private */,
      25,    0,  256,    2, 0x08 /* Private */,
      26,    1,  257,    2, 0x08 /* Private */,
      28,    0,  260,    2, 0x08 /* Private */,
      29,    0,  261,    2, 0x08 /* Private */,
      30,    1,  262,    2, 0x08 /* Private */,
      31,    0,  265,    2, 0x08 /* Private */,
      32,    0,  266,    2, 0x08 /* Private */,
      33,    0,  267,    2, 0x08 /* Private */,
      34,    0,  268,    2, 0x08 /* Private */,
      35,    0,  269,    2, 0x08 /* Private */,
      36,    0,  270,    2, 0x08 /* Private */,
      37,    0,  271,    2, 0x08 /* Private */,
      38,    0,  272,    2, 0x08 /* Private */,
      39,    2,  273,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   40,   41,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Gamepad_Connect_clicked(); break;
        case 1: _t->gamepad_Left_Stick_X_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->gamepad_Left_Stick_Y_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->gamepad_Right_Stick_X_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->gamepad_Right_Stick_Y_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->gamepad_Left_Trigger_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->gamepad_Right_Trigger_Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->gamepad_UP_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->gamepad_DOWN_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->gamepad_LEFT_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->gamepad_RIGHT_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->gamepad_A_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->gamepad_B_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->gamepad_X_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->gamepad_Y_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->gamepad_WHITE_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->gamepad_BLACK_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->gamepad_LEFT_STICK_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->gamepad_RIGHT_STICK_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->gamepad_START_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->gamepad_BACK_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_pushButton_Serial_Connect_clicked(); break;
        case 22: _t->on_pushButton_Serial_Scan_clicked(); break;
        case 23: _t->on_comboBox_Serial_Selector_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->serial_send_on_timeout(); break;
        case 25: _t->on_pushButton_Camera_Scan_clicked(); break;
        case 26: _t->on_comboBox_Camera_Selector_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->on_pushButton_Camera_Connect_clicked(); break;
        case 28: _t->serial_data_received(); break;
        case 29: _t->on_pushButton_Serial_Disconnect_clicked(); break;
        case 30: _t->on_pushButton_Reset_PID_clicked(); break;
        case 31: _t->on_pushButton_PID_Pause_Play_clicked(); break;
        case 32: _t->on_pushButton_Read_PID_clicked(); break;
        case 33: _t->on_pushButton_Store_PID_clicked(); break;
        case 34: _t->on_pushButton_Take_Image_clicked(); break;
        case 35: _t->image_saved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
