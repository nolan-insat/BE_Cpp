#ifndef BUZZER_H_
#define BUZZER_H_

#include <iostream>
#include <Arduino.h>
#include "Actuator.h"


class Buzzer : public Actuator {

protected : 
    static int BuzzerCount;
    int frequency;
    int duration;

public :
    Buzzer(int pin);
    Buzzer(int pin, String name);

    ~Buzzer();

    void init();
    void deactivate();
    void activate();

    void setTone(int freq, int time);
    void playBeep();
    void playMelody(int melody[], int size);

    int getFrequency();
    int getDuration();

    void setFrequency(int freq);
    void setDuration(int duration);
};

#endif