#include "Lcd.h"
#include <Wire.h>

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
    // Initialisation de l'ecran LCD
    Wire.begin(D2, D1);
    delay(100);
    this->lcd.begin(16, 2); // ecran 16x2
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

void Lcd::setColor(int r, int g, int b) {
    if (this->isActive) {
        this->lcd.setRGB(r, g, b);
    }
}