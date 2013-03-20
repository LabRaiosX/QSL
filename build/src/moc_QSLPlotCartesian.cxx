/****************************************************************************
** Meta object code from reading C++ file 'QSLPlotCartesian.h'
**
** Created: Wed Mar 20 14:35:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLPlotCartesian.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLPlotCartesian.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLPlotCartesian[] = {

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
      23,   18,   17,   17, 0x0a,
      69,   65,   17,   17, 0x0a,
     102,   93,   17,   17, 0x0a,
     125,  121,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSLPlotCartesian[] = {
    "QSLPlotCartesian\0\0plts\0"
    "setPlotables(QList<QSLPlotCartesianSet*>)\0"
    "sca\0addScale(QSLPlotScale*)\0fileName\0"
    "exportPNG(QString)\0col\0setScalesColor(QColor)\0"
};

void QSLPlotCartesian::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLPlotCartesian *_t = static_cast<QSLPlotCartesian *>(_o);
        switch (_id) {
        case 0: _t->setPlotables((*reinterpret_cast< const QList<QSLPlotCartesianSet*>(*)>(_a[1]))); break;
        case 1: _t->addScale((*reinterpret_cast< QSLPlotScale*(*)>(_a[1]))); break;
        case 2: _t->exportPNG((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setScalesColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLPlotCartesian::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLPlotCartesian::staticMetaObject = {
    { &QSLPlotArea::staticMetaObject, qt_meta_stringdata_QSLPlotCartesian,
      qt_meta_data_QSLPlotCartesian, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLPlotCartesian::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLPlotCartesian::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLPlotCartesian::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLPlotCartesian))
        return static_cast<void*>(const_cast< QSLPlotCartesian*>(this));
    return QSLPlotArea::qt_metacast(_clname);
}

int QSLPlotCartesian::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLPlotArea::qt_metacall(_c, _id, _a);
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
