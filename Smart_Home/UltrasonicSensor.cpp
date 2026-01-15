#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int sigPin): Sensor(sigPin) {}

UltrasonicSensor::UltrasonicSensor(int sigPin, String name)
    : Sensor(sigPin, name) {}

void UltrasonicSensor::init() {
    pinMode(pin, INPUT);
    activate();
}

void UltrasonicSensor::deactivate() {
    deactivate();
}

float UltrasonicSensor::readDistance() {
    // Envoi du trigger
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);

    // Passage en entrée pour lire l'écho
    pinMode(pin, INPUT);
    unsigned long duration = pulseIn(pin, HIGH, 30000);  // timeout = 30ms

    // Conversion en cm
    float distanceCm = duration / 29.0 / 2.0;
    return distanceCm;
}

bool UltrasonicSensor::isObjectDetected(float maxDistance) {
    float d = readDistance();
    return (d > 0 && d <= maxDistance);
}

int UltrasonicSensor::getSigPin() const {
    return pin;
}