/****************************************************************************
** Meta object code from reading C++ file 'QSLPlotCartesianSet.h'
**
** Created: Wed Mar 20 14:35:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLPlotCartesianSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLPlotCartesianSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLPlotCartesianSet[] = {

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
      25,   21,   20,   20, 0x0a,
      59,   51,   20,   20, 0x0a,
      77,   51,   20,   20, 0x0a,
     101,   97,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSLPlotCartesianSet[] = {
    "QSLPlotCartesianSet\0\0sty\0"
    "setPointStyle(PointStyle)\0enabled\0"
    "setDrawLine(bool)\0setDrawPoints(bool)\0"
    "rad\0setPointRadius(int)\0"
};

void QSLPlotCartesianSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLPlotCartesianSet *_t = static_cast<QSLPlotCartesianSet *>(_o);
        switch (_id) {
        case 0: _t->setPointStyle((*reinterpret_cast< PointStyle(*)>(_a[1]))); break;
        case 1: _t->setDrawLine((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setDrawPoints((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setPointRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLPlotCartesianSet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLPlotCartesianSet::staticMetaObject = {
    { &QSLPlotable::staticMetaObject, qt_meta_stringdata_QSLPlotCartesianSet,
      qt_meta_data_QSLPlotCartesianSet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLPlotCartesianSet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLPlotCartesianSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLPlotCartesianSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLPlotCartesianSet))
        return static_cast<void*>(const_cast< QSLPlotCartesianSet*>(this));
    return QSLPlotable::qt_metacast(_clname);
}

int QSLPlotCartesianSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLPlotable::qt_metacall(_c, _id, _a);
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
