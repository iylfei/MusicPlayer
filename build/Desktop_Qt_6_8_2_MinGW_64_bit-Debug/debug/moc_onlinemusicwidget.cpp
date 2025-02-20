/****************************************************************************
** Meta object code from reading C++ file 'onlinemusicwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../onlinemusicwidget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'onlinemusicwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN17OnlineMusicWidgetE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN17OnlineMusicWidgetE = QtMocHelpers::stringData(
    "OnlineMusicWidget",
    "on_closeButton_clicked",
    "",
    "on_minButton_clicked",
    "on_playButton_clicked",
    "onSliderPressed",
    "onSliderReleased",
    "onSliderValueChanged",
    "value",
    "on_volumeSlider_valueChanged",
    "volume",
    "updateProgress",
    "position",
    "on_volumeButton_clicked",
    "on_addButton_clicked",
    "on_localMusicListButton_clicked",
    "onLocalMusicDoubleClicked",
    "QListWidgetItem*",
    "item",
    "scrollText",
    "on_nextButton_clicked",
    "on_prevButton_clicked",
    "addToPlaylist",
    "songPath",
    "on_optionsButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN17OnlineMusicWidgetE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    1 /* Private */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    1,  121,    2, 0x08,    6 /* Private */,
       9,    1,  124,    2, 0x08,    8 /* Private */,
      11,    1,  127,    2, 0x08,   10 /* Private */,
      13,    0,  130,    2, 0x08,   12 /* Private */,
      14,    0,  131,    2, 0x08,   13 /* Private */,
      15,    0,  132,    2, 0x08,   14 /* Private */,
      16,    1,  133,    2, 0x08,   15 /* Private */,
      19,    0,  136,    2, 0x08,   17 /* Private */,
      20,    0,  137,    2, 0x08,   18 /* Private */,
      21,    0,  138,    2, 0x08,   19 /* Private */,
      22,    1,  139,    2, 0x08,   20 /* Private */,
      24,    0,  142,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject OnlineMusicWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN17OnlineMusicWidgetE.offsetsAndSizes,
    qt_meta_data_ZN17OnlineMusicWidgetE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN17OnlineMusicWidgetE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OnlineMusicWidget, std::true_type>,
        // method 'on_closeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_minButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_playButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSliderValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_volumeSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'on_volumeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_localMusicListButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLocalMusicDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'scrollText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_nextButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_prevButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_optionsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void OnlineMusicWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<OnlineMusicWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_closeButton_clicked(); break;
        case 1: _t->on_minButton_clicked(); break;
        case 2: _t->on_playButton_clicked(); break;
        case 3: _t->onSliderPressed(); break;
        case 4: _t->onSliderReleased(); break;
        case 5: _t->onSliderValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_volumeSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->on_volumeButton_clicked(); break;
        case 9: _t->on_addButton_clicked(); break;
        case 10: _t->on_localMusicListButton_clicked(); break;
        case 11: _t->onLocalMusicDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 12: _t->scrollText(); break;
        case 13: _t->on_nextButton_clicked(); break;
        case 14: _t->on_prevButton_clicked(); break;
        case 15: _t->addToPlaylist((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->on_optionsButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *OnlineMusicWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnlineMusicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN17OnlineMusicWidgetE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OnlineMusicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
