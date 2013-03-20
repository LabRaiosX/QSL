/****************************************************************************
** Meta object code from reading C++ file 'QSLPlotArea.h'
**
** Created: Wed Mar 20 14:35:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLPlotArea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLPlotArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLPlotArea[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,
      48,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   64,   12,   12, 0x0a,
     101,   95,   12,   12, 0x0a,
     126,   64,   12,   12, 0x0a,
     151,   95,   12,   12, 0x0a,
     180,  176,   12,   12, 0x0a,
     201,   12,   12,   12, 0x0a,
     210,   12,   12,   12, 0x0a,
     224,  220,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSLPlotArea[] = {
    "QSLPlotArea\0\0plotsChanged()\0"
    "appearenceChanged()\0regionChanged()\0"
    "xi,xf\0setXrange(double,double)\0yi,yf\0"
    "setYrange(double,double)\0"
    "setGraphXbounds(int,int)\0"
    "setGraphYbounds(int,int)\0col\0"
    "setBackColor(QColor)\0replot()\0rescale()\0"
    "plt\0rescale(QSLPlotable*)\0"
};

void QSLPlotArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLPlotArea *_t = static_cast<QSLPlotArea *>(_o);
        switch (_id) {
        case 0: _t->plotsChanged(); break;
        case 1: _t->appearenceChanged(); break;
        case 2: _t->regionChanged(); break;
        case 3: _t->setXrange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->setYrange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->setGraphXbounds((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setGraphYbounds((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setBackColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->replot(); break;
        case 9: _t->rescale(); break;
        case 10: _t->rescale((*reinterpret_cast< QSLPlotable*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLPlotArea::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLPlotArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QSLPlotArea,
      qt_meta_data_QSLPlotArea, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLPlotArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLPlotArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLPlotArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLPlotArea))
        return static_cast<void*>(const_cast< QSLPlotArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int QSLPlotArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QSLPlotArea::plotsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSLPlotArea::appearenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QSLPlotArea::regionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
