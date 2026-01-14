#include "Alarm.h"
#include "Buzzer.h"
#include <Arduino.h>
#include "UltrasonicSensor.h"

Alarm::Alarm() : armed(false), triggerTime(10) {}

Alarm::~Alarm() {}

void Alarm::arm() {
    armed = true;
}

void Alarm::disarm() {
    armed = false;
}

bool Alarm::isArmed() const {
    return armed;
}

void Alarm::trigger(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor) {
    if (armed && ultrasonicSensor->isObjectDetected(10)) { // Example threshold
        for (int i = 0; i < 3; ++i) {
            buzzer->playBeep();
            delay(triggerTime);
        }
    }
}

unsigned long Alarm::getTriggerTime() const {
    return triggerTime;
}

void Alarm::setTriggerTime(unsigned long time) {
    triggerTime = time;
}