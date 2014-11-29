/****************************************************************************
** Meta object code from reading C++ file 'itemlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../itemlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'itemlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ItemListWidget_t {
    QByteArrayData data[9];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ItemListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ItemListWidget_t qt_meta_stringdata_ItemListWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 6),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 3),
QT_MOC_LITERAL(4, 27, 6),
QT_MOC_LITERAL(5, 34, 7),
QT_MOC_LITERAL(6, 42, 7),
QT_MOC_LITERAL(7, 50, 4),
QT_MOC_LITERAL(8, 55, 4)
    },
    "ItemListWidget\0equip0\0\0iid\0equip1\0"
    "remove0\0remove1\0next\0back"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ItemListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ItemListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ItemListWidget *_t = static_cast<ItemListWidget *>(_o);
        switch (_id) {
        case 0: _t->equip0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->equip1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->remove0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->remove1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->next(); break;
        case 5: _t->back(); break;
        default: ;
        }
    }
}

const QMetaObject ItemListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ItemListWidget.data,
      qt_meta_data_ItemListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ItemListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ItemListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ItemListWidget.stringdata))
        return static_cast<void*>(const_cast< ItemListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ItemListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
