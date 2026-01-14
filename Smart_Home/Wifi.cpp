#include "Wifi.h"
#include <iostream>
#include <ESP8266WiFi.h>

Wifi::Wifi(int pin) : Actuator(pin) {}
Wifi::Wifi(int pin, String name) : Actuator(pin, name) {}

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

void Wifi::connecter(String ssid, String motdepasse) {
    this->ssid = ssid;
    this->motdepasse = motdepasse;
    WiFi.begin(ssid.c_str(), motdepasse.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    this->connecte = true;
    this->isActive = true;
    Serial.println(getIP());
}

String Wifi::getSSID() {
    return this->ssid;
}

String Wifi::getMotDePasse() {
    return this->motdepasse;
}

bool Wifi::getConnecte() {
    return this->connecte;
}

void Wifi::setSSID(String ssid) {
    this->ssid = ssid;
}

void Wifi::setMotDePasse(String motdepasse) {
    this->motdepasse = motdepasse;
}

String Wifi::getIP() {
    if (connecte) {
        return WiFi.localIP().toString();
    }
    return "0.0.0.0";
}