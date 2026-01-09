#ifndef SENSOR_H_
#define SENSOR_H_

#include "Device.h"
#include <iostream>

class Sensor : public Device {

protected :
    static int SensorCount;

public :
    Sensor(int pin);
    Sensor(int pin, String name);
    ~Sensor();
    //Getteurs
    virtual String getName();
    virtual int getPin();
    virtual bool getIsActive();

    //Setteurs
    virtual void setName(String name);
    virtual void setPin(int pin);
    virtual void activate();
    virtual void deactivate();
};


#endif