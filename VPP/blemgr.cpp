#include "blemgr.h"

bleMgr::bleMgr(QObject* parent) : QObject(parent) {
    
}

bleMgr::~bleMgr() {

}

bool bleMgr::checkBLEPowerStt() {
    return false;
}

void bleMgr::deviceError(QLowEnergyController::Error error) {
    qDebug() << "QLowEnergyService::ServiceError: " << QString::number(error);
}

int bleMgr::init() {
    QByteArray arr;
    arr.append("");
    QLowEnergyAdvertisingData advertisingData;
    advertisingData.setDiscoverability(QLowEnergyAdvertisingData::DiscoverabilityGeneral);
    advertisingData.setIncludePowerLevel(true);
    advertisingData.setLocalName("myiphone");

    QLowEnergyCharacteristicData charData;
    charData.setUuid(QBluetoothUuid::HeartRateMeasurement);
    charData.setValue(arr);
    charData.setProperties(QLowEnergyCharacteristic::Notify);
    const QLowEnergyDescriptorData clientConfig(QBluetoothUuid::ClientCharacteristicConfiguration,
                                                arr);
    charData.addDescriptor(clientConfig);

    QLowEnergyServiceData serviceData;
    serviceData.setType(QLowEnergyServiceData::ServiceTypePrimary);
    serviceData.setUuid(QBluetoothUuid::HeartRate);
    serviceData.addCharacteristic(charData);

    const QScopedPointer<QLowEnergyController> leController(QLowEnergyController::createPeripheral());
    
    leController->addService(serviceData);
    leController->startAdvertising(QLowEnergyAdvertisingParameters(), advertisingData,
                                   advertisingData);
    auto reconnect = [&leController, advertisingData]() {
        leController->startAdvertising(QLowEnergyAdvertisingParameters(), advertisingData,
                                       advertisingData);
    };
    QObject::connect(leController.data(), &QLowEnergyController::disconnected, reconnect);
    return 0;
}

int bleMgr::advertise(const QString &ble_address) {
    qDebug() << "ble address: " << ble_address;
    QString name = ble_address;
    name = name.replace(":","");
    QByteArray arr;
    arr.append("");
    QLowEnergyAdvertisingData advertisingData;
    advertisingData.setDiscoverability(QLowEnergyAdvertisingData::DiscoverabilityGeneral);
    advertisingData.setIncludePowerLevel(true);
    advertisingData.setLocalName(name);

    QLowEnergyCharacteristicData charData;
    charData.setUuid(QBluetoothUuid::HeartRateMeasurement);
    charData.setValue(arr);
    charData.setProperties(QLowEnergyCharacteristic::Notify);
    const QLowEnergyDescriptorData clientConfig(QBluetoothUuid::ClientCharacteristicConfiguration,
                                                arr);
    charData.addDescriptor(clientConfig);

    QLowEnergyServiceData serviceData;
    serviceData.setType(QLowEnergyServiceData::ServiceTypePrimary);
    serviceData.setUuid(QBluetoothUuid::HeartRate);
    serviceData.addCharacteristic(charData);

    const QScopedPointer<QLowEnergyController> leController(QLowEnergyController::createPeripheral());
    leController->addService(serviceData);
    leController->startAdvertising(QLowEnergyAdvertisingParameters(), advertisingData,
                                   advertisingData);
    auto reconnect = [&leController, advertisingData]() {
        leController->startAdvertising(QLowEnergyAdvertisingParameters(), advertisingData,
                                       advertisingData);
    };
    QObject::connect(leController.data(), &QLowEnergyController::disconnected, reconnect);
    count_adv = 0;
    emit backMainPage();
    while (1) {
        qDebug() << "start sleep";
        count_adv += 1;

        QThread::msleep(500);
       if(count_adv >= 1) {
            count_adv = 0;
            leController->stopAdvertising();
            break;
        }
    }
    qDebug() << "stop sleep";
    return 0;
}
