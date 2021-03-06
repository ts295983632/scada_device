#ifndef SCADADEVICE_H
#define SCADADEVICE_H
#include "packet.h"
#include <QTcpSocket>

enum deviceState_enum
{
    STATE_ON,
    STATE_OFF,
    STATE_ERROR
};

class ScadaDevice
{
public:
    explicit ScadaDevice();
    ~ScadaDevice();

    virtual Packet getInitPacket() = 0;
    virtual Packet getDataPacket() = 0;
    Packet getSettingsPacket();
    virtual bool initReceived(Packet* init) = 0;
    virtual bool dataReceived(Packet* data) = 0;
    bool settingsReceived(Packet* settings);
    int getUUID();
protected:
    QString name;
    QString factoryData;
    deviceState_enum deviceState;
    int uuid;


};

#endif // SCADADEVICE_H
