/****************************************************************************
** Meta object code from reading C++ file 'QSLFitEngine.h'
**
** Created: Wed Mar 20 14:35:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/QSLFitEngine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSLFitEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSLFitEngine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      29,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   13,   13,   13, 0x0a,
      65,   55,   13,   13, 0x0a,
      87,   13,   13,   13, 0x0a,
     110,  100,   13,   13, 0x0a,
     161,  157,   13,   13, 0x0a,
     199,  195,   13,   13, 0x0a,
     228,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSLFitEngine[] = {
    "QSLFitEngine\0\0errorOcurred()\0"
    "sucessfulSolved()\0solve()\0i,enabled\0"
    "setFitParam(int,bool)\0setNoSigma()\0"
    "xdat,ydat\0setData(QSLArray1D<double>,QSLArray1D<double>)\0"
    "par\0setParameters(QSLArray1D<double>)\0"
    "sig\0setSigma(QSLArray1D<double>)\0"
    "setFitAll()\0"
};

void QSLFitEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSLFitEngine *_t = static_cast<QSLFitEngine *>(_o);
        switch (_id) {
        case 0: _t->errorOcurred(); break;
        case 1: _t->sucessfulSolved(); break;
        case 2: _t->solve(); break;
        case 3: _t->setFitParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setNoSigma(); break;
        case 5: _t->setData((*reinterpret_cast< const QSLArray1D<double>(*)>(_a[1])),(*reinterpret_cast< const QSLArray1D<double>(*)>(_a[2]))); break;
        case 6: _t->setParameters((*reinterpret_cast< const QSLArray1D<double>(*)>(_a[1]))); break;
        case 7: _t->setSigma((*reinterpret_cast< const QSLArray1D<double>(*)>(_a[1]))); break;
        case 8: _t->setFitAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSLFitEngine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSLFitEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSLFitEngine,
      qt_meta_data_QSLFitEngine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSLFitEngine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSLFitEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSLFitEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSLFitEngine))
        return static_cast<void*>(const_cast< QSLFitEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int QSLFitEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QSLFitEngine::errorOcurred()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSLFitEngine::sucessfulSolved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
