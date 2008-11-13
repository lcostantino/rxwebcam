/****************************************************************************
** Meta object code from reading C++ file 'FormStreamingImp.h'
**
** Created: Wed Nov 5 16:14:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FormStreamingImp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FormStreamingImp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RealStreamWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_RealStreamWidget[] = {
    "RealStreamWidget\0"
};

const QMetaObject RealStreamWidget::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_RealStreamWidget,
      qt_meta_data_RealStreamWidget, 0 }
};

const QMetaObject *RealStreamWidget::metaObject() const
{
    return &staticMetaObject;
}

void *RealStreamWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RealStreamWidget))
        return static_cast<void*>(const_cast< RealStreamWidget*>(this));
    return QLabel::qt_metacast(_clname);
}

int RealStreamWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_FormStreamingImp[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      33,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   17,   17,   17, 0x0a,
      75,   17,   17,   17, 0x09,
      89,   17,   17,   17, 0x09,
     103,   17,   17,   17, 0x09,
     117,   17,   17,   17, 0x09,
     130,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FormStreamingImp[] = {
    "FormStreamingImp\0\0newSize(QSize)\0"
    "setStatus(QString)\0showWebcamController()\0"
    "grabPicture()\0updateTimer()\0startStream()\0"
    "stopStream()\0grabMovie()\0"
};

const QMetaObject FormStreamingImp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormStreamingImp,
      qt_meta_data_FormStreamingImp, 0 }
};

const QMetaObject *FormStreamingImp::metaObject() const
{
    return &staticMetaObject;
}

void *FormStreamingImp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormStreamingImp))
        return static_cast<void*>(const_cast< FormStreamingImp*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormStreamingImp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSize((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 1: setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: showWebcamController(); break;
        case 3: grabPicture(); break;
        case 4: updateTimer(); break;
        case 5: startStream(); break;
        case 6: stopStream(); break;
        case 7: grabMovie(); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FormStreamingImp::newSize(QSize _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormStreamingImp::setStatus(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
