#ifndef DUMMY_H
#define DUMMY_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstring>
#include <sstream>
#include <iomanip>

#define emit
// Dummy QObject
class QObject {
public:
    virtual ~QObject() = default;
};
template <typename T>
class QList : public std::vector<T> {
public:
    T at(size_t i) const { return this->operator[](i); }
    bool empty() const { return std::vector<T>::empty(); }
};





// Dummy QByteArray
class QByteArray {
public:
    QByteArray() = default;
    QByteArray(const std::string& s) { data = s; }
    std::string data;
    bool isEmpty() const { return data.empty(); }
    QByteArray mid(size_t pos, size_t len) const {
        return data.substr(pos, len);
    }

    size_t length() const { return data.length(); }
    size_t count() const { return data.length(); }
    QByteArray append(const std::string& s) {
        data += s;
        return *this;
    }

    QByteArray& operator=(const char* s) {
    data = std::string(s);
    return *this;
    }
    bool operator==(const QByteArray& rhs) const {
        return data == rhs.data;
    }

    QByteArray replace(const std::string& from, const std::string& to) {
        size_t pos = 0;
        while ((pos = data.find(from, pos)) != std::string::npos) {
            data.replace(pos, from.length(), to);
            pos += to.length();
        }
        return *this;
    }

    static QByteArray fromHex(const QByteArray& input) {
        std::string result;
        const std::string& s = input.data;
        for (size_t i = 0; i + 1 < s.length(); i += 2) {
            std::string byteString = s.substr(i, 2);
            char byte = (char) strtol(byteString.c_str(), nullptr, 16);
            result.push_back(byte);
        }
        return QByteArray(result);
    }

    QByteArray toHex() const {
    std::ostringstream oss;
    for (unsigned char c : data){
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
        return QByteArray(oss.str());

}

    friend QByteArray operator+(const QByteArray& lhs, const QByteArray& rhs) {
        return QByteArray(lhs.data + rhs.data);
    }


friend QByteArray operator+(const QByteArray& lhs, const char* rhs) {
    return QByteArray(lhs.data + std::string(rhs));
}

friend QByteArray operator+(const char* lhs, const QByteArray& rhs) {
    return QByteArray(std::string(lhs) + rhs.data);
}

friend QByteArray operator+(const QByteArray& lhs, const std::string& rhs) {
    return QByteArray(lhs.data + rhs);
}

friend QByteArray operator+(const std::string& lhs, const QByteArray& rhs) {
    return QByteArray(lhs + rhs.data);
}


    unsigned int toUInt(bool* ok, int base = 10) const {
        try {
            return std::stoul(data, nullptr, base);
        } catch (...) {
            *ok = false;
            return 0;
        }
    }

    char& operator[](size_t i) { return data[i]; }
    const char& operator[](size_t i) const { return data[i]; }

    bool operator!=(const std::string& rhs) const {
        return data != rhs;
    }

    bool operator==(const std::string& rhs) const {
        return data == rhs;
    }
};

class QThread {
public:
    QThread() {
        std::cout << "Dummy QThread created\n";
    }

    static void msleep(unsigned long msecs) {
        std::cout << "Dummy sleep for " << msecs << " ms\n";
    }

    void start() {
        std::cout << "Dummy QThread started\n";
    }
    void quit() {
        std::cout << "Dummy thread quit\n";
    }
};

// Dummy macros
#define Q_OBJECT
#define signals public
#define slots
#define SIGNAL(x) x
#define SLOT(x) x
#define connect(sender, signal, receiver, slot) \
    std::cout << "Dummy connect: " << #signal << " -> " << #slot << std::endl;


// Dummy SerialOBD
// class SerialOBD : public QObject {
// public:
//     void ConnectToSerialPort() {
//         std::cout << "SerialOBD::ConnectToSerialPort called\n";
//     }
//     void moveToThread(QThread* thread) {
//         std::cout << "SerialOBD moved to thread\n";
//     }
// };

// Dummy SerialGPS
// class SerialGPS : public QObject {
// public:
    
// };

// Dummy QSerialPort
class QSerialPort {
public:
    QSerialPort() {
        std::cout << "QSerialPort constructed\n";
    }

    // bool open(int mode = 0) {
    //     std::cout << "QSerialPort::open called\n";
    //     return true;
    // }

    void close() {
        std::cout << "QSerialPort::close called\n";
    }

    // void write(const std::string& data) {
    //     std::cout << "QSerialPort::write: " << data << "\n";
    // }

    // void write(const QByteArray& data) {
    //     std::cout << "QSerialPort::write: " << data.data << "\n";
    // }


    std::string readAll() {
        std::cout << "QSerialPort::readAll called\n";
        return "dummy data";
    }
     enum BaudRate { Baud38400 };
    enum DataBits { Data8 };
    enum Parity { NoParity };
    enum StopBits { OneStop };
    enum FlowControl { NoFlowControl };

    void setPortName(const std::string& name) {
        std::cout << "Set port name: " << name << "\n";
    }

    void setBaudRate(BaudRate) { std::cout << "Set baud rate\n"; }
    void setDataBits(DataBits) { std::cout << "Set data bits\n"; }
    void setParity(Parity)     { std::cout << "Set parity\n"; }
    void setStopBits(StopBits) { std::cout << "Set stop bits\n"; }
    void setFlowControl(FlowControl) { std::cout << "Set flow control\n"; }

    bool open(int) { std::cout << "Port opened\n"; return true; }

    void write(const std::string& data) {
        std::cout << "QSerialPort::write: " << data << "\n";
    }

    bool waitForBytesWritten(int) { return true; }
    bool waitForReadyRead(int) { return true; }

    // std::string readAll() {
    //     std::cout << "QSerialPort::readAll()\n";
    //     return "dummy OBD data";
    // }
};

// Dummy QStringLiteral macro
#define QStringLiteral(x) x

// Dummy QUrl
class QUrl {
public:
    QUrl(const char* url) {
        std::cout << "QUrl created: " << url << std::endl;
    }
};

// Dummy QGuiApplication
class QGuiApplication {
public:
    QGuiApplication(int& argc, char** argv) {
        std::cout << "QGuiApplication initialized with argc=" << argc << std::endl;
    }

    int exec() {
        std::cout << "QGuiApplication::exec() called" << std::endl;
        return 0;
    }
};

// Dummy QQmlApplicationEngine
class QQmlApplicationEngine {
public:
    class DummyContext {
    public:
        void setContextProperty(const char* name, void* obj) {
            std::cout << "Context property set: " << name << std::endl;
        }
    };

    DummyContext* rootContext() {
        std::cout << "Returning dummy context" << std::endl;
        return new DummyContext();
    }

    void load(const QUrl& url) {
        std::cout << "Loading QML from URL" << std::endl;
    }
};

class QRegExp {
public:
    QRegExp(const std::string& pattern) : regex(pattern) {}

    bool exactMatch(const QByteArray& input) {
        return true;
    }

private:
    std::string regex;
};

class QSerialPortInfo {
public:
    std::string portName() const { return "ttyUSB0"; }

    // static QList<QSerialPortInfo> availablePorts() {
    //     QList<QSerialPortInfo> ports;
    //     ports.push_back(QSerialPortInfo()); // chỉ giả lập 1 port
    //     return ports;
    // }
};

class QIODevice {
public:
    enum OpenModeFlag {
        NotOpen = 0x0000,
        ReadOnly = 0x0001,
        WriteOnly = 0x0002,
        ReadWrite = ReadOnly | WriteOnly
    };
};




#endif // DUMMY_H
