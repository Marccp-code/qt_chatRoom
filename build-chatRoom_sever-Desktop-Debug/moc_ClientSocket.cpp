/****************************************************************************
** Meta object code from reading C++ file 'ClientSocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatRoom_sever/ClientSocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientSocket_t {
    QByteArrayData data[12];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ClientSocket_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ClientSocket_t qt_meta_stringdata_ClientSocket = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 7),
QT_MOC_LITERAL(4, 37, 21),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 11),
QT_MOC_LITERAL(7, 87, 11),
QT_MOC_LITERAL(8, 99, 7),
QT_MOC_LITERAL(9, 107, 11),
QT_MOC_LITERAL(10, 119, 6),
QT_MOC_LITERAL(11, 126, 11)
    },
    "ClientSocket\0showMainWindow\0\0pack_t*\0"
    "showMainWindow_string\0onlineList_emit\0"
    "setTextEdit\0sendPackage\0package\0"
    "QTcpSocket*\0socket\0onReadyRead\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       5,    1,   50,    2, 0x06,
       6,    1,   53,    2, 0x06,
       7,    2,   56,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    8,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientSocket *_t = static_cast<ClientSocket *>(_o);
        switch (_id) {
        case 0: _t->showMainWindow((*reinterpret_cast< pack_t*(*)>(_a[1]))); break;
        case 1: _t->showMainWindow_string((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onlineList_emit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setTextEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendPackage((*reinterpret_cast< pack_t*(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 5: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientSocket::*_t)(pack_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::showMainWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::showMainWindow_string)) {
                *result = 1;
            }
        }
        {
            typedef void (ClientSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::onlineList_emit)) {
                *result = 2;
            }
        }
        {
            typedef void (ClientSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::setTextEdit)) {
                *result = 3;
            }
        }
        {
            typedef void (ClientSocket::*_t)(pack_t * , QTcpSocket * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sendPackage)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ClientSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientSocket.data,
      qt_meta_data_ClientSocket,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientSocket.stringdata))
        return static_cast<void*>(const_cast< ClientSocket*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ClientSocket::showMainWindow(pack_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientSocket::showMainWindow_string(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientSocket::onlineList_emit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientSocket::setTextEdit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientSocket::sendPackage(pack_t * _t1, QTcpSocket * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
