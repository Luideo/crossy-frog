/****************************************************************************
** Meta object code from reading C++ file 'halloffame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CrossyFrog/halloffame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'halloffame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HallOfFame_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HallOfFame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HallOfFame_t qt_meta_stringdata_HallOfFame = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HallOfFame"
QT_MOC_LITERAL(1, 11, 9), // "mainTimer"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "animationTick"
QT_MOC_LITERAL(4, 36, 12), // "initDatabase"
QT_MOC_LITERAL(5, 49, 12), // "drawDatabase"
QT_MOC_LITERAL(6, 62, 9), // "QPainter*"
QT_MOC_LITERAL(7, 72, 10) // "itsPainter"

    },
    "HallOfFame\0mainTimer\0\0animationTick\0"
    "initDatabase\0drawDatabase\0QPainter*\0"
    "itsPainter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HallOfFame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void HallOfFame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HallOfFame *_t = static_cast<HallOfFame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mainTimer(); break;
        case 1: _t->animationTick(); break;
        case 2: { bool _r = _t->initDatabase();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->drawDatabase((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject HallOfFame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HallOfFame.data,
      qt_meta_data_HallOfFame,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HallOfFame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HallOfFame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HallOfFame.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HallOfFame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE