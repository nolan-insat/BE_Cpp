#include "Actionneur.h"

Actionneur::Actionneur(int pin) : Equipement(pin) {
    nbActionneurs++;
} 
Actionneur::Actionneur(int pin, string name) : Equipement(pin, name) {
    nbActionneurs++;
}

Actionneur::~Actionneur() {
    nbActionneurs--;
}

string Actionneur::getNom() {
    return this->nom;
}

int Actionneur::getBroche() {
    return this->broche;
}
bool Actionneur::getActif() {
    return this->estActif;
}

void Actionneur::setNom(string name) {
    this->nom = name;
}
void Actionneur::setBroche(int pin) {
    this->broche = pin;
}