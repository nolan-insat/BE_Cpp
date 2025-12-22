#include "Actuator.h"

int Actuator::ActuatorCount = 0;

Actuator::Actuator(int pin) : Device(pin) {
    ActuatorCount++;
} 
Actuator::Actuator(int pin, string name) : Device(pin, name) {
    ActuatorCount++;
}

Actuator::~Actuator() {
    ActuatorCount--;
}

string Actuator::getName() {
    return this->name;
}

int Actuator::getPin() {
    return this->pin;
}
bool Actuator::getIsActive() {
    return this->isActive;
}

void Actuator::setName(string name) {
    this->name = name;
}

void Actuator::setPin(int pin) {
    this->pin = pin;
}