#ifndef LIGHT_CONTROLLER_H_
#define LIGHT_CONTROLLER_H_

/* Contrôleur d'éclairage automatique basé sur présence et luminosité */

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
    
    float detectionDistance;    // Distance max de détection 
    int lightThreshold;         // Seuil de luminosité 
    bool autoMode;              // Mode automatique activé
    bool lightState;            // État actuel de la lumière
    
    // Statistiques
    unsigned int detectionCount;
    unsigned int lightOnCount;
    
    // Méthodes 
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
    
    // Cycle de contrôle de la présence et de la luminosité, puis activation ou non de la led en consequence.
    // Retourne true si la LED est allumée, false sinon
    bool update();
    
    //Vérifie si la lumière est allumée
    bool isLightOn() const;

    // Getter pour le mode
    bool isAutoMode() const {return autoMode;}  
    
    // Définit la distance de détection
    void setDetectionDistance(float distance);
    
    // Définit le seuil de luminosité pour allumer
    void setLightThreshold(int threshold);
    
    // Active/désactive le contrôle automatique
    void setAutoMode(bool enabled);
    
    void toggleMode();
    
    // Allumage manuel
    void turnOn();
    
    // Extinction manuelle
    void turnOff();
    
    // Affiche les statistiques
    void printStats() const;
    
};

// Exception pour le contrôleur
class LightControllerException {
private:
    String message;
public:
    LightControllerException(String msg) : message(msg) {}
    String what() {return message;}
};

#endif
