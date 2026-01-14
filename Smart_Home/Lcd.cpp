#include "Lcd.h"
#include <Wire.h>

int Lcd::LCDCount = 0;

Lcd::Lcd(int pin) : Actuator(pin) {
    LCDCount++;
}

Lcd::Lcd(int pin, String name) : Actuator(pin, name) {
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
    lcd.begin(16, 2); // ecran 16x2
    lcd.setCursor(0, 0);
    this->activate();
    lcd.clear();
}

void Lcd::setCursor(int col, int row) {
    if (this->isActive) {
        lcd.setCursor(col, row);
    }
}

void Lcd::clearLine(int row) {
    if (this->isActive) {
        lcd.setCursor(0, row);
        for (int i = 0; i < 16; i++) {
            lcd.print(" ");
        }
        lcd.setCursor(0, row);
    }
}

void Lcd::activate() {
    this->isActive = true;
}

void Lcd::deactivate() {
    this->isActive = false;
}

void Lcd::clear() {
    if (this->isActive) {
        lcd.clear();
    }
}

void Lcd::printMessage(const String& message) {
    if (this->isActive) {
        lcd.print(message.c_str());
    }
}

void Lcd::setColor(int r, int g, int b) {
    if (this->isActive) {
        lcd.setRGB(r, g, b);
    }
}