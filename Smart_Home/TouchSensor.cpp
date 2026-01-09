#include "TouchSensor.h"
#include <Arduino.h>

TouchSensor::TouchSensor(int pin) : Sensor(pin, "Touch Sensor"), lastState(false), lastChangeTime(0) {}

TouchSensor::TouchSensor(int pin, String name) : Sensor(pin, name), lastState(false), lastChangeTime(0) {}

void TouchSensor::init() {
    pinMode(this->pin, INPUT);
    this->isActive = true;
}

void TouchSensor::deactivate() {
    Sensor::deactivate();
}

bool TouchSensor::isTouched() {
    if (!this->isActive) return false;
    
    unsigned long now = millis();
    if (now - lastChangeTime < 50) {  
        return lastState;
    }
    
    bool currentState = digitalRead(this->pin) == HIGH;
    
    if (currentState != lastState) {
        lastChangeTime = now;
        lastState = currentState;
    }
    
    return currentState;
}

bool TouchSensor::isPressed() {
    static bool previousState = false;
    bool currentState = isTouched();
    
    if (currentState && !previousState) {
        previousState = currentState;
        return true;
    }
    
    previousState = currentState;
    return false;
}

bool TouchSensor::isReleased() {
    static bool previousState = false;
    bool currentState = isTouched();
    
    if (!currentState && previousState) {
        previousState = currentState;
        return true;
    }
    
    previousState = currentState;
    return false;
}