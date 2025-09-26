#ifndef SERIALGPS_H
#define SERIALGPS_H
#include "dummy.h"
// #include <QObject>
// #include <QSerialPort>
// #include <QSerialPortInfo>
// #include <QDebug>
// #include <QThread>

class SerialGPS : public QObject
{
    Q_OBJECT
public:
    //explicit SerialGPS(QObject *parent = nullptr);
    SerialGPS();


signals:

public slots:
    void ConnectToSerialPort();
public:
    QSerialPort m_serial;
};

#endif // SERIALGPS_H
