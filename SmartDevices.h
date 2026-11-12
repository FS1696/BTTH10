/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#ifndef SMART_DEVICES_H
#define SMART_DEVICES_H

#include "DeviceInterfaces.h"
#include <string>

// Đèn thông minh: chỉ hỗ trợ bật/tắt.
class SmartLight : public IDevice {
private:
    std::string name_;
    bool isOn_;

public:
    explicit SmartLight(const std::string& name);

    void TurnOn();
    void TurnOff();
    const std::string& GetName() const;
    bool IsOn() const;
};

// Quạt thông minh: chỉ hỗ trợ bật/tắt.
class SmartFan : public IDevice {
private:
    std::string name_;
    bool isOn_;

public:
    explicit SmartFan(const std::string& name);

    void TurnOn();
    void TurnOff();
    const std::string& GetName() const;
    bool IsOn() const;
};

// Cửa thông minh vừa là thiết bị bật/tắt, vừa có khả năng khóa/mở khóa.
class SmartDoor : public IDevice, public ILockable {
private:
    std::string name_;
    bool isOn_;
    bool isLocked_;

public:
    explicit SmartDoor(const std::string& name);

    void TurnOn();
    void TurnOff();
    const std::string& GetName() const;
    void Lock();
    void Unlock();
    bool IsOn() const;
    bool IsLocked() const;
};

#endif // SMART_DEVICES_H
