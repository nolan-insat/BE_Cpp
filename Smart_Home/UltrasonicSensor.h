#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "Sensor.h"

class UltrasonicSensor : public Sensor {
private:
    int echoPin;  
    
public:
    UltrasonicSensor(int triggerPin, int echoPin);
    UltrasonicSensor(int triggerPin, int echoPin, string name);
    
    void initialize();
    void deactivate();
    
    float readDistance();
    bool isObjectDetected(float maxDistance = 100.0);  // Détection objet
    
    int getEchoPin();
};

#endif