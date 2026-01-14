#ifndef LIGHT_CONTROLLER_H_
#define LIGHT_CONTROLLER_H_

/* Contr�leur d'�clairage automatique bas� sur pr�sence et luminosit� */

#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "LightSensor.h"
#include "Led.h"
#include "Button.h"
#include <exception>

class LightController {

private:
    UltrasonicSensor* presenceSensor;
    LightSensor* lightSensor;
    Led* led;
    
    float detectionDistance;    // Distance max de d�tection 
    int lightThreshold;         // Seuil de luminosit� 
    bool autoMode;              // Mode automatique activ�
    bool lightState;            // �tat actuel de la lumi�re
    
    // Statistiques
    unsigned int detectionCount;
    unsigned int lightOnCount;
    
    // M�thodes 
    bool checkPresence();
    bool checkLightLevel();
    void updateLight(bool shouldBeOn);

public:
    // Constructeur
    LightController(UltrasonicSensor* presenceSensor, 
                    LightSensor* lightSensor, 
                    Led* led);
    
    // Destructeur
    ~LightController();
    
    void init();
    
    // Cycle de contr�le de la pr�sence et de la luminosit�, puis activation ou non de la led en consequence.
    // Retourne true si la LED est allum�e, false sinon
    bool update();
    
    //V�rifie si la lumi�re est allum�e
    bool isLightOn() const;

    // Getter pour le mode
    bool isAutoMode() const {return autoMode;}  
    
    // D�finit la distance de d�tection
    void setDetectionDistance(float distance);
    
    // D�finit le seuil de luminosit� pour allumer
    void setLightThreshold(int threshold);
    
    // Active/d�sactive le contr�le automatique
    void setAutoMode(bool enabled);
    
    void toggleMode();
    
    // Allumage manuel
    void turnOn();
    
    // Extinction manuelle
    void turnOff();
    
    // Affiche les statistiques
    void printStats() const;
    
};

#endif

#ifndef LIGHT_CONTROLLER_EXCEPTION_H_
#define LIGHT_CONTROLLER_EXCEPTION_H_

// Exception pour le contr�leur
class LightControllerException {
private:
    String message;
public:
    LightControllerException(String msg) : message(msg) {}
    String what() {return message;}
};

#endif
