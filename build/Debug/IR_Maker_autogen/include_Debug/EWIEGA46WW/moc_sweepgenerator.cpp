/****************************************************************************
** Meta object code from reading C++ file 'sweepgenerator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../sweepgenerator.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sweepgenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSweepGeneratorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSweepGeneratorENDCLASS = QtMocHelpers::stringData(
    "SweepGenerator",
    "limXZoom",
    "",
    "QCPRange",
    "range",
    "on_save_button_clicked",
    "on_gen_button_clicked",
    "on_play_button_clicked",
    "on_srate_currentTextChanged",
    "arg1",
    "on_fullspectrumbox_stateChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSweepGeneratorENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[15];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[6];
    char stringdata5[23];
    char stringdata6[22];
    char stringdata7[23];
    char stringdata8[28];
    char stringdata9[5];
    char stringdata10[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSweepGeneratorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSweepGeneratorENDCLASS_t qt_meta_stringdata_CLASSSweepGeneratorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "SweepGenerator"
        QT_MOC_LITERAL(15, 8),  // "limXZoom"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 8),  // "QCPRange"
        QT_MOC_LITERAL(34, 5),  // "range"
        QT_MOC_LITERAL(40, 22),  // "on_save_button_clicked"
        QT_MOC_LITERAL(63, 21),  // "on_gen_button_clicked"
        QT_MOC_LITERAL(85, 22),  // "on_play_button_clicked"
        QT_MOC_LITERAL(108, 27),  // "on_srate_currentTextChanged"
        QT_MOC_LITERAL(136, 4),  // "arg1"
        QT_MOC_LITERAL(141, 31)   // "on_fullspectrumbox_stateChanged"
    },
    "SweepGenerator",
    "limXZoom",
    "",
    "QCPRange",
    "range",
    "on_save_button_clicked",
    "on_gen_button_clicked",
    "on_play_button_clicked",
    "on_srate_currentTextChanged",
    "arg1",
    "on_fullspectrumbox_stateChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSweepGeneratorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,
       8,    1,   56,    2, 0x08,    6 /* Private */,
      10,    1,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject SweepGenerator::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSSweepGeneratorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSweepGeneratorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSweepGeneratorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SweepGenerator, std::true_type>,
        // method 'limXZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>,
        // method 'on_save_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_gen_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_play_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_srate_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_fullspectrumbox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SweepGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SweepGenerator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->limXZoom((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 1: _t->on_save_button_clicked(); break;
        case 2: _t->on_gen_button_clicked(); break;
        case 3: _t->on_play_button_clicked(); break;
        case 4: _t->on_srate_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_fullspectrumbox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SweepGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SweepGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSweepGeneratorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SweepGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
