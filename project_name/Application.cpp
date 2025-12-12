/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <SoftwareSerial.h>

#include <Wire.h>
#include "rgb_lcd.h"

#include <ESP8266WiFi.h>

#define BUZZER_PIN D5
// Notes standard (Hz)
#define DO  523  
#define RE  587  
#define MI  659  
#define FA  698  
#define SOL  784  
#define LA  880  
#define SI  988  
#define DO_AIGU  1047 

rgb_lcd lcd;

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
 Serial.begin(9600);
  delay(1000);
  
  WiFi.begin("moi", "Nolan31*");

  Wire.begin(D2, D1);
  delay(100);
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.begin(16, 2);
  lcd.setRGB(255, 0, 255);
  lcd.clear();
  
  lcd.print("Connexion");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.print(".");
  }
  lcd.clear();

  // Mélodie Connexion réussie
  tone(BUZZER_PIN, DO, 150); 
  delay(200);
  tone(BUZZER_PIN, MI, 150); 
  delay(200);
  tone(BUZZER_PIN, SOL, 150); 
  delay(400);
  tone(BUZZER_PIN, DO_AIGU, 300); 
  delay(400);
  lcd.println("\nConnecte!");
  delay(2000);
  lcd.clear();

  lcd.print("IP: ");
  lcd.println(WiFi.localIP());
  delay(2000);
  lcd.clear();

  lcd.println("WiFi OK");
  delay(2000);
  lcd.clear();

  WiFi.disconnect();
  tone(BUZZER_PIN, DO_AIGU, 80); 
  delay(200); 
  tone(BUZZER_PIN, SOL, 80); 
  delay(200);   
  tone(BUZZER_PIN, MI, 80); 
  delay(100);   
  tone(BUZZER_PIN, DO, 250); 
  delay(300); 
  noTone(BUZZER_PIN);
  lcd.println("WiFi deconnecte");
  delay(100);

}


void Application::run(void)
{


}
