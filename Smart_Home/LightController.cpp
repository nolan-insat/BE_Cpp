#include "LightController.h"
#include <Arduino.h>
#include "Sensor.h"

LightController::LightController(UltrasonicSensor* presenceSensor, 
                               LightSensor* lightSensor, 
                               Led* led)
    : presenceSensor(presenceSensor), 
      lightSensor(lightSensor), 
      led(led),
      detectionDistance(10.0),   // 10 cm par dfaut
      lightThreshold(300),       // Seuil par d�faut
      autoMode(true),           // Mode automatique activ par dfaut
      lightState(false),
      detectionCount(0),
      lightOnCount(0) {
    
    Serial.println("LightController : constructeur");
}

LightController::~LightController() {
    Serial.println("LightController : destructeur");
    // �teindre la LED � la destruction
    if (led && led->getIsActive()) {
        led->turnOff();
    }
}

void LightController::init() {
    
    // V�rifier que tous les p�riph�riques sont init
    if (!presenceSensor || !presenceSensor->getIsActive()) {
        throw LightControllerException("Capteur de presence non initialise");
    }
    
    if (!lightSensor || !lightSensor->getIsActive()) {
        throw LightControllerException("Capteur de lumiere non initialise");
    }
    
    if (!led || !led->getIsActive()) {
        throw LightControllerException("LED non initialisee");
    }
    
    // Init l'�tat de la led, �teinte par d�faut
    lightState = false;
    led->turnOff();
}

bool LightController::update() {
    if (!autoMode) {
        return lightState;  // Mode manuel, rien � faire
    }
    
    try {
        // On v�rifie la pr�sence de quelqu'un
        bool presenceDetected = checkPresence();
        
        // On v�rifie la luminosit�
        bool tooDark = checkLightLevel();
        
        // D�cision �tat de la led
        bool shouldBeOn = presenceDetected && tooDark;
        updateLight(shouldBeOn);
        
        return lightState;
        
    } catch (const std::exception& e) {
        Serial.print("LightController: Erreur lors de l'update");
        Serial.println(e.what());
        
        // En cas d'erreur, on �teint la led par s�curit�
        if (led && led->getIsActive()) {
            led->turnOff();
            lightState = false;
        }
        
        return false;
    }
}

bool LightController::checkPresence() {
    if (!presenceSensor || !presenceSensor->getIsActive()) {
        throw LightControllerException("Capteur de presence inactif");
    }
    
    return presenceSensor->isObjectDetected(detectionDistance);
}

bool LightController::checkLightLevel() {
    if (!lightSensor || !lightSensor->getIsActive()) {
        throw LightControllerException("Capteur de lumiere inactif");
    }
    
    int lightLevel = lightSensor->getLightLevel();
    
    // Retourne true si trop sombre
    bool tooDark = lightLevel < lightThreshold;
    
    return tooDark;
}

void LightController::updateLight(bool shouldBeOn) {
    if (!led || !led->getIsActive()) {
        throw LightControllerException("LED inactive");
    }
    
    // On change l'�tat seulement si n�cessaire
    if (shouldBeOn != lightState) {
        if (shouldBeOn) {
            led->turnOn();
            lightOnCount++;
        } else {
            led->turnOff();
        }
        lightState = shouldBeOn;
    }
}

bool LightController::isLightOn() const {
    return lightState;
}

void LightController::setDetectionDistance(float distance) {
    if (distance < 5.0 || distance > 400.0) {
        throw LightControllerException("Distance invalide : 5-400 cm");
    }
    detectionDistance = distance;
}

float LightController::getDetectionDistance() {
    return detectionDistance;
}

int LightController::getLightThreshold() {
    return lightThreshold;
}

void LightController::setLightThreshold(int threshold) {
    if (threshold < 0 || threshold > 1023) {  
        throw LightControllerException("Seuil invalide (0-1023)");
    }
    lightThreshold = threshold;
}

void LightController::setAutoMode(bool enabled) {
    autoMode = enabled;
}

void LightController::toggleMode() {
    setAutoMode(!autoMode);
}

void LightController::turnOn() {
    setAutoMode(false);  // Passer en mode manuel
    updateLight(true);
}

void LightController::turnOff() {
    setAutoMode(false);  // Passer en mode manuel
    updateLight(false);
}

void LightController::toggleLight() {
    if (lightState) {
        turnOff();
    } else {
        turnOn();
    }
}

void LightController::printStats() const {
    Serial.println("--- STATISTIQUES LightController ---");
    Serial.print("Detections de presence : ");
    Serial.println(detectionCount);
    Serial.print("Allumages de LED : ");
    Serial.println(lightOnCount);
    Serial.print("Etat actuel : ");
    Serial.println(lightState ? "ALLUMEE" : "ETEINTE");
    Serial.print("Mode : ");
    Serial.println(isAutoMode ? "AUTOMATIQUE" : "MANUEL");
    Serial.print("Distance configuree : ");
    Serial.print(detectionDistance);
    Serial.println(" cm");
    Serial.print("Seuil lumiere : ");
    Serial.println(lightThreshold);
}
