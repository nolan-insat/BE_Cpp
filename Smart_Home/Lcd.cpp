#include "Lcd.h"

int Lcd::LCDCount = 0;

Lcd::Lcd(int pin) : Actuator(pin) {
    LCDCount++;
}

Lcd::Lcd(int pin, string name) : Actuator(pin, name) {
    LCDCount++;
}

Lcd::~Lcd() {
    LCDCount--;
}

int Lcd::getLCDCount() {
    return LCDCount;
}

void Lcd::init() {
    // Initialisation de l'écran LCD
    this->lcd.begin(16, 2); // Exemple pour un écran 16x2
    this->activate();
    this->lcd.clear();
}

void Lcd::activate() {
    this->isActive = true;
}

void Lcd::deactivate() {
    this->isActive = false;
}

void Lcd::clear() {
    if (this->isActive) {
        this->clear();
    }
}

void Lcd::printMessage(const string& message) {
    if (this->isActive) {
        this->lcd.print(message.c_str());
    }
}