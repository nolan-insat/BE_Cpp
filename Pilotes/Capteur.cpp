#include "Capteur.h"
#include <iostream>

Capteur::Capteur(int pin) : Equipement(pin){}

    //Getteurs
string Capteur::getNom(){return Equipement::nom;}
int Capteur::getBroche(){return Equipement::broche;}
bool Capteur::getActif(){return Equipement::estActif;}

    //Setteurs
void Capteur::setNom(string name){Equipement::nom = name;}
void Capteur::setBroche(int pin){Equipement::broche = pin;}
void Capteur::activer(){Equipement::estActif = true;}