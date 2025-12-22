#include "Led.h"

int Led::LedCount = 0;

Led::Led(int pin) : Actuator(pin) {
    LedCount++;
}

Led::Led(int pin, string name) : Actuator(pin, name) {
    LedCount++;
}

Led::~Led() {
    LedCount--;
}

int Led::getLedCount() {
    return LedCount;
}

void Led::init() {
    pinMode(this->pin, OUTPUT);
    activate();
    digitalWrite(this->pin, LOW);
}

void Led::activate() {
    this->isActive = true;
    this->turnOn();
}

void Led::deactivate() {
    this->turnOff();
    this->isActive = false;
    
}

void Led::turnOn() {
    if (this->isActive) {
        digitalWrite(this->pin, HIGH);
    }
}

void Led::turnOff() {
    if (this->isActive) {
        digitalWrite(this->pin, LOW);
    }
}

void Led::toggle() {
    if (this->isActive) {
        digitalWrite(this->pin, !digitalRead(this->pin));
    }
}

void Led::blink(int duration, int repetitions) {
    if (this->isActive) {
        for (int i = 0; i < repetitions; i++) {
            toggle();
            delay(duration);
            toggle();
            delay(duration);
        }
    }
}