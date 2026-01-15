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
#include "LightController.h"



// #include <SoftwareSerial.h>

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

  // ledSalon = new Led(LED_PIN, "LED System");
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
  // Nettoyage LightController en premier
    if (lightController) {
        delete lightController;
    }
    
    // Nettoyage des p�riph�riques
    if (ledSalon) {
        delete ledSalon;
    }
    
    if (lightSensor1) {
        delete lightSensor1;
    }

    if (ultrasonicSensor1) {
        delete ultrasonicSensor1;
    }
}  

void Application::init(void)
{
  buzzer1->init();
  lcd1->init();
  lcd1->setColor(100, 100, 100);
  lcd1->clear();
  Serial.println("Initialisation des capteurs...");

  button1->init();
  touchSensor1->init();
  lightSensor1->init();
  soundSensor1->init();
  ultrasonicSensor1->init();

  wifi1->connecter("MONPC", "HelloHello");
  delay(1000);

  Serial.println("WiFi connected");

  lcd1->printMessage("IP:");
  delay(500);
  lcd1->clear();
  lcd1->printMessage(wifi1->getIP());


  alarm1->init(buzzer1, ultrasonicSensor1, lcd1);

  server->on("/", [&](){
    String html = "<html><body>"  ;
    html += "<p>Hugo et Nolan - INSA Toulouse</p>";
    html += "<h1>SMART HOME</h1>";

    // ALARM CONTROLS
    html += "<h2>Alarm</h2>";
    html += "<a href='/alarm?state=on'><button>ARM</button></a>";
    html += "<a href='/alarm?state=off'><button>DISARM</button></a>";
    html += "<p>Current alarm state: ";
    html += (alarm1->isArmed() ? "ARMED" : "DISARMED");
    html += "</p>";

    // LIGHT MODE
    html += "<h2>Light Mode</h2>";
    html += "<a href='/light?mode=auto'><button>AUTO</button></a>";
    html += "<a href='/light?mode=manual'><button>MANUAL</button></a>";
    html += "<p>Current light mode: ";
    html += (lightController->isAutoMode() ? "AUTO" : "MANUAL");
    html += "</p>";

    // PARAM FORM
    html += "<h2>Parameters</h2>";
    html += "<form action='/setParams' method='GET'>";

    // Pré-remplir les champs avec les valeurs actuelles
    html += "Detection distance (cm): <input name='dist' type='number' value='";
    html += String(lightController->getDetectionDistance());
    html += "'><br>";

    html += "Light threshold: <input name='lux' type='number' value='";
    html += String(lightController->getLightThreshold());
    html += "'><br>";

    html += "<input type='submit' value='Apply'>";
    html += "</form>";

    html += "</body></html>";

    server->send(200, "text/html", html);
  });

  // ALARM CONTROL ENDPOINT
  server->on("/alarm", [&](){
    if (server->hasArg("state")) {
        if (server->arg("state") == "on") alarm1->arm();
        if (server->arg("state") == "off") alarm1->disarm();
    }
    server->sendHeader("Location", "/");
    server->send(303);
  });

  // LIGHT MODE ENDPOINT
  server->on("/light", [&](){
    if (server->hasArg("mode")) {
        if (server->arg("mode") == "auto") lightController->setAutoMode(true);
        if (server->arg("mode") == "manual") lightController->setAutoMode(false);
    }
    server->sendHeader("Location", "/");
    server->send(303);
  });

  // PARAM SETTER
  server->on("/setParams", [&](){
    if (server->hasArg("dist")) {
        float d = server->arg("dist").toFloat();
        lightController->setDetectionDistance(d);
    }
    if (server->hasArg("lux")) {
        int l = server->arg("lux").toInt();
        lightController->setLightThreshold(l);
    }
    server->sendHeader("Location", "/");
    server->send(303);
  });

  server->begin();


  try {
    // Init LED
    ledSalon = new Led(LED_PIN, "LED Salon");
    ledSalon->init();
    ledSalon->turnOff();
        
    // Initialisation du LightController
    lightController = new LightController(ultrasonicSensor1, lightSensor1, ledSalon);
    lightController->init();

    // Configurer les paramètres
    lightController->setDetectionDistance(10.0);  // 10 cm
    lightController->setLightThreshold(350);       // Seuil de luminosité

    } catch (LightControllerException& e) {
      Serial.print("Erreur LightController: ");
      Serial.println(e.what());
    }
}



void Application::run(void)
{
  unsigned long currentTime = millis();

  try {
    // Mettre à jour le LightController
    if (lightController) {
      bool lightState = lightController->update();
    }

    // Touch sensor pour changer le mode du light controller
    if (touchSensor1->isTouched()){
      lightController->toggleMode();
    }
    // Si on appuie sur le bouton, et qu'on est en mode manuel, la led s'allume
    if (!lightController->isAutoMode()){
      if (button1->isPressed()) {
        lightController->toggleLight();
      }
    }

    static unsigned long lastStatsTime = 0;
    
    if (currentTime - lastStatsTime > 10000) {
      if (lightController) {
        lightController->printStats();
      }
      lastStatsTime = currentTime;
    }       
    } catch (LightControllerException& e) {
      Serial.print("Erreur LightController dans run(): ");
      Serial.println(e.what());
    }
  
  server->handleClient();

  alarm1->trigger();
  Serial.println(String(ultrasonicSensor1->readDistance()));
  Serial.println(ultrasonicSensor1->isObjectDetected(10.0));
  Serial.println(alarm1->isArmed());


}

