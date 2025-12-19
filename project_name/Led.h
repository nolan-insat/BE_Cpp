#ifndef LED_H_
#define LED_H_

// #include <Arduino.h>
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

        virtual void init();

        void allumer();
        void eteindre();
        void clignote();
};

#endif