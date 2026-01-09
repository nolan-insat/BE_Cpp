/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include <Arduino.h>
#include "Application.h"
#include "Device.h"
#include "Actuator.h"
#include "Sensor.h"
#include "Led.h"
#include "Wifi.h"
#include "Lcd.h"
#include "Buzzer.h"


/*

#include <SoftwareSerial.h>

#include <Wire.h>
#include <rgb_lcd.h>
*/
#include <ESP8266WiFi.h>

// Notes standard (Hz)
#define DO  523  
#define RE  587  
#define MI  659  
#define FA  698  
#define SOL  784  
#define LA  880  
#define SI  988  
#define DO_AIGU  1047 


Application::Application()
{
  Serial.begin(9600);
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  led1 = new Led(D5, "Led1");
  led1->init();
 
  buzzer1 = new Buzzer(D8, "Buzzer1");
  buzzer1->init();

  int melody[] = {DO, MI, SOL, DO_AIGU, DO_AIGU, SOL, MI, DO};
  buzzer1->playBeep();
  /*
  buzzer1->playMelody(melody, 8);
  buzzer1->playMelody(melody, 8);
  buzzer1->playMelody(melody, 8);
  */
  lcd1 = new Lcd(D1, "Lcd1");
  lcd1->init();

  lcd1->printMessage("Smart Home Init");
  delay(2000);

  

  lcd1->printMessage("Init Complete");
  delay(2000);
  lcd1->clear();


  // WiFi = new Wifi(D1, "Wifi1");
  WiFi.begin("moi", "Nolan31*");


  lcd1->printMessage("Connexion");
  while ((WiFi.status() != WL_CONNECTED)) {
    delay(500);
    lcd1->printMessage(".");
  }
  lcd1->clear();


  lcd1->printMessage("\nConnecte!");
  delay(2000);
  lcd1->clear();

  lcd1->printMessage("WiFi OK");
  delay(2000);
  lcd1->clear();
  WiFi.disconnect();

  lcd1->printMessage("WiFi deconnecte");
  delay(100);
}


void Application::run(void)
{
  led1->blink(500, 3);

}
