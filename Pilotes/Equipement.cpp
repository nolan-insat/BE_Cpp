#include "Equipement.h"
#include <iostream>

using namespace std;

Equipement::Equipement(int pin) : broche(pin){estActif = false;}
Equipement::Equipement(int pin, string name) : broche(pin){nom = name; estActif = false;}
Equipement::~Equipement() {}