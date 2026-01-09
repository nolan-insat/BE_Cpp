#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

#include "Sensor.h"

class LightSensor : public Sensor {
private:
    int darkThreshold;  // Seuil : trop sombre
    
public:
    LightSensor(int pin);
    LightSensor(int pin, string name);
    
    void initialize();
    
    int getLightLevel();        // Retourne niveau lumière 0-1023
    bool isTooDark();           // lumière < darkThreshold
    bool isBright();           
    
    void setDarkThreshold(int t);
    int getDarkThreshold();
};

#endif