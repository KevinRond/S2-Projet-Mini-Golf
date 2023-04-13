/****************************************************************************
** Meta object code from reading C++ file 'FenetreTerrain.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FenetreTerrain.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenetreTerrain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_FenetreTerrain_t {
    uint offsetsAndSizes[20];
    char stringdata0[15];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[14];
    char stringdata5[14];
    char stringdata6[20];
    char stringdata7[19];
    char stringdata8[11];
    char stringdata9[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_FenetreTerrain_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_FenetreTerrain_t qt_meta_stringdata_FenetreTerrain = {
    {
        QT_MOC_LITERAL(0, 14),  // "FenetreTerrain"
        QT_MOC_LITERAL(15, 16),  // "b_retour_appuyer"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 21),  // "b_trouSuivant_appuyer"
        QT_MOC_LITERAL(55, 13),  // "b_fin_appuyer"
        QT_MOC_LITERAL(69, 13),  // "action_retour"
        QT_MOC_LITERAL(83, 19),  // "affiche_nom_fichier"
        QT_MOC_LITERAL(103, 18),  // "action_trouSuivant"
        QT_MOC_LITERAL(122, 10),  // "action_fin"
        QT_MOC_LITERAL(133, 5)   // "jouer"
    },
    "FenetreTerrain",
    "b_retour_appuyer",
    "",
    "b_trouSuivant_appuyer",
    "b_fin_appuyer",
    "action_retour",
    "affiche_nom_fichier",
    "action_trouSuivant",
    "action_fin",
    "jouer"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_FenetreTerrain[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FenetreTerrain::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FenetreTerrain.offsetsAndSizes,
    qt_meta_data_FenetreTerrain,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_FenetreTerrain_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FenetreTerrain, std::true_type>,
        // method 'b_retour_appuyer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'b_trouSuivant_appuyer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'b_fin_appuyer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'action_retour'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'affiche_nom_fichier'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'action_trouSuivant'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'action_fin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jouer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FenetreTerrain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenetreTerrain *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->b_retour_appuyer(); break;
        case 1: _t->b_trouSuivant_appuyer(); break;
        case 2: _t->b_fin_appuyer(); break;
        case 3: _t->action_retour(); break;
        case 4: _t->affiche_nom_fichier(); break;
        case 5: _t->action_trouSuivant(); break;
        case 6: _t->action_fin(); break;
        case 7: _t->jouer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenetreTerrain::*)();
            if (_t _q_method = &FenetreTerrain::b_retour_appuyer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FenetreTerrain::*)();
            if (_t _q_method = &FenetreTerrain::b_trouSuivant_appuyer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FenetreTerrain::*)();
            if (_t _q_method = &FenetreTerrain::b_fin_appuyer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *FenetreTerrain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetreTerrain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenetreTerrain.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FenetreTerrain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FenetreTerrain::b_retour_appuyer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FenetreTerrain::b_trouSuivant_appuyer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FenetreTerrain::b_fin_appuyer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
