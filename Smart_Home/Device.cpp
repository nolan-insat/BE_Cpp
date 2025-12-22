#include "Device.h"
#include <iostream>

using namespace std;

int Device::DeviceCount = 0;

int Device::getDeviceCount() {
    return DeviceCount;
}

Device::Device(int pin) : pin(pin), isActive(false) {}
Device::Device(int pin, string name) : pin(pin), name(name), isActive(false) {}
Device::~Device() {}