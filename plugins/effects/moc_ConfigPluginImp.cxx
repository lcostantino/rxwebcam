/****************************************************************************
** Meta object code from reading C++ file 'ConfigPluginImp.h'
**
** Created: Wed Nov 5 16:14:50 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui_interfaces/ConfigPluginImp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigPluginImp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigPluginImp[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x09,
      51,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ConfigPluginImp[] = {
    "ConfigPluginImp\0\0effectActivated(QListWidgetItem*)\0"
    "accept()\0"
};

const QMetaObject ConfigPluginImp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigPluginImp,
      qt_meta_data_ConfigPluginImp, 0 }
};

const QMetaObject *ConfigPluginImp::metaObject() const
{
    return &staticMetaObject;
}

void *ConfigPluginImp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigPluginImp))
        return static_cast<void*>(const_cast< ConfigPluginImp*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigPluginImp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: effectActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: accept(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
