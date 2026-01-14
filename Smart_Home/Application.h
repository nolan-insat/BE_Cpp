/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Led.h"
#include "Wifi.h"
#include "Lcd.h"
#include "Buzzer.h"
#include "Device.h"
#include "Actuator.h"
#include "Sensor.h"
#include "Button.h"
#include "TouchSensor.h"
#include "LightSensor.h"
#include "SoundSensor.h"
#include "Alarm.h"
#include "UltrasonicSensor.h"

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);

    private:
      Led* led1;
      Buzzer* buzzer1;
      Lcd* lcd1;
      Wifi* wifi1;
      Button* button1;
      TouchSensor* touchSensor1;
      LightSensor* lightSensor1;
      SoundSensor* soundSensor1;
      Alarm* alarm1;
      UltrasonicSensor* ultrasonicsensor1;
      ESP8266WebServer* server;

};

#endif