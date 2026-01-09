#ifndef DEVICE_H_
#define DEVICE_H_

#include <Arduino.h>
#include <iostream>

class Device {

protected :
    static int DeviceCount;
    String name;
    int pin;
    bool isActive;

public :
    Device(int pin);
    Device(int pin, String name);
    ~Device();

    virtual void init() = 0;
    virtual void deactivate() = 0;
    virtual void activate() = 0;

    int getDeviceCount();

    //Getteurs
    virtual String getName() = 0;
    virtual int getPin() = 0;
    virtual bool getIsActive() = 0;

    //Setteurs
    virtual void setName(String name) = 0;
    virtual void setPin(int pin) = 0;
};

#endif