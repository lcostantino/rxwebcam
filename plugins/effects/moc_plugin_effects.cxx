/****************************************************************************
** Meta object code from reading C++ file 'plugin_effects.h'
**
** Created: Wed Nov 5 16:14:50 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plugin_effects.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin_effects.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Effects[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_Effects[] = {
    "Effects\0"
};

const QMetaObject Effects::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Effects,
      qt_meta_data_Effects, 0 }
};

const QMetaObject *Effects::metaObject() const
{
    return &staticMetaObject;
}

void *Effects::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Effects))
        return static_cast<void*>(const_cast< Effects*>(this));
    if (!strcmp(_clname, "RxWebcamInterface"))
        return static_cast< RxWebcamInterface*>(const_cast< Effects*>(this));
    if (!strcmp(_clname, "com.trolltech.RxWebcamInterface/1.0"))
        return static_cast< RxWebcamInterface*>(const_cast< Effects*>(this));
    return QObject::qt_metacast(_clname);
}

int Effects::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE