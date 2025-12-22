#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>
#include <rgb_lcd.h>

#include "Actuator.h"

class Lcd : public Actuator {
    private:
        static int LCDCount;
        rgb_lcd lcd;  
    public:
        // Constructeur
        Lcd(int pin);
        Lcd(int pin, string name);
        // Destructeur
        ~Lcd();

        int getLCDCount();

        void init();
        void activate();
        void deactivate();

        void printMessage(const string& message);
        void setColor(int r, int g, int b);
        void clear();
};


#endif