/****************************************************************************
** Meta object code from reading C++ file 'v4l2wrap.h'
**
** Created: Wed Nov 5 16:14:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "v4l2wrap/v4l2wrap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v4l2wrap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V4L2Wrap[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_V4L2Wrap[] = {
    "V4L2Wrap\0\0,len,\0"
    "newFrame(const unsigned char*,int,QSize)\0"
};

const QMetaObject V4L2Wrap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_V4L2Wrap,
      qt_meta_data_V4L2Wrap, 0 }
};

const QMetaObject *V4L2Wrap::metaObject() const
{
    return &staticMetaObject;
}

void *V4L2Wrap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V4L2Wrap))
        return static_cast<void*>(const_cast< V4L2Wrap*>(this));
    return QObject::qt_metacast(_clname);
}

int V4L2Wrap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFrame((*reinterpret_cast< const unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void V4L2Wrap::newFrame(const unsigned char * _t1, int _t2, const QSize & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
