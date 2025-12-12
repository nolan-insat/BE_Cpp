/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <SoftwareSerial.h>

#include <Wire.h>
#include "rgb_lcd.h"

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
  Serial.println("Initialisation I2C pour LCD...");
  
  // TOUJOURS utiliser D2 et D1 pour I2C
  Wire.begin(D2, D1); // <-- IMPORTANT !
  delay(100);
  
  lcd.begin(16, 2);
  lcd.setRGB(255, 0, 255);
  lcd.clear();
  lcd.print("Hello");

}


void Application::run(void)
{

}
