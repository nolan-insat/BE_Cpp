#include "Actuator.h"

int Actuator::ActuatorCount = 0;

Actuator::Actuator(int pin) : Device(pin) {
    ActuatorCount++;
} 
Actuator::Actuator(int pin, String name) : Device(pin, name) {
    ActuatorCount++;
}

Actuator::~Actuator() {
    ActuatorCount--;
}

int Actuator::getActuatorCount() {
    return ActuatorCount;
}

String Actuator::getName() {
    return this->name;
}

int Actuator::getPin() {
    return this->pin;
}
bool Actuator::getIsActive() {
    return this->isActive;
}

void Actuator::setName(String name) {
    this->name = name;
}

void Actuator::setPin(int pin) {
    this->pin = pin;
}