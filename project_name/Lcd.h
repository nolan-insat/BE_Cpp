#ifndef LCD_H_
#define LCD_H_

#include <iostream>
#include "Actionneur.h"

class LCD : public Actionneur {
protected:
    int colonnes;
    int lignes;

public:
    LCD(int pin);
    LCD(int pin, string name);
    
    ~LCD();
    
    void initLCD();
    void effacerLCD();
    void afficherMessage(string message);
    
    int getColonnes();
    int getLignes();
    
    void setColonnes(int cols);
    void setLignes(int rows);
};

#endif
