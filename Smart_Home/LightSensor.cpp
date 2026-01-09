#include "LightSensor.h"
#include <Arduino.h>

LightSensor::LightSensor(int pin) : Sensor(pin, "Light Sensor"), darkThreshold(300) {}

LightSensor::LightSensor(int pin, String name) : Sensor(pin, name), darkThreshold(300) {}

void LightSensor::init() {
    pinMode(this->pin, INPUT);
    this->isActive = true;
}

int LightSensor::getLightLevel() {
    if (!this->isActive) return -1;
    
    return analogRead(this->pin);
}

bool LightSensor::isTooDark() {
    int level = getLightLevel();
    return level < darkThreshold;
}

bool LightSensor::isBright() {
    int level = getLightLevel();
    return level > darkThreshold + 100;
}

void LightSensor::setDarkThreshold(int t) {darkThreshold = t;}
int LightSensor::getDarkThreshold() {return darkThreshold;}