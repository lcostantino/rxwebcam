/****************************************************************************
** Meta object code from reading C++ file 'plugin_photo_server.h'
**
** Created: Wed Nov 5 16:14:58 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plugin_photo_server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin_photo_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhotoServer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_PhotoServer[] = {
    "PhotoServer\0"
};

const QMetaObject PhotoServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PhotoServer,
      qt_meta_data_PhotoServer, 0 }
};

const QMetaObject *PhotoServer::metaObject() const
{
    return &staticMetaObject;
}

void *PhotoServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhotoServer))
        return static_cast<void*>(const_cast< PhotoServer*>(this));
    if (!strcmp(_clname, "RxWebcamInterface"))
        return static_cast< RxWebcamInterface*>(const_cast< PhotoServer*>(this));
    if (!strcmp(_clname, "com.trolltech.RxWebcamInterface/1.0"))
        return static_cast< RxWebcamInterface*>(const_cast< PhotoServer*>(this));
    return QObject::qt_metacast(_clname);
}

int PhotoServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
