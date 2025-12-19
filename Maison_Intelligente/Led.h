#ifndef LED_H_
#define LED_H_

#include <Arduino.h>
#include <string>
#include "Actionneur.h"

class Led : public Actionneur {
    private:
        static int nbLeds;
    public:
        // Constructeur
        Led(int pin);
        Led(int pin, string name);
        // Destructeur
        ~Led();

        int getNbLeds();

        void init();
        void activer();
        void desactiver();

        void allumer();
        void eteindre();
        void toggle();
        void clignote(int duree, int repetitions);
};

#endif