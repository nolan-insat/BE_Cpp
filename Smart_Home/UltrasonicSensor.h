#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "Sensor.h"
#include <Arduino.h>

class UltrasonicSensor : public Sensor {
private:
    int sigPin;
public:
    UltrasonicSensor(int sigPin);
    UltrasonicSensor(int sigPin, String name);

    void init();
    void deactivate();

    float readDistance();
    bool isObjectDetected(float maxDistance = 100.0);

    int getSigPin() const;
};

/*
#include "Sensor.h"

class UltrasonicSensor : public Sensor {
private:
    int echoPin;  
    
public:
    UltrasonicSensor(int triggerPin, int echoPin);
    UltrasonicSensor(int triggerPin, int echoPin, String name);
    
    void init();
    void deactivate();
    
    float readDistance();
    bool isObjectDetected(float maxDistance = 100.0);  // D�tection objet
    
    int getEchoPin() const;
};

*/

#endif