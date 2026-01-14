#include "Alarm.h"
#include "Buzzer.h"
#include <Arduino.h>
#include "UltrasonicSensor.h"

#define DO  523  
#define SOL  784

Alarm::Alarm() : armed(false), triggerTime(10) {}

Alarm::~Alarm() {}

void Alarm::arm(Buzzer* buzzer) {
    armed = true;
    int melody[] = {DO, SOL};
    buzzer->playMelody(melody, 2);
}

void Alarm::disarm(Buzzer* buzzer) {
    armed = false;
    int melody[] = {SOL, DO};
    buzzer->playMelody(melody, 2);
}

bool Alarm::isArmed() const {
    return armed;
}

void Alarm::trigger(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor) {
    Serial.println(isArmed() ? "Alarm is armed." : "Alarm is disarmed.");
    Serial.println(String(ultrasonicSensor->readDistance()));
    if (armed && ultrasonicSensor->isObjectDetected(10)) { // Example threshold
        for (int i = 0; i < 3; ++i) {
            buzzer->playBeep();
        }
    }
}

unsigned long Alarm::getTriggerTime() const {
    return triggerTime;
}

void Alarm::setTriggerTime(unsigned long time) {
    triggerTime = time;
}