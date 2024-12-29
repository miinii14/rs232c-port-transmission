#include "portmanager.h"
#include <QObject>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <QDebug>
#include <QImageReader>
#include <QBuffer>
#include <QFileInfo>
#include <cstring>
#include <QUrl>


PortManager::PortManager(QObject *parent) : QObject(parent) {}
PortManager::~PortManager(){}

QString PortManager::openSerialPort(unsigned int portNumber, unsigned int baudRate, unsigned int parity, unsigned int stopBits, unsigned int byteSize){
    LPCWSTR portName;
    unsigned long fdwEvtMask;

    switch(portNumber) {
    case 1:
        portName = L"COM1";
        break;
    case 2:
        portName = L"COM2";
        break;
    case 3:
        portName = L"COM3";
        break;
    case 4:
        portName = L"COM4";
        break;
    case 5:
        portName = L"COM5";
        break;
    case 6:
        portName = L"COM6";
        break;
    case 7:
        portName = L"COM7";
        break;

    default:
        return QString::fromStdString("Port number is null or incorrect");
    }

    hCommDev = CreateFile (portName, GENERIC_READ | GENERIC_WRITE, 0, NULL,OPEN_EXISTING, 0, NULL);
    if (hCommDev != INVALID_HANDLE_VALUE) {
        GetCommState(hCommDev, &dcb);

        switch(baudRate) {
        case 110:
            dcb.BaudRate = CBR_110;
            break;
        case 300:
            dcb.BaudRate = CBR_300;
            break;
        case 600:
            dcb.BaudRate = CBR_600;
            break;
        case 1200:
            dcb.BaudRate = CBR_1200;
            break;
        case 2400:
            dcb.BaudRate = CBR_2400;
            break;
        case 4800:
            dcb.BaudRate = CBR_4800;
            break;
        case 9600:
            dcb.BaudRate = CBR_9600;
            break;
        case 19200:
            dcb.BaudRate = CBR_19200;
            break;
        case 38400:
            dcb.BaudRate = CBR_38400;
            break;
        case 57600:
            dcb.BaudRate = CBR_57600;
            break;
        case 115200:
            dcb.BaudRate = CBR_115200;
            break;
        case 128000:
            dcb.BaudRate = CBR_128000;
            break;
        case 256000:
            dcb.BaudRate = CBR_256000;
            break;
        default:
            return QString::fromStdString("Baud rate is null or incorrect");
        }

        switch(parity) {
        case 0:
            dcb.Parity = NOPARITY;
            break;
        case 1:
            dcb.Parity = ODDPARITY;
            break;
        case 2:
            dcb.Parity = EVENPARITY;
            break;
        case 3:
            dcb.Parity = MARKPARITY;
            break;
        case 4:
            dcb.Parity = SPACEPARITY;
            break;
        default:
            return QString::fromStdString("Parity is null or incorrect");
        }

        switch (stopBits) {
        case 0:
            dcb.StopBits = ONESTOPBIT;
            break;
        case 1:
            dcb.StopBits = ONE5STOPBITS;
            break;
        case 2:
            dcb.StopBits = TWOSTOPBITS;
            break;
        default:
            return QString::fromStdString("Stop bits are null or incorrect");
        }

        if(byteSize < 5 || byteSize > 8) {
            return QString::fromStdString("Byte size is null or incorrect");
        }
        dcb.ByteSize = byteSize;

        dcb.DCBlength = sizeof(dcb);
        dcb.fParity = TRUE;
        dcb.fDtrControl = DTR_CONTROL_DISABLE;
        dcb.fRtsControl = RTS_CONTROL_DISABLE;

        SetCommState(hCommDev, &dcb);
        GetCommMask(hCommDev, &fdwEvtMask);
        SetCommMask(hCommDev, EV_TXEMPTY);

        return QString::fromStdString("Success");
    }

    return QString::fromStdString("Create file error");
}

std::string PortManager::openFileDialog() {
    wchar_t filename[MAX_PATH] = L"";
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"All Files\0*.*\0Text Files\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.to_bytes(ofn.lpstrFile);
    }

    return "";
}

QString PortManager::readFromFile() {

    path = PortManager::openFileDialog();
    std::ifstream inFile(path);

    inFile.seekg(0, std::ios::end);
    size_t size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    if (!inFile) {
        return QString::fromStdString("Open file error");
    }

    input.resize(size);

    inFile.read(&input[0], size);

    inFile.close();

    return QString::fromStdString("Success");
}

