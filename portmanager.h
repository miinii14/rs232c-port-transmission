#ifndef PORTMANAGER_H
#define PORTMANAGER_H

#include <QObject>
#include <windows.h>
#include <QUrl>


class PortManager : public QObject
{
    Q_OBJECT
public:

    DCB dcb;
    void* hCommDev;
    std::string input;
    std::string path;
    char* buffer;
    std::vector<char> binaryBuffer;

    explicit PortManager(QObject *parent = nullptr);
    ~PortManager();

    Q_INVOKABLE QString openSerialPort(unsigned int portNumber, unsigned int baudRate, unsigned int parity, unsigned int stopBits, unsigned int byteSize);
    Q_INVOKABLE QString writeSerialPort();
    Q_INVOKABLE QString writeSerialPortBinary();
    Q_INVOKABLE QString readSerialPort();
    Q_INVOKABLE QString readSerialPortBinary();
    Q_INVOKABLE void closeSerialPort();
    Q_INVOKABLE QString readFromFile();
    Q_INVOKABLE QString readFromBinaryFile();
    Q_INVOKABLE std::string openFileDialog();
    Q_INVOKABLE QString getInput();
    Q_INVOKABLE QString getPath();
    Q_INVOKABLE QString getBuffer();
    Q_INVOKABLE QUrl getImageUrl();
    Q_INVOKABLE QUrl getImageOutputUrl();
    Q_INVOKABLE QString convertToImage();
    Q_INVOKABLE void setInput(QString string);
};

#endif
