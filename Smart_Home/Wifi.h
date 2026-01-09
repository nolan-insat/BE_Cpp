#ifndef WIFI_H_
#define WIFI_H_

#include <iostream>
#include "Actuator.h"

class Wifi : public Actuator {
protected:
    string ssid;
    string motdepasse;
    bool connecte;

public:
    Wifi(int pin);
    Wifi(int pin, string name);
    
    ~Wifi();
    
    void initWifi();
    void deconnecter();
    void connecter(string ssid, string motdepasse);
    
    string getSSID();
    string getMotDePasse();
    bool getConnecte();
    
    void setSSID(string ssid);
    void setMotDePasse(string motdepasse);
};

#endif
