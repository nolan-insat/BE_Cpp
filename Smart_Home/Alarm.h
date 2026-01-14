#ifndef ALARM_H
#define ALARM_H

#include "Buzzer.h"
#include "UltrasonicSensor.h"

class Alarm {
private:
    bool armed;
    unsigned long triggerTime;
public:
    Alarm();
    ~Alarm();
    void arm(Buzzer* buzzer);
    void disarm(Buzzer* buzzer);
    bool isArmed() const;
    void trigger(Buzzer* buzzer, UltrasonicSensor* ultrasonicSensor);
    unsigned long getTriggerTime() const;
    void setTriggerTime(unsigned long time);
};

#endif