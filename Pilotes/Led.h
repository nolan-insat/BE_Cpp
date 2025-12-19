#ifndef LED_H_
#define LED_H_

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

        void
}

#endif