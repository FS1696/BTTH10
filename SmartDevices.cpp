/****************/
// Mã sinh viên: [Điền mã sinh viên]
// Họ tên: [Điền họ tên]
/****************/
#include "SmartDevices.h"
#include <iostream>

SmartLight::SmartLight(const std::string& name)
    : name_(name), isOn_(false) {}

void SmartLight::TurnOn() {
    isOn_ = true;
    std::cout << name_ << ": ON" << std::endl;
}

void SmartLight::TurnOff() {
    isOn_ = false;
    std::cout << name_ << ": OFF" << std::endl;
}

const std::string& SmartLight::GetName() const {
    return name_;
}

bool SmartLight::IsOn() const {
    return isOn_;
}

SmartFan::SmartFan(const std::string& name)
    : name_(name), isOn_(false) {}

void SmartFan::TurnOn() {
    isOn_ = true;
    std::cout << name_ << ": ON" << std::endl;
}

void SmartFan::TurnOff() {
    isOn_ = false;
    std::cout << name_ << ": OFF" << std::endl;
}

const std::string& SmartFan::GetName() const {
    return name_;
}

bool SmartFan::IsOn() const {
    return isOn_;
}

SmartDoor::SmartDoor(const std::string& name)
    : name_(name), isOn_(false), isLocked_(false) {}

void SmartDoor::TurnOn() {
    isOn_ = true;
    std::cout << name_ << ": ON" << std::endl;
}

void SmartDoor::TurnOff() {
    isOn_ = false;
    std::cout << name_ << ": OFF" << std::endl;
}

const std::string& SmartDoor::GetName() const {
    return name_;
}

void SmartDoor::Lock() {
    isLocked_ = true;
    std::cout << name_ << ": LOCKED" << std::endl;
}

void SmartDoor::Unlock() {
    isLocked_ = false;
    std::cout << name_ << ": UNLOCKED" << std::endl;
}

bool SmartDoor::IsOn() const {
    return isOn_;
}

bool SmartDoor::IsLocked() const {
    return isLocked_;
}
