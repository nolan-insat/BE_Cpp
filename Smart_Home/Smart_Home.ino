#include <Arduino.h>

#include <ESP8266WebServer.h>

#include <ESP8266WiFi.h>

#include "Application.h"
#include "Device.h"
#include "Actuator.h"
#include "Led.h"

#include <Wire.h>
#include <rgb_lcd.h>

// rgb_lcd lcd;

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
  /*
  Wire.begin(D2, D1);
  delay(100);
  lcd.begin(16, 2); // ecran 16x2
  lcd.setCursor(0, 0);
  lcd.print("HELLO LCD!");
  */

}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
}
