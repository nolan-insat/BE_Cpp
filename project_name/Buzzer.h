#ifndef BUZZER_H_
#define BUZZER_H_

#include <iostream>
#include "Actionneur.h"


class Buzzer : public Actionneur{

protected : 
    int frequence;
    int duree;

public :
    Buzzer(int pin);
    Buzzer(int pin, string name);

    ~Buzzer();

    void initBuzzer();
    void desactiverBuzzer();
    void activerBuzzer();

    void definirSon(int freq, int temps);
    void jouerbip();
    void jouerMelodie(int melodie[], int taille);

    int getFrequence();
    int getDuree();

    void setFrequence(int freq);
    void setDuree(int duree);
};

#endif