#ifndef TOUCH_SENSOR_H_
#define TOUCH_SENSOR_H_

#include <iostream>
#include "Sensor.h"


class TouchSensor : public Sensor {
private:
    bool lastState;
    unsigned long lastChangeTime;
    
public:
    // Constructeurs
    TouchSensor(int pin);
    TouchSensor(int pin, String name);
    
    void init();
    void deactivate();
    
    bool isTouched();    
    bool isPressed();          
    bool isReleased();      // D�tection rel�chement

};

#endif