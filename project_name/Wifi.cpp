#include "Wifi.h"
#include <iostream>

Wifi::Wifi(int pin) : Actionneur(pin) {}
Wifi::Wifi(int pin, string name) : Actionneur(pin, name) {}

Wifi::~Wifi() {
    deconnecter();
}

void Wifi::initWifi() {
    pinMode(this->broche, OUTPUT);
    this->estActif = true;
    this->connecte = false;
}

void Wifi::deconnecter() {
    this->connecte = false;
    this->estActif = false;
}

void Wifi::connecter(string ssid, string motdepasse) {
    this->ssid = ssid;
    this->motdepasse = motdepasse;
    this->connecte = true;
    this->estActif = true;
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