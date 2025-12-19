#ifndef CAPTEUR_H_
#define CAPTEUR_H_

#include "Equipement.h"
#include <iostream>

class Capteur : public Equipement {

protected :
    static int nbCapteurs;

public :
    Capteur(int pin);

    //Getteurs
    virtual string getNom();
    virtual int getBroche();
    virtual bool getActif();

    //Setteurs
    virtual void setNom(string name);
    virtual void setBroche(int pin);
    virtual void activer();
};


#endif