#ifndef ACTUATOR_H_
#define ACTUATOR_H_

#include "Device.h"

class Actuator : public Device {
    protected:
    static int ActuatorCount;
    public:

    // Constructeur
    Actuator(int pin) ;
    Actuator(int pin, string name);
    // Destructeur
    ~Actuator() ;

    int getActuatorCount();

    string getName();
    int getPin();
    bool getIsActive();

    void setName(string name);
    void setPin(int pin);


};

#endif