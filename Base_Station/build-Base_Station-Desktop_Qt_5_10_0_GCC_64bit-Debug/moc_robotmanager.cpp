/****************************************************************************
** Meta object code from reading C++ file 'robotmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Base_Station/robotmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotManager_t {
    QByteArrayData data[14];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotManager_t qt_meta_stringdata_RobotManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RobotManager"
QT_MOC_LITERAL(1, 13, 21), // "robotConnectionStatus"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "PIDValuesReceived"
QT_MOC_LITERAL(4, 54, 15), // "PIDValuesStruct"
QT_MOC_LITERAL(5, 70, 5), // "p_pid"
QT_MOC_LITERAL(6, 76, 17), // "PIDOutputReceived"
QT_MOC_LITERAL(7, 94, 8), // "p_output"
QT_MOC_LITERAL(8, 103, 9), // "connected"
QT_MOC_LITERAL(9, 113, 12), // "disconnected"
QT_MOC_LITERAL(10, 126, 5), // "error"
QT_MOC_LITERAL(11, 132, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 161, 13), // "p_socketError"
QT_MOC_LITERAL(13, 175, 9) // "readyRead"

    },
    "RobotManager\0robotConnectionStatus\0\0"
    "PIDValuesReceived\0PIDValuesStruct\0"
    "p_pid\0PIDOutputReceived\0p_output\0"
    "connected\0disconnected\0error\0"
    "QAbstractSocket::SocketError\0p_socketError\0"
    "readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      13,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void RobotManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotManager *_t = static_cast<RobotManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->robotConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->PIDValuesReceived((*reinterpret_cast< PIDValuesStruct(*)>(_a[1]))); break;
        case 2: _t->PIDOutputReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RobotManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotManager::robotConnectionStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RobotManager::*_t)(PIDValuesStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotManager::PIDValuesReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RobotManager::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotManager::PIDOutputReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RobotManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RobotManager.data,
      qt_meta_data_RobotManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RobotManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RobotManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RobotManager::robotConnectionStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RobotManager::PIDValuesReceived(PIDValuesStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RobotManager::PIDOutputReceived(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
