#include "Alarm.h"
#include "Buzzer.h"
#include <Arduino.h>
#include "UltrasonicSensor.h"

#define DO  523  
#define SOL  784

Alarm::Alarm() : armed(false) {}

Alarm::~Alarm() {}

void Alarm::init(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor, Lcd* lcd) {
    this->buzzer = buzzer;
    this->ultrasonicSensor = ultrasonicSensor;
    this->lcd = lcd;
    disarm();
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
    if (armed && ultrasonicSensor->isObjectDetected(thresholdDistance)) {
            buzzer->playBeep();
    }
}