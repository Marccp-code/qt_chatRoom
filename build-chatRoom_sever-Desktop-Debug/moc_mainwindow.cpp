/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatRoom_sever/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[13];
    char stringdata[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 24),
QT_MOC_LITERAL(4, 53, 16),
QT_MOC_LITERAL(5, 70, 7),
QT_MOC_LITERAL(6, 78, 23),
QT_MOC_LITERAL(7, 102, 22),
QT_MOC_LITERAL(8, 125, 20),
QT_MOC_LITERAL(9, 146, 13),
QT_MOC_LITERAL(10, 160, 13),
QT_MOC_LITERAL(11, 174, 11),
QT_MOC_LITERAL(12, 186, 6)
    },
    "MainWindow\0onNewConnection\0\0"
    "on_btn_boardCast_clicked\0toShowMainWindow\0"
    "pack_t*\0toShowMainWindow_string\0"
    "on_btn_refresh_clicked\0solve_onlineListEmit\0"
    "toSetTextEdit\0toSendPackage\0QTcpSocket*\0"
    "socket\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    0,   55,    2, 0x08,
       4,    1,   56,    2, 0x08,
       6,    1,   59,    2, 0x08,
       7,    0,   62,    2, 0x08,
       8,    1,   63,    2, 0x08,
       9,    1,   66,    2, 0x08,
      10,    2,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 11,    2,   12,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->on_btn_boardCast_clicked(); break;
        case 2: _t->toShowMainWindow((*reinterpret_cast< pack_t*(*)>(_a[1]))); break;
        case 3: _t->toShowMainWindow_string((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_btn_refresh_clicked(); break;
        case 5: _t->solve_onlineListEmit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->toSetTextEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->toSendPackage((*reinterpret_cast< pack_t*(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
