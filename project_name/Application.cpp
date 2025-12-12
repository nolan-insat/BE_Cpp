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

  Wire.begin(D2, D1); // <-- IMPORTANT !
  delay(100);
  
  lcd.begin(16, 2);
  lcd.setRGB(255, 0, 255);
  lcd.clear();
  
  lcd.print("Connexion");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.print(".");
  }
  lcd.clear();
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
  lcd.println("WiFi deconnecte");
  delay(100);

}


void Application::run(void)
{


}
