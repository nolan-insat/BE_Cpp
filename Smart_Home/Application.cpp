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
#include "Button.h"
#include "TouchSensor.h"
#include "LightSensor.h"
#include "SoundSensor.h"
#include "Alarm.h"
#include "UltrasonicSensor.h"







#include <HardwareSerial.h>

#include <Wire.h>
#include <rgb_lcd.h>

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>

// Notes standard (Hz)
#define DO  523  
#define RE  587  
#define MI  659  
#define FA  698  
#define SOL  784  
#define LA  880  
#define SI  988  
#define DO_AIGU  1047 

#define LED_PIN D5
#define BUZZER_PIN D8
#define LCD_PIN D1
#define BUTTON_PIN D6
#define TOUCH_PIN D7
#define LIGHT_SENSOR_PIN A0
#define SOUND_SENSOR_PIN A0
#define ULTRASONIC_PIN D3


Application::Application()
{
  Serial.begin(9600);
  Serial.println("=== DEMARRAGE SYSTEME ===");

  server = new ESP8266WebServer(80);

  led1 = new Led(LED_PIN, "LED System");
  buzzer1 = new Buzzer(BUZZER_PIN, "Buzzer System");
  lcd1 = new Lcd(LCD_PIN, "LCD Display");
  button1 = new Button(BUTTON_PIN, "Bouton");
  touchSensor1 = new TouchSensor(TOUCH_PIN, "Touch Sensor");
  lightSensor1 = new LightSensor(LIGHT_SENSOR_PIN, "Light Sensor");
  soundSensor1 = new SoundSensor(SOUND_SENSOR_PIN, "Sound Sensor");
  ultrasonicSensor1 = new UltrasonicSensor(ULTRASONIC_PIN, "Ultrasonic Sensor");
  wifi1 = new Wifi(0, "Wifi1");

  alarm1 = new Alarm();

}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  /*
  led1 = new Led(D5, "Led1");
  led1->init();
 
  buzzer1 = new Buzzer(D8, "Buzzer1");
  buzzer1->init();

  int melody[] = {DO, MI, SOL, DO_AIGU, DO_AIGU, SOL, MI, DO};
  buzzer1->playBeep();
  
  buzzer1->playMelody(melody, 8);
  buzzer1->playMelody(melody, 8);
  buzzer1->playMelody(melody, 8);
  
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
  */
  
  // Serial.println("=== INITIALISATION SYSTEME ===");
  /*
  // 1. LED (Actionneur)
  led1 = new Led(LED_PIN, "LED System");
  led1->init();
  led1->activate();
  
  // 2. Buzzer (Actionneur)
  buzzer1 = new Buzzer(BUZZER_PIN, "Buzzer System");
  buzzer1->init();
  buzzer1->playBeep();
  
  // 3. LCD (Actionneur)
  lcd1 = new Lcd(LCD_PIN, "LCD Display");
  
  lcd1->init();
  lcd1->setColor(0, 100, 0); // Vert
  lcd1->printMessage("Systeme OK");
  delay(1000);
  lcd1->printMessage("Initialisation...");
  delay(1000);

  
  // 4. Capteurs
  // Bouton poussoir
  lcd1->clear();
  button1 = new Button(BUTTON_PIN, "Bouton");
  lcd1->printMessage("Init Bouton");
  button1->init();
  lcd1->printMessage("Bouton OK\n");
  delay(500);
  
  // Capteur tactile
  lcd1->clear();
  touchSensor1 = new TouchSensor(TOUCH_PIN, "Touch Sensor");
  lcd1->printMessage("Init Touch Sensor");
  touchSensor1->init();
  lcd1->printMessage("Touch Sensor OK");
  delay(500);
  
  // Capteur lumi�re
  lcd1->clear();
  lightSensor1 = new LightSensor(LIGHT_SENSOR_PIN, "Light Sensor");
  lcd1->printMessage("Init Light Sensor");
  lightSensor1->init();
  lightSensor1->setDarkThreshold(300);
  lcd1->printMessage("Light Sensor OK\n");
  delay(500);
  
  // Capteur sonore
  soundSensor1 = new SoundSensor(SOUND_SENSOR_PIN, "Sound Sensor");
  soundSensor1->init();
  soundSensor1->setThreshold(600);
  
  // Affichage de confirmation
  lcd1->clear();
  lcd1->printMessage("Initialisation");
  lcd1->setColor(0, 0, 100); // Bleu
  
  // S�quence sonore et lumineuse de d�marrage
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
  */



  led1->init();
  led1->blink(200, 2);
  buzzer1->init();
  buzzer1->playBeep();
  lcd1->init();
  lcd1->setColor(100, 100, 100);
  delay(1000);
  lcd1->clear();
  Serial.println("Initialisation des capteurs...");

  button1->init();
  Serial.println("Bouton OK");
  touchSensor1->init();
  Serial.println("Touch Sensor OK");
  lightSensor1->init();
  Serial.println("Light Sensor OK");
  soundSensor1->init();
  Serial.println("Sound Sensor OK");
  ultrasonicSensor1->init();
  Serial.println("Ultrasonic Sensor OK");

  wifi1->connecter("moi", "Nolan31*");

  Serial.println("WiFi connected");

  lcd1->printMessage("IP:");
  lcd1->printMessage(wifi1->getIP());
  Serial.println("Capteurs initialises.");
  delay(500);


  server->on("/ON", [&](){
        alarm1->arm(buzzer1);
        server->send(200, "text/plain", "Alarm armed");
    });

    server->on("/OFF", [&](){
        alarm1->disarm(buzzer1);
        server->send(200, "text/plain", "Alarm disarmed");
    });

    server->begin();
}


void Application::run(void)
{
  led1->blink(500, 3);

  server->handleClient();

  alarm1->trigger(buzzer1, ultrasonicSensor1);

}
