#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

#include "Sensor.h"

class LightSensor : public Sensor {
private:
    int darkThreshold;  // Seuil : trop sombre
    
public:
    LightSensor(int pin);
    LightSensor(int pin, String name);
    
    void init();
    
    int getLightLevel();        // Retourne niveau lumi�re 0-1023
    bool isTooDark();           // lumi�re < darkThreshold
    bool isBright();           
    
    void setDarkThreshold(int t);
    int getDarkThreshold();
};

#endif