#include "Buzzer.h"
#include <iostream>

Buzzer::Buzzer(int pin) : Actionneur(pin){}
Buzzer::Buzzer(int pin, string name) : Actionneur(pin, name){}

Buzzer::~Buzzer(){desactiverBuzzer();}

void Buzzer::initBuzzer(){
    pinMode(this->broche, OUTPUT);
    digitalWrite(this->broche, LOW); 
    this->estActif = false;
}

void Buzzer::desactiverBuzzer(){
    noTone(this->broche);
    digitalWrite(this->broche, LOW);
    this->estActif = false;
    this->frequence = 0;
}

void Buzzer::activerBuzzer(){
    if (this->frequence > 0) {
        tone(this->broche, this->frequence);
        this->estActif = true;
    }
}

void Buzzer::definirSon(int freq, int temps){
    this->frequence = freq;
    this->duree = temps;
}

void Buzzer::jouerbip(){
    activerBuzzer();
    delay(100);
    desactiverBuzzer();
    delay(100);
}

void Buzzer::jouerMelodie(int melodie[], int taille){
    for (int i = 0; i < taille; i += 2) {
        this->frequence = melodie[i];
        this->duree = melodie[i + 1];
        activerBuzzer();
        delay(this->duree);
        desactiverBuzzer();
        delay(50);
    }
}

int Buzzer::getFrequence(){
    return this->frequence;
}

int Buzzer::getDuree(){
    return this->duree;
}

void Buzzer::setFrequence(int freq){
    this->frequence = freq;
}

void Buzzer::setDuree(int duree){
    this->duree = duree;
}