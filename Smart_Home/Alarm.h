#ifndef ALARM_H_
#define ALARM_H_

#include "Buzzer.h"
#include "UltrasonicSensor.h"
#include <Arduino.h>
#include "Lcd.h"

class Alarm {
private:
    bool armed;
    Buzzer* buzzer;
    UltrasonicSensor* ultrasonicSensor;
    Lcd* lcd;
    float thresholdDistance = 10.0;
public:
    Alarm();
    ~Alarm();
    void init(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor, Lcd* lcd);
    void arm();
    void disarm();
    bool isArmed() const;
    void trigger();
    unsigned long getTriggerTime() const;
    void setTriggerTime(unsigned long time);
};

#endif