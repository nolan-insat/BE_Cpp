#ifndef BUTTON_H_
#define BUTTON_H_

#include "Sensor.h"

class Button : public Sensor {
private:
    bool lastState;         
    unsigned long lastPressTime; // éviter rebonds
    
public:
    Button(int pin);
    Button(int pin, string name);
    
    void initialize();
    
    bool isPressed();           
    bool wasPressed();          
    bool wasReleased();         // bouton vient d'être relâché

};

#endif