QString PortManager::readFromBinaryFile() {
    path = PortManager::openFileDialog();
    std::ifstream inFile(path, std::ios::binary);

    if(!inFile.is_open()) {
        return QString::fromStdString("Read binary file error");
    }

    inFile.seekg(0, std::ios::end);
    size_t size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    std::vector<char> buf(size);

    inFile.read(buf.data(), size);
    inFile.close();

    binaryBuffer = buf;

    return QString::fromStdString("Success");
}

QString PortManager::writeSerialPort(){
    unsigned long lpEvtMask;
    unsigned long bytesWritten = 0;

    unsigned long long bufferSize = input.size()+1;
    buffer = new char[bufferSize];
    strcpy(buffer, input.c_str());

    if(!WriteFile(hCommDev, (void*)buffer, bufferSize, &bytesWritten, NULL)) {
        return QString::fromStdString("Write serial port error");
    }

    return "Success";
}

QString PortManager::writeSerialPortBinary(){
    unsigned long long lpEvtMask;
    unsigned long long bytesWritten = 0;
    size_t chunkSize = 4000;

    for (size_t offset = 0; offset < binaryBuffer.size(); offset += chunkSize) {
        size_t currentChunkSize = std::min(chunkSize, binaryBuffer.size() - offset);
        DWORD written = 0;

        if (!WriteFile(hCommDev, binaryBuffer.data() + offset, currentChunkSize, &written, NULL)) {
            DWORD error = GetLastError();
            return QString::fromStdString("Write error at offset " + std::to_string(offset) + ". Error: " + std::to_string(error));
        }

        bytesWritten += written;
    }


    return QString::fromStdString("Success");
}

QString PortManager::readSerialPort(){
    unsigned long bytesRead = 0;

    unsigned long long bufferSize = input.size()+1;

    if(!ReadFile(hCommDev, (void*)buffer, bufferSize, &bytesRead, NULL)) {
        return "Read serial port error";
    }

    return QString::fromStdString("Success");
}

QString PortManager::readSerialPortBinary(){
    size_t chunkSize = 4000;
    size_t size = binaryBuffer.size();
    binaryBuffer.clear();

    for (size_t offset = 0; offset < size; offset += chunkSize) {
        size_t currentChunkSize = std::min(chunkSize, size - offset);
        std::vector<char> tempBuffer(currentChunkSize);
        DWORD bytesActuallyRead = 0;

        if (!ReadFile(hCommDev, tempBuffer.data(), currentChunkSize, &bytesActuallyRead, NULL)) {
            DWORD error = GetLastError();
            return QString::fromStdString("Read error at offset " + std::to_string(offset) + ". Error: " + std::to_string(error));
        }

        binaryBuffer.insert(binaryBuffer.end(), tempBuffer.begin(), tempBuffer.begin() + bytesActuallyRead);

        if (bytesActuallyRead < currentChunkSize) {
            break;
        }
    }

    return QString::fromStdString("Success");
}

QString PortManager::getInput(){
    return QString::fromStdString(input);
}

QString PortManager::getPath(){
    return QString::fromStdString(path);
}

QString PortManager::getBuffer(){
    return QString::fromStdString(std::string(buffer));
}

QUrl PortManager::getImageUrl(){
    return QUrl::fromLocalFile(QString::fromStdString(path)).toString();
}

QUrl PortManager::getImageOutputUrl(){
    std::string extention = path.substr(path.rfind('.'));
    return QUrl::fromLocalFile(QString::fromStdString(path+extention)).toString();
}

QString PortManager::convertToImage(){
    std::string extention = path.substr(path.rfind('.'));
    std::ofstream outputFile(path+extention, std::ios::binary);
    if(!outputFile){
        return QString::fromStdString("Output file not found");
    }

    outputFile.write(binaryBuffer.data(), binaryBuffer.size());
    if(!outputFile){
        return QString::fromStdString("Writing file error");
    }

    return QString::fromStdString("Success");
}

void PortManager::setInput(QString string){
    input = string.toStdString();
}

void PortManager::closeSerialPort(){
    if(hCommDev != NULL){
        CloseHandle(hCommDev);
    }
}
