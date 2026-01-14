#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int sigPin): Sensor(sigPin) {}

UltrasonicSensor::UltrasonicSensor(int sigPin, String name)
    : Sensor(sigPin, name) {}

void UltrasonicSensor::init() {
    pinMode(pin, INPUT);
}

void UltrasonicSensor::deactivate() {
    // Rien à faire pour ce type de capteur
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


/*

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) : Sensor(triggerPin, "Motion Sensor"), echoPin(echoPin) {}

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin, String name) : Sensor(triggerPin, name), echoPin(echoPin) {}

void UltrasonicSensor::init() {
    pinMode(this->pin, OUTPUT);     
    pinMode(this->echoPin, INPUT);  
    this->isActive = true;
}

void UltrasonicSensor::deactivate() {
    Sensor::deactivate();
}

float UltrasonicSensor::readDistance() {
    if (!this->isActive) return -1.0;
    
    digitalWrite(this->pin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pin, LOW);
    
    // Lecture dur�e echo
    long duration = pulseIn(this->echoPin, HIGH);
    
    // Calcul distance (vitesse du son = 340 m/s)
    float distance = duration * 0.034 / 2;
    
    return distance;
}

bool UltrasonicSensor::isObjectDetected(float maxDistance) {
    float distance = readDistance();
    
    if (distance > 0 && distance < maxDistance) {
        Serial.print("Object detected at ");
        Serial.print(distance);
        Serial.println(" cm");
        return true;
    }
    return false;
}

int UltrasonicSensor::getEchoPin() const {return echoPin;}

*/