#ifndef EQUIPEMENT_H_
#define EQUIPEMENT_H_

#include <iostream>

using namespace std;

class Equipement{

protected :
    string nom;
    int broche;
    bool estActif;

public :
    Equipement(int pin);
    Equipement(int pin, string name);
    ~Equipement();

    virtual void init() = 0;
    virtual void desactiver() = 0;

    //Getteurs
    virtual string getNom() = 0;
    virtual int getBroche() = 0;
    virtual bool getActif() = 0;

    //Setteurs
    virtual void setNom(string name) = 0;
    virtual void setBroche(int pin) = 0;
    virtual void activer() = 0;

};

#endif