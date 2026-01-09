#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) : Sensor(pin, "Button"), lastState(false), lastPressTime(0) {}

Button::Button(int pin, string name) : Sensor(pin, name), lastState(false), lastPressTime(0) {}

void Button::initialize() {
    pinMode(this->pin, INPUT_PULLUP);  
    this->isActive = true;
}

bool Button::isPressed() {
    if (!this->isActive) return false;
    
    // Avec pull-up : LOW = pressé
    return digitalRead(this->pin) == LOW;
}

bool Button::wasPressed() {
    if (!this->isActive) return false;
    
    bool currentPressed = isPressed();
    
    // Anti-rebond = attendre 50ms entre 2 pressions
    if (currentPressed && !lastState) {
        if (millis() - lastPressTime > 50) {
            lastState = currentPressed;
            lastPressTime = millis();
            return true;
        }
    }
    
    lastState = currentPressed;
    return false;
}

bool Button::wasReleased() {
    if (!this->isActive) return false;
    
    bool currentPressed = isPressed();
    
    if (!currentPressed && lastState) {
        if (millis() - lastPressTime > 50) {
            lastState = currentPressed;
            lastPressTime = millis();
            return true;
        }
    }
    
    lastState = currentPressed;
    return false;
}