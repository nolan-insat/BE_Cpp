#include <Arduino.h>

#include <ESP8266WebServer.h>

#include <ESP8266WiFi.h>

#include "Application.h"
#include "Device.h"
#include "Actuator.h"
#include "Led.h"

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
}
