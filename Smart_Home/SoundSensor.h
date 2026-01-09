#ifndef SOUND_SENSOR_H_
#define SOUND_SENSOR_H_

#include "Sensor.h"

class SoundSensor : public Sensor {
private:
    int threshold;  // Seuil pour bruit fort
    
public:
    SoundSensor(int pin);
    SoundSensor(int pin, String name);
    
    void init();
    
    int getSoundLevel();        // niveau sonore 0-1023
    bool isLoud();              // bruit > threshold
    
    void setThreshold(int t);
    int getThreshold();
};

#endif