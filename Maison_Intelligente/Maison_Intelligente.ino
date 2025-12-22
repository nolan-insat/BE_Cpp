#include <Arduino.h>

#include "Application.h"
#include "Equipement.h"
#include "Actionneur.h"
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
