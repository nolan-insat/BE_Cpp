#ifndef WIFI_H_
#define WIFI_H_

#include <iostream>
#include <Arduino.h>
#include "Actuator.h"

class Wifi : public Actuator {
protected:
    String ssid;
    String motdepasse;
    bool connecte;

public:
    Wifi(int pin);
    Wifi(int pin, String name);
    
    ~Wifi();
    
    void init();
    void deconnecter();
    void connecter(String ssid, String motdepasse);
    
    String getSSID();
    String getMotDePasse();
    bool getConnecte();
    
    void setSSID(String ssid);
    void setMotDePasse(String motdepasse);

    void activate();
    void deactivate();
};

#endif
