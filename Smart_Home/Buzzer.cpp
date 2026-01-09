#include "Buzzer.h"
#include <Arduino.h>
#include <iostream>

int Buzzer::BuzzerCount = 0;

Buzzer::Buzzer(int pin) : Actuator(pin){ BuzzerCount++; }
Buzzer::Buzzer(int pin, String name) : Actuator(pin, name){ BuzzerCount++; }

Buzzer::~Buzzer(){ BuzzerCount--; deactivate(); }

void Buzzer::init(){
    pinMode(this->pin, OUTPUT);
    this->isActive = true;
}

void Buzzer::deactivate(){
    this->isActive = false;
}

void Buzzer::activate(){
    this->isActive = true;
}

void Buzzer::setTone(int freq, int time){
    tone(this->pin, freq, time);
}

void Buzzer::playBeep(){
    tone(this->pin, 1000, 500);
}

void Buzzer::playMelody(int melody[], int size){
    for (int i = 0; i < size; i++){
        setTone(melody[i], 200);
        delay(250);
    }
}

int Buzzer::getFrequency() {
    return this->frequency;
}
int Buzzer::getDuration() {
    return this->duration;
}

void Buzzer::setFrequency(int freq) {
    this->frequency = freq;
}
void Buzzer::setDuration(int duration) {
    this->duration = duration;
}

    