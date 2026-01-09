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
  lcd1->clear();
  

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

  /*Serial.println("=== INITIALISATION SYSTEME ===");
  
  // 1. LED (Actionneur)
  led1 = new Led(LED_PIN, "LED System");
  led1->init();
  led1->turnOff();
  
  // 2. Buzzer (Actionneur)
  buzzer1 = new Buzzer(BUZZER_PIN, "Buzzer System");
  buzzer1->init();
  
  // 3. LCD (Actionneur)
  lcd1 = new Lcd(LCD_PIN, "LCD Display");
  lcd1->init();
  lcd1->setColor(0, 100, 0); // Vert
  lcd1->printMessage("Systeme OK");
  delay(1000);
  
  // 4. Capteurs
  // Bouton poussoir
  button1 = new Button(BUTTON_PIN, "Bouton");
  button1->init();
  
  // Capteur tactile
  touchSensor1 = new TouchSensor(TOUCH_PIN, "Touch Sensor");
  touchSensor1->init();
  
  // Capteur lumière
  lightSensor1 = new LightSensor(LIGHT_SENSOR_PIN, "Light Sensor");
  lightSensor1->init();
  lightSensor1->setDarkThreshold(300);
  
  // Capteur sonore
  soundSensor1 = new SoundSensor(SOUND_SENSOR_PIN, "Sound Sensor");
  soundSensor1->init();
  soundSensor1->setThreshold(600);
  
  // Affichage de confirmation
  lcd1->clear();
  lcd1->printMessage("Initialisation");
  lcd1->setColor(0, 0, 100); // Bleu
  
  // Séquence sonore et lumineuse de démarrage
  led1->blink(200, 3);
  
  int melody[] = {523, 659, 784, 1047}; // Do, Mi, Sol, Do aigu
  buzzer1->playMelody(melody, 4);
  
  // Affichage final
  lcd1->clear();
  lcd1->printMessage("Pret!");
  lcd1->setColor(0, 100, 0); // Vert
  
  Serial.println("Systeme pret!");
  Serial.println("=== MODES DISPONIBLES ===");
  Serial.println("1. Appui bouton: Mode demonstration");
  Serial.println("2. Touch sensor: Mode surveillance");
  Serial.println("3. Systeme automatique");
}
*/
}


void Application::run(void)
{
  led1->blink(500, 3);

}
