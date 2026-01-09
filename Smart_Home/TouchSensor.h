#ifndef TOUCH_SENSOR_H_
#define TOUCH_SENSOR_H_

#include <iostream>
#include "Sensor.h"

using namespace std;

class TouchSensor : public Sensor {
private:
    bool lastState;
    unsigned long lastChangeTime;
    
public:
    // Constructeurs
    TouchSensor(int pin);
    TouchSensor(int pin, string name);
    
    void initialize();
    void deactivate();
    
    bool isTouched();    
    bool isPressed();          
    bool isReleased();      // Détection relâchement

};

#endif