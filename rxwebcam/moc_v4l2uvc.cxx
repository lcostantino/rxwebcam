/****************************************************************************
** Meta object code from reading C++ file 'v4l2uvc.h'
**
** Created: Wed Nov 5 16:14:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "v4l2wrap/v4l2uvc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v4l2uvc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V4L2Cmd[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      49,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     115,  112,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V4L2Cmd[] = {
    "V4L2Cmd\0\0,min,max,current,type,step,def_value,id\0"
    "new_control(QString,int,int,int,int,int,int,unsigned long int)\0"
    ",,\0changeValue(QString,int,int)\0"
};

const QMetaObject V4L2Cmd::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_V4L2Cmd,
      qt_meta_data_V4L2Cmd, 0 }
};

const QMetaObject *V4L2Cmd::metaObject() const
{
    return &staticMetaObject;
}

void *V4L2Cmd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V4L2Cmd))
        return static_cast<void*>(const_cast< V4L2Cmd*>(this));
    return QObject::qt_metacast(_clname);
}

int V4L2Cmd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: new_control((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< unsigned long int(*)>(_a[8]))); break;
        case 1: changeValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void V4L2Cmd::new_control(const QString & _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, unsigned long int _t8)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
