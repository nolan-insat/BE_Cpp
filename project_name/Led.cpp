#include "Led.h"

Led::Led(int pin) : Actionneur(pin) {
    nbLeds++;
}

Led::Led(int pin, string name) : Actionneur(pin, name) {
    nbLeds++;
}

Led::~Led() {
    nbLeds--;
}

int Led::getNbLeds() {
    return nbLeds;
}

void Led::init() {
    pinMode(this->broche, OUTPUT);
    digitalWrite(this->broche, LOW);
}

void Led::allumer() {
    digitalWrite(this->broche, HIGH);
}

void Led::eteindre() {
    digitalWrite(this->broche, LOW);
}