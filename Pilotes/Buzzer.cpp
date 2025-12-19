#include "Buzzer.h"
#include <iostream>

Buzzer::Buzzer(int pin) : Actionneur(pin){}
Buzzer::Buzzer(int pin, string name) : Actionneur(pin, name){}

Buzzer::~Buzzer(){desactiverBuzzer();}

void Buzzer::initBuzzer();
    void desactiverBuzzer();
    void activerBuzzer();

    void definirSon(int freq, int temps);
    void jouerbip();
    void jouerMelodie(int melodie[], int taille);

    int getFrequence();
    int getDuree();

    void setFrequence(int freq);
    void setDuree(int duree);