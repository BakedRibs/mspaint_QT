/****************************************************************************
** Meta object code from reading C++ file 'paint_qt.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GitHub/mspaint_QT/paint_qt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint_qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_paint_QT[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   10,    9,    9, 0x0a,
      57,   47,    9,    9, 0x0a,
      92,   85,    9,    9, 0x0a,
     124,  117,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_paint_QT[] = {
    "paint_QT\0\0tmpColor\0colorButtonClicked(QColor*)\0"
    "tmpString\0toolsButtonClicked(QString)\0"
    "tmpNum\0shapesButtonClicked(int)\0tmpWid\0"
    "penwidthButtonClicked(int)\0"
};

void paint_QT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        paint_QT *_t = static_cast<paint_QT *>(_o);
        switch (_id) {
        case 0: _t->colorButtonClicked((*reinterpret_cast< QColor*(*)>(_a[1]))); break;
        case 1: _t->toolsButtonClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->shapesButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->penwidthButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData paint_QT::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject paint_QT::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_paint_QT,
      qt_meta_data_paint_QT, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &paint_QT::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *paint_QT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *paint_QT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_paint_QT))
        return static_cast<void*>(const_cast< paint_QT*>(this));
    return QDialog::qt_metacast(_clname);
}

int paint_QT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
