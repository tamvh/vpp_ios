#ifndef BLEMGR_H
#define BLEMGR_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/qlowenergyadvertisingdata.h>
#include <QtBluetooth/qlowenergyadvertisingparameters.h>
#include <QtBluetooth/qlowenergycharacteristic.h>
#include <QtBluetooth/qlowenergycharacteristicdata.h>
#include <QtBluetooth/qlowenergydescriptordata.h>
#include <QtBluetooth/qlowenergycontroller.h>
#include <QtBluetooth/qlowenergyservice.h>
#include <QtBluetooth/qlowenergyservicedata.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qlist.h>
#include <QtCore/qloggingcategory.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qtimer.h>

class bleMgr : public QObject
{
    Q_OBJECT
public:
    bleMgr(QObject* parent = 0);
    virtual ~bleMgr();
public:
    Q_INVOKABLE int advertise(const QString& ble_address);
    Q_INVOKABLE int init();
    Q_INVOKABLE bool checkBLEPowerStt();
public:

signals:
    void backMainPage();
private slots:
    void deviceError(QLowEnergyController::Error);
private:
    int count_adv;
};

#endif // BLEMGR_H
