/****************************************************************************
** Meta object code from reading C++ file 'blemgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VPP/blemgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blemgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bleMgr_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bleMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bleMgr_t qt_meta_stringdata_bleMgr = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bleMgr"
QT_MOC_LITERAL(1, 7, 12), // "backMainPage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "deviceError"
QT_MOC_LITERAL(4, 33, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(5, 61, 9), // "advertise"
QT_MOC_LITERAL(6, 71, 11), // "ble_address"
QT_MOC_LITERAL(7, 83, 4), // "init"
QT_MOC_LITERAL(8, 88, 16) // "checkBLEPowerStt"

    },
    "bleMgr\0backMainPage\0\0deviceError\0"
    "QLowEnergyController::Error\0advertise\0"
    "ble_address\0init\0checkBLEPowerStt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bleMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x02 /* Public */,
       7,    0,   46,    2, 0x02 /* Public */,
       8,    0,   47,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,

 // methods: parameters
    QMetaType::Int, QMetaType::QString,    6,
    QMetaType::Int,
    QMetaType::Bool,

       0        // eod
};

void bleMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bleMgr *_t = static_cast<bleMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backMainPage(); break;
        case 1: _t->deviceError((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 2: { int _r = _t->advertise((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->init();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->checkBLEPowerStt();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bleMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bleMgr::backMainPage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject bleMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_bleMgr.data,
      qt_meta_data_bleMgr,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *bleMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bleMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bleMgr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int bleMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void bleMgr::backMainPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
