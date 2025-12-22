#include "Device.h"
#include <iostream>

using namespace std;

Device::Device(int pin) : pin(pin), isActive(false) {}
Device::Device(int pin, string name) : pin(pin), name(name), isActive(false) {}
Device::~Device() {}