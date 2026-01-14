#include "Alarm.h"
#include "Buzzer.h"
#include <Arduino.h>
#include "UltrasonicSensor.h"

#define DO  523  
#define SOL  784

Alarm::Alarm() : armed(false), triggerTime(10) {}

Alarm::~Alarm() {}

void Alarm::init(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor, Lcd* lcd) {
    this->buzzer = buzzer;
    this->ultrasonicSensor = ultrasonicSensor;
    this->lcd = lcd;
}

void Alarm::arm() {
    armed = true;
    int melody[] = {DO, SOL};
    buzzer->playMelody(melody, 2);
    lcd->clearLine(1);
    lcd->setCursor(0, 1);
    lcd->printMessage("Alarm Armed");
}

void Alarm::disarm() {
    armed = false;
    int melody[] = {SOL, DO};
    buzzer->playMelody(melody, 2);
    lcd->clearLine(1);
    lcd->setCursor(0, 1);
    lcd->printMessage("Alarm Disarmed");
}

bool Alarm::isArmed() const {
    return armed;
}

void Alarm::trigger() {
    // Serial.println(isArmed() ? "Alarm is armed." : "Alarm is disarmed.");
    // Serial.println(String(ultrasonicSensor->readDistance()));
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