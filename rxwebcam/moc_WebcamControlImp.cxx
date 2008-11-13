/****************************************************************************
** Meta object code from reading C++ file 'WebcamControlImp.h'
**
** Created: Wed Nov 5 16:14:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "WebcamControlImp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebcamControlImp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPushButtonT[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QPushButtonT[] = {
    "QPushButtonT\0\0,,,\0"
    "updateDataController(qulonglong,int,int,int)\0"
    "click()\0"
};

const QMetaObject QPushButtonT::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QPushButtonT,
      qt_meta_data_QPushButtonT, 0 }
};

const QMetaObject *QPushButtonT::metaObject() const
{
    return &staticMetaObject;
}

void *QPushButtonT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPushButtonT))
        return static_cast<void*>(const_cast< QPushButtonT*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QPushButtonT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDataController((*reinterpret_cast< qulonglong(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: click(); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPushButtonT::updateDataController(qulonglong _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QComboBoxT[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   61,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QComboBoxT[] = {
    "QComboBoxT\0\0,,,\0"
    "updateDataController(qulonglong,int,int,int)\0"
    "current\0selectedItem(int)\0"
};

const QMetaObject QComboBoxT::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_QComboBoxT,
      qt_meta_data_QComboBoxT, 0 }
};

const QMetaObject *QComboBoxT::metaObject() const
{
    return &staticMetaObject;
}

void *QComboBoxT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QComboBoxT))
        return static_cast<void*>(const_cast< QComboBoxT*>(this));
    return QComboBox::qt_metacast(_clname);
}

int QComboBoxT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDataController((*reinterpret_cast< qulonglong(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: selectedItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QComboBoxT::updateDataController(qulonglong _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QCheckBoxT[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QCheckBoxT[] = {
    "QCheckBoxT\0\0,,,\0"
    "updateDataController(qulonglong,int,int,int)\0"
    "clickedBox()\0"
};

const QMetaObject QCheckBoxT::staticMetaObject = {
    { &QCheckBox::staticMetaObject, qt_meta_stringdata_QCheckBoxT,
      qt_meta_data_QCheckBoxT, 0 }
};

const QMetaObject *QCheckBoxT::metaObject() const
{
    return &staticMetaObject;
}

void *QCheckBoxT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCheckBoxT))
        return static_cast<void*>(const_cast< QCheckBoxT*>(this));
    return QCheckBox::qt_metacast(_clname);
}

int QCheckBoxT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCheckBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDataController((*reinterpret_cast< qulonglong(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: clickedBox(); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QCheckBoxT::updateDataController(qulonglong _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QSliderT[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   59,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QSliderT[] = {
    "QSliderT\0\0,,,\0"
    "updateDataController(qulonglong,int,int,int)\0"
    "newVal\0changedvalue(int)\0"
};

const QMetaObject QSliderT::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_QSliderT,
      qt_meta_data_QSliderT, 0 }
};

const QMetaObject *QSliderT::metaObject() const
{
    return &staticMetaObject;
}

void *QSliderT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSliderT))
        return static_cast<void*>(const_cast< QSliderT*>(this));
    return QSlider::qt_metacast(_clname);
}

int QSliderT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDataController((*reinterpret_cast< qulonglong(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: changedvalue((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QSliderT::updateDataController(qulonglong _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_WebcamControlImp[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      21,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   50,   17,   17, 0x09,
     189,  161,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_WebcamControlImp[] = {
    "WebcamControlImp\0\0,,\0changeValue(QString,int,int)\0"
    "name,min,max,current,type,step,default_value,id\0"
    "new_control(QString,int,int,int,int,int,int,unsigned long int)\0"
    "id,old_value,new_value,type\0"
    "updateDataController(qulonglong,int,int,int)\0"
};

const QMetaObject WebcamControlImp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WebcamControlImp,
      qt_meta_data_WebcamControlImp, 0 }
};

const QMetaObject *WebcamControlImp::metaObject() const
{
    return &staticMetaObject;
}

void *WebcamControlImp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebcamControlImp))
        return static_cast<void*>(const_cast< WebcamControlImp*>(this));
    return QDialog::qt_metacast(_clname);
}

int WebcamControlImp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: new_control((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< unsigned long int(*)>(_a[8]))); break;
        case 2: updateDataController((*reinterpret_cast< qulonglong(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WebcamControlImp::changeValue(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
