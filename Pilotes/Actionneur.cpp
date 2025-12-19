#include "Actionneur.h"

Actionneur::Actionneur(int pin) : Equipement(pin) {} 
Actionneur::Actionneur(int pin, string name) : Equipement(pin, name) {}

string Actionneur::getNom() {
    return this->nom;
}

int Actionneur::getBroche();
bool Actionneur::getActif();

void Actionneur::setNom(string name);
void Actionneur::setBroche(int pin);