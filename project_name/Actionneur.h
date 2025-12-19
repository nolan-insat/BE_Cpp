#ifndef ACTIONNEUR_H_
#define ACTIONNEUR_H_

#include "Equipement.h"

class Actionneur : public Equipement {
    protected:
    static int nbActionneurs;
    public:

    // Constructeur
    Actionneur(int pin) ;
    Actionneur(int pin, string nom);
    // Destructeur
    ~Actionneur() ;

    string getNom();
    int getBroche();
    bool getActif();

    void setNom(string name);
    void setBroche(int pin);

    int getNbActionneurs();

};

#endif