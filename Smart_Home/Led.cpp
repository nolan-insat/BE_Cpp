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
    digitalWrite(this->pin, HIGH);
}

void Led::deactivate() {
    digitalWrite(this->pin, HIGH);
    this->isActive = false;
    
}

void Led::turnOn() {
    digitalWrite(this->pin, HIGH);
}

void Led::turnOff() {
    digitalWrite(this->pin, LOW);
}

void Led::toggle() {
    digitalWrite(this->pin, !digitalRead(this->pin));

}

void Led::blink(int duration, int repetitions) {
    for (int i = 0; i < repetitions; i++) {
        toggle();
        delay(duration);
        toggle();
        delay(duration);
    }

}