#ifndef SENSOR_H_
#define SENSOR_H_

#include "Device.h"
#include <iostream>

class Sensor : public Device {

protected :
    static int SensorCount;

public :
    Sensor(int pin);
    Sensor(int pin, string name);

    //Getteurs
    virtual string getName();
    virtual int getPin();
    virtual bool getIsActive();

    //Setteurs
    virtual void setName(string name);
    virtual void setPin(int pin);
    virtual void activate();
    virtual void deactivate();
};


#endif