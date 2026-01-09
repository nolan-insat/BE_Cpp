#include "Wifi.h"
#include <iostream>

Wifi::Wifi(int pin) : Actuator(pin) {}
Wifi::Wifi(int pin, string name) : Actuator(pin, name) {}

Wifi::~Wifi() {
    deconnecter();
}

void Wifi::init() {
    pinMode(this->pin, OUTPUT);
    this->isActive = true;
    this->connecte = false;
}

void Wifi::activate() {
    this->isActive = true;
}

void Wifi::deactivate() {
    this->isActive = false;
    this->connecte = false;
}

void Wifi::deconnecter() {
    this->connecte = false;
    this->isActive = false;
}

void Wifi::connecter(string ssid, string motdepasse) {
    this->ssid = ssid;
    this->motdepasse = motdepasse;
    this->connecte = true;
    this->isActive = true;
}

string Wifi::getSSID() {
    return this->ssid;
}

string Wifi::getMotDePasse() {
    return this->motdepasse;
}

bool Wifi::getConnecte() {
    return this->connecte;
}

void Wifi::setSSID(string ssid) {
    this->ssid = ssid;
}

void Wifi::setMotDePasse(string motdepasse) {
    this->motdepasse = motdepasse;
}