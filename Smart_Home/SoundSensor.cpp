#include "SoundSensor.h"
#include <Arduino.h>

SoundSensor::SoundSensor(int pin) : Sensor(pin, "Sound Sensor"), threshold(500) {}

SoundSensor::SoundSensor(int pin, string name) : Sensor(pin, name), threshold(500) {}

void SoundSensor::initialize() {
    pinMode(this->pin, INPUT);
    this->isActive = true;
}

int SoundSensor::getSoundLevel() {
    if (!this->isActive) return -1;
    
    return analogRead(this->pin);
}

bool SoundSensor::isLoud() {
    int level = getSoundLevel();
    return level > threshold;
}

void SoundSensor::setThreshold(int t) {threshold = t;}
int SoundSensor::getThreshold() {return threshold;}