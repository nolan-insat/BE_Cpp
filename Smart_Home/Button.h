#ifndef BUTTON_H_
#define BUTTON_H_

#include "Sensor.h"

class Button : public Sensor {
private:
    bool lastState;         
    unsigned long lastPressTime; // �viter rebonds
    
public:
    Button(int pin);
    Button(int pin, String name);
    
    void init();
    
    bool isPressed();           
    bool wasPressed();          
    bool wasReleased();         // bouton vient d'�tre rel�ch�

};

#endif