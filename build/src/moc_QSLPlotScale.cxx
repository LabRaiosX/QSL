/****************************************************************************
** Meta object code from reading C++ file 'QSLPlotScale.h'
**
** Created: Wed Mar 20 14:35:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLPlotScale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLPlotScale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLPlotScale[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x0a,
      84,   45,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QSLPlotScale[] = {
    "QSLPlotScale\0\0pos\0setPosition(ScalePosition)\0"
    "minData,maxData,minPix,maxPix,perpDist\0"
    "update(double,double,int,int,int)\0"
};

void QSLPlotScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLPlotScale *_t = static_cast<QSLPlotScale *>(_o);
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< ScalePosition(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLPlotScale::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLPlotScale::staticMetaObject = {
    { &QSLPlotable::staticMetaObject, qt_meta_stringdata_QSLPlotScale,
      qt_meta_data_QSLPlotScale, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLPlotScale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLPlotScale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLPlotScale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLPlotScale))
        return static_cast<void*>(const_cast< QSLPlotScale*>(this));
    return QSLPlotable::qt_metacast(_clname);
}

int QSLPlotScale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLPlotable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
