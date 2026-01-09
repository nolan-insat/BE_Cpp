#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) : Sensor(triggerPin, "Motion Sensor"), echoPin(echoPin) {}

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin, string name) : Sensor(triggerPin, name), echoPin(echoPin) {}

void UltrasonicSensor::initialize() {
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
    
    // Lecture durée echo
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