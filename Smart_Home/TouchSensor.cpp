#include "TouchSensor.h"
#include <Arduino.h>

TouchSensor::TouchSensor(int pin) : Sensor(pin, "Touch Sensor"), lastState(false) {}

TouchSensor::TouchSensor(int pin, String name) : Sensor(pin, name), lastState(false) {}

void TouchSensor::init() {
    pinMode(this->pin, INPUT);
    this->isActive = true;
}

void TouchSensor::deactivate() {
    Sensor::deactivate();
}

bool TouchSensor::isTouched() {
    if (!this->isActive) return false;
    
    bool currentState = digitalRead(this->pin) == HIGH;
    
    if (currentState != lastState) {
        lastState = currentState;
    }
    
    return currentState;
}
