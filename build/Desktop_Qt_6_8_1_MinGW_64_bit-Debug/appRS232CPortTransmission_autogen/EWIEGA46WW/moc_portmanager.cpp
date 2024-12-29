/****************************************************************************
** Meta object code from reading C++ file 'portmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../portmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'portmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN11PortManagerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN11PortManagerE = QtMocHelpers::stringData(
    "PortManager",
    "openSerialPort",
    "",
    "portNumber",
    "baudRate",
    "parity",
    "stopBits",
    "byteSize",
    "writeSerialPort",
    "writeSerialPortBinary",
    "readSerialPort",
    "readSerialPortBinary",
    "closeSerialPort",
    "readFromFile",
    "readFromBinaryFile",
    "openFileDialog",
    "std::string",
    "getInput",
    "getPath",
    "getBuffer",
    "getImageUrl",
    "getImageOutputUrl",
    "convertToImage",
    "setInput",
    "string"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN11PortManagerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,  110,    2, 0x02,    1 /* Public */,
       8,    0,  121,    2, 0x02,    7 /* Public */,
       9,    0,  122,    2, 0x02,    8 /* Public */,
      10,    0,  123,    2, 0x02,    9 /* Public */,
      11,    0,  124,    2, 0x02,   10 /* Public */,
      12,    0,  125,    2, 0x02,   11 /* Public */,
      13,    0,  126,    2, 0x02,   12 /* Public */,
      14,    0,  127,    2, 0x02,   13 /* Public */,
      15,    0,  128,    2, 0x02,   14 /* Public */,
      17,    0,  129,    2, 0x02,   15 /* Public */,
      18,    0,  130,    2, 0x02,   16 /* Public */,
      19,    0,  131,    2, 0x02,   17 /* Public */,
      20,    0,  132,    2, 0x02,   18 /* Public */,
      21,    0,  133,    2, 0x02,   19 /* Public */,
      22,    0,  134,    2, 0x02,   20 /* Public */,
      23,    1,  135,    2, 0x02,   21 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,    6,    7,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    0x80000000 | 16,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QUrl,
    QMetaType::QUrl,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

Q_CONSTINIT const QMetaObject PortManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN11PortManagerE.offsetsAndSizes,
    qt_meta_data_ZN11PortManagerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN11PortManagerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PortManager, std::true_type>,
        // method 'openSerialPort'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'writeSerialPort'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'writeSerialPortBinary'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readSerialPort'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readSerialPortBinary'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'closeSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readFromFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readFromBinaryFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'openFileDialog'
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'getInput'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getPath'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getBuffer'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getImageUrl'
        QtPrivate::TypeAndForceComplete<QUrl, std::false_type>,
        // method 'getImageOutputUrl'
        QtPrivate::TypeAndForceComplete<QUrl, std::false_type>,
        // method 'convertToImage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void PortManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PortManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->openSerialPort((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->writeSerialPort();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->writeSerialPortBinary();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->readSerialPort();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->readSerialPortBinary();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->closeSerialPort(); break;
        case 6: { QString _r = _t->readFromFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->readFromBinaryFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { std::string _r = _t->openFileDialog();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getInput();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->getPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getBuffer();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QUrl _r = _t->getImageUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 13: { QUrl _r = _t->getImageOutputUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->convertToImage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setInput((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *PortManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PortManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN11PortManagerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PortManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
