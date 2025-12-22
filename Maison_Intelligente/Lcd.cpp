#include "Lcd.h"

int Lcd::nbLcds = 0;

Lcd::Lcd(int pin) : Actionneur(pin) {
    nbLcds++;
}

Lcd::Lcd(int pin, string name) : Actionneur(pin, name) {
    nbLcds++;
}

Lcd::~Lcd() {
    nbLcds--;
}

int Lcd::getNbLcds() {
    return nbLcds;
}

void Lcd::init() {
    // Initialisation de l'écran LCD
    lcd.begin(16, 2); // Exemple pour un écran 16x2
    
}