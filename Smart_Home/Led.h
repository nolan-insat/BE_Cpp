#ifndef LED_H_
#define LED_H_

#include <Arduino.h>
#include "Actuator.h"

class Led : public Actuator {
    private:
        static int LedCount;
    public:
        // Constructeur
        Led(int pin);
        Led(int pin, String name);
        // Destructeur
        ~Led();

        int getLedCount();

        void init();
        void activate();
        void deactivate();

        void turnOn();
        void turnOff();
        void toggle();
        void blink(int duration, int repetitions);
};

#endif