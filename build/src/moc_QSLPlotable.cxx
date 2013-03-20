/****************************************************************************
** Meta object code from reading C++ file 'QSLPlotable.h'
**
** Created: Wed Mar 20 15:44:45 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLPlotable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLPlotable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLPlotable[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      33,   12,   12,   12, 0x05,
      47,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   63,   12,   12, 0x0a,
      88,   85,   12,   12, 0x0a,
     104,  101,   12,   12, 0x0a,
     125,  121,   12,   12, 0x0a,
     145,  142,   12,   12, 0x0a,
     162,  142,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSLPlotable[] = {
    "QSLPlotable\0\0appearenceChanged()\0"
    "dataChanged()\0rangesChanged()\0tit\0"
    "setTitle(QString)\0pn\0setPen(QPen)\0br\0"
    "setBrush(QBrush)\0col\0setColor(QColor)\0"
    "on\0setVisible(bool)\0setAntialiased(bool)\0"
};

void QSLPlotable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLPlotable *_t = static_cast<QSLPlotable *>(_o);
        switch (_id) {
        case 0: _t->appearenceChanged(); break;
        case 1: _t->dataChanged(); break;
        case 2: _t->rangesChanged(); break;
        case 3: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 5: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 6: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setAntialiased((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLPlotable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLPlotable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSLPlotable,
      qt_meta_data_QSLPlotable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLPlotable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLPlotable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLPlotable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLPlotable))
        return static_cast<void*>(const_cast< QSLPlotable*>(this));
    return QObject::qt_metacast(_clname);
}

int QSLPlotable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QSLPlotable::appearenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSLPlotable::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QSLPlotable::rangesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
