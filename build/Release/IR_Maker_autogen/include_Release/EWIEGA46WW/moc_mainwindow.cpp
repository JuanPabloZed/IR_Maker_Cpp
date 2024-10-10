/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../mainwindow.h"
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
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "limXZoomIR",
    "",
    "QCPRange",
    "limXZoomFreq",
    "limYZoomFreq",
    "on_createir_button_clicked",
    "on_browsesweep_button_clicked",
    "on_treeView_clicked",
    "QModelIndex",
    "index",
    "on_customsave_radio_toggled",
    "checked",
    "on_autosr_check_stateChanged",
    "arg1",
    "on_files_list_clicked",
    "on_browseout_button_clicked",
    "on_about_button_clicked",
    "on_autosave_radio_toggled",
    "on_srate_textChanged",
    "on_sweepgen_button_clicked",
    "on_playir_button_clicked",
    "on_irlengthbox_stateChanged",
    "on_trimbox_stateChanged",
    "on_showgraphsbox_stateChanged",
    "on_testsound_clicked",
    "on_testir_clicked",
    "on_irlengthSamples_editingFinished",
    "on_irlength_editingFinished",
    "on_irlengthSamples_textChanged",
    "on_fullrangebox_stateChanged",
    "on_begfreq_textChanged",
    "on_endfreq_textChanged",
    "on_CutTailBox_stateChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[68];
    char stringdata0[11];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[27];
    char stringdata7[30];
    char stringdata8[20];
    char stringdata9[12];
    char stringdata10[6];
    char stringdata11[28];
    char stringdata12[8];
    char stringdata13[29];
    char stringdata14[5];
    char stringdata15[22];
    char stringdata16[28];
    char stringdata17[24];
    char stringdata18[26];
    char stringdata19[21];
    char stringdata20[27];
    char stringdata21[25];
    char stringdata22[28];
    char stringdata23[24];
    char stringdata24[30];
    char stringdata25[21];
    char stringdata26[18];
    char stringdata27[35];
    char stringdata28[28];
    char stringdata29[31];
    char stringdata30[29];
    char stringdata31[23];
    char stringdata32[23];
    char stringdata33[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 10),  // "limXZoomIR"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 8),  // "QCPRange"
        QT_MOC_LITERAL(32, 12),  // "limXZoomFreq"
        QT_MOC_LITERAL(45, 12),  // "limYZoomFreq"
        QT_MOC_LITERAL(58, 26),  // "on_createir_button_clicked"
        QT_MOC_LITERAL(85, 29),  // "on_browsesweep_button_clicked"
        QT_MOC_LITERAL(115, 19),  // "on_treeView_clicked"
        QT_MOC_LITERAL(135, 11),  // "QModelIndex"
        QT_MOC_LITERAL(147, 5),  // "index"
        QT_MOC_LITERAL(153, 27),  // "on_customsave_radio_toggled"
        QT_MOC_LITERAL(181, 7),  // "checked"
        QT_MOC_LITERAL(189, 28),  // "on_autosr_check_stateChanged"
        QT_MOC_LITERAL(218, 4),  // "arg1"
        QT_MOC_LITERAL(223, 21),  // "on_files_list_clicked"
        QT_MOC_LITERAL(245, 27),  // "on_browseout_button_clicked"
        QT_MOC_LITERAL(273, 23),  // "on_about_button_clicked"
        QT_MOC_LITERAL(297, 25),  // "on_autosave_radio_toggled"
        QT_MOC_LITERAL(323, 20),  // "on_srate_textChanged"
        QT_MOC_LITERAL(344, 26),  // "on_sweepgen_button_clicked"
        QT_MOC_LITERAL(371, 24),  // "on_playir_button_clicked"
        QT_MOC_LITERAL(396, 27),  // "on_irlengthbox_stateChanged"
        QT_MOC_LITERAL(424, 23),  // "on_trimbox_stateChanged"
        QT_MOC_LITERAL(448, 29),  // "on_showgraphsbox_stateChanged"
        QT_MOC_LITERAL(478, 20),  // "on_testsound_clicked"
        QT_MOC_LITERAL(499, 17),  // "on_testir_clicked"
        QT_MOC_LITERAL(517, 34),  // "on_irlengthSamples_editingFin..."
        QT_MOC_LITERAL(552, 27),  // "on_irlength_editingFinished"
        QT_MOC_LITERAL(580, 30),  // "on_irlengthSamples_textChanged"
        QT_MOC_LITERAL(611, 28),  // "on_fullrangebox_stateChanged"
        QT_MOC_LITERAL(640, 22),  // "on_begfreq_textChanged"
        QT_MOC_LITERAL(663, 22),  // "on_endfreq_textChanged"
        QT_MOC_LITERAL(686, 26)   // "on_CutTailBox_stateChanged"
    },
    "MainWindow",
    "limXZoomIR",
    "",
    "QCPRange",
    "limXZoomFreq",
    "limYZoomFreq",
    "on_createir_button_clicked",
    "on_browsesweep_button_clicked",
    "on_treeView_clicked",
    "QModelIndex",
    "index",
    "on_customsave_radio_toggled",
    "checked",
    "on_autosr_check_stateChanged",
    "arg1",
    "on_files_list_clicked",
    "on_browseout_button_clicked",
    "on_about_button_clicked",
    "on_autosave_radio_toggled",
    "on_srate_textChanged",
    "on_sweepgen_button_clicked",
    "on_playir_button_clicked",
    "on_irlengthbox_stateChanged",
    "on_trimbox_stateChanged",
    "on_showgraphsbox_stateChanged",
    "on_testsound_clicked",
    "on_testir_clicked",
    "on_irlengthSamples_editingFinished",
    "on_irlength_editingFinished",
    "on_irlengthSamples_textChanged",
    "on_fullrangebox_stateChanged",
    "on_begfreq_textChanged",
    "on_endfreq_textChanged",
    "on_CutTailBox_stateChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  176,    2, 0x08,    1 /* Private */,
       4,    1,  179,    2, 0x08,    3 /* Private */,
       5,    1,  182,    2, 0x08,    5 /* Private */,
       6,    0,  185,    2, 0x08,    7 /* Private */,
       7,    0,  186,    2, 0x08,    8 /* Private */,
       8,    1,  187,    2, 0x08,    9 /* Private */,
      11,    1,  190,    2, 0x08,   11 /* Private */,
      13,    1,  193,    2, 0x08,   13 /* Private */,
      15,    1,  196,    2, 0x08,   15 /* Private */,
      16,    0,  199,    2, 0x08,   17 /* Private */,
      17,    0,  200,    2, 0x08,   18 /* Private */,
      18,    1,  201,    2, 0x08,   19 /* Private */,
      19,    1,  204,    2, 0x08,   21 /* Private */,
      20,    0,  207,    2, 0x08,   23 /* Private */,
      21,    0,  208,    2, 0x08,   24 /* Private */,
      22,    1,  209,    2, 0x08,   25 /* Private */,
      23,    1,  212,    2, 0x08,   27 /* Private */,
      24,    1,  215,    2, 0x08,   29 /* Private */,
      25,    0,  218,    2, 0x08,   31 /* Private */,
      26,    0,  219,    2, 0x08,   32 /* Private */,
      27,    0,  220,    2, 0x08,   33 /* Private */,
      28,    0,  221,    2, 0x08,   34 /* Private */,
      29,    1,  222,    2, 0x08,   35 /* Private */,
      30,    1,  225,    2, 0x08,   37 /* Private */,
      31,    1,  228,    2, 0x08,   39 /* Private */,
      32,    1,  231,    2, 0x08,   41 /* Private */,
      33,    1,  234,    2, 0x08,   43 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'limXZoomIR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>,
        // method 'limXZoomFreq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>,
        // method 'limYZoomFreq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>,
        // method 'on_createir_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_browsesweep_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_treeView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_customsave_radio_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_autosr_check_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_files_list_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_browseout_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_about_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_autosave_radio_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_srate_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_sweepgen_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_playir_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_irlengthbox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_trimbox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_showgraphsbox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_testsound_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_testir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_irlengthSamples_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_irlength_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_irlengthSamples_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_fullrangebox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_begfreq_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_endfreq_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_CutTailBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->limXZoomIR((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 1: _t->limXZoomFreq((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 2: _t->limYZoomFreq((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 3: _t->on_createir_button_clicked(); break;
        case 4: _t->on_browsesweep_button_clicked(); break;
        case 5: _t->on_treeView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->on_customsave_radio_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_autosr_check_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_files_list_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->on_browseout_button_clicked(); break;
        case 10: _t->on_about_button_clicked(); break;
        case 11: _t->on_autosave_radio_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_srate_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->on_sweepgen_button_clicked(); break;
        case 14: _t->on_playir_button_clicked(); break;
        case 15: _t->on_irlengthbox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_trimbox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_showgraphsbox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_testsound_clicked(); break;
        case 19: _t->on_testir_clicked(); break;
        case 20: _t->on_irlengthSamples_editingFinished(); break;
        case 21: _t->on_irlength_editingFinished(); break;
        case 22: _t->on_irlengthSamples_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->on_fullrangebox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_begfreq_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_endfreq_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->on_CutTailBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
