#include "Buzzer.h"
#include <iostream>

Buzzer::Buzzer(int pin) : Actuator(pin){ BuzzerCount++; }
Buzzer::Buzzer(int pin, string name) : Actuator(pin, name){ BuzzerCount++; }

Buzzer::~Buzzer(){ BuzzerCount--; deactivate(); }
/*
void Buzzer::init();
    void deactivate();
    void activate();

    void setTone(int freq, int time);
    void playBeep();
    void playMelody(int melody[], int size);

    int getFrequency();
    int getDuration();

    void setFrequency(int freq);
    void setDuration(int duration);
    */
    