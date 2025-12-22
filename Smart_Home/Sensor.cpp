#include "Sensor.h"
#include <iostream>

Sensor::Sensor(int pin) : Device(pin){}

    //Getteurs
string Sensor::getName() {return this->name;}
int Sensor::getPin() {return this->pin;}
bool Sensor::getIsActive() {return this->isActive;}

    //Setteurs
void Sensor::setName(string name) {this->name = name;}
void Sensor::setPin(int pin) {this->pin = pin;}

void Sensor::activate() {this->isActive = true;}

void Sensor::deactivate() {this->isActive = false;}