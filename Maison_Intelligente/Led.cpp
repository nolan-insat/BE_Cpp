#include "Led.h"

int Led::nbLeds = 0;

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

void Led::activer() {
    this->estActif = true;
    this->allumer();
}

void Led::desactiver() {
    this->eteindre();
    this->estActif = false;
    
}

void Led::allumer() {
    if (this->estActif) {
        digitalWrite(this->broche, HIGH);
    }
}

void Led::eteindre() {
    if (this->estActif) {
        digitalWrite(this->broche, LOW);
    }
}

void Led::toggle() {
    if (this->estActif) {
        digitalWrite(this->broche, !digitalRead(this->broche));
    }
}

void Led::clignote(int duree, int repetitions) {
    if (this->estActif) {
        for (int i = 0; i < repetitions; i++) {
            toggle();
            delay(duree);
            toggle();
            delay(duree);
        }
    }
}