#ifndef DEVICE_H_
#define DEVICE_H_

#include <iostream>

using namespace std;

class Device {

protected :
    static int DeviceCount;
    string name;
    int pin;
    bool isActive;

public :
    Device(int pin);
    Device(int pin, string name);
    ~Device();

    virtual void init() = 0;
    virtual void deactivate() = 0;
    virtual void activate() = 0;

    int getDeviceCount();

    //Getteurs
    virtual string getName() = 0;
    virtual int getPin() = 0;
    virtual bool getIsActive() = 0;

    //Setteurs
    virtual void setName(string name) = 0;
    virtual void setPin(int pin) = 0;
};

#endif