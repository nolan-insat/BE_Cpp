#include "Application.h"
#include <Arduino.h>
#include "Led.h"
#include "Equipement.h"
#include "Actionneur.h"

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
