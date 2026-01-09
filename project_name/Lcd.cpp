#include "Lcd.h"
#include <iostream>

LCD::LCD(int pin) : Actionneur(pin) {}
LCD::LCD(int pin, string name) : Actionneur(pin, name) {}

LCD::~LCD() {}

void LCD::initLCD() {
    pinMode(this->broche, OUTPUT);
    this->estActif = true;
}

void LCD::effacerLCD() {
    // Code pour effacer l'écran LCD
    this->estActif = false;
}

void LCD::afficherMessage(string message) {
    if (this->estActif) {
        // Code pour afficher le message sur LCD
    }
}

int LCD::getColonnes() {
    return this->colonnes;
}

int LCD::getLignes() {
    return this->lignes;
}

void LCD::setColonnes(int cols) {
    this->colonnes = cols;
}

void LCD::setLignes(int rows) {
    this->lignes = rows;
}
