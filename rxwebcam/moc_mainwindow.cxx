/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Nov 5 16:14:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RxWebcamMain[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x09,
      30,   27,   13,   13, 0x09,
      48,   13,   13,   13, 0x09,
      67,   63,   13,   13, 0x09,
      90,   86,   13,   13, 0x09,
     110,   13,   13,   13, 0x09,
     126,   13,   13,   13, 0x09,
     140,   13,   13,   13, 0x09,
     150,   13,   13,   13, 0x09,
     158,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_RxWebcamMain[] = {
    "RxWebcamMain\0\0openDevice()\0ob\0"
    "setSize(QAction*)\0newSize(QSize)\0msg\0"
    "setStatus(QString)\0act\0pmenuSlot(QAction*)\0"
    "configPlugins()\0setSafeMode()\0showFps()\0"
    "about()\0aboutQt()\0"
};

const QMetaObject RxWebcamMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RxWebcamMain,
      qt_meta_data_RxWebcamMain, 0 }
};

const QMetaObject *RxWebcamMain::metaObject() const
{
    return &staticMetaObject;
}

void *RxWebcamMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RxWebcamMain))
        return static_cast<void*>(const_cast< RxWebcamMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RxWebcamMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openDevice(); break;
        case 1: setSize((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: newSize((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 3: setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: pmenuSlot((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: configPlugins(); break;
        case 6: setSafeMode(); break;
        case 7: showFps(); break;
        case 8: about(); break;
        case 9: aboutQt(); break;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
