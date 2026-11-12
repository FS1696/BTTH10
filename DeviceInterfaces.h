/****************/
// Mã sinh viên: [Điền mã sinh viên]
// Họ tên: [Điền họ tên]
/****************/
#ifndef DEVICE_INTERFACES_H
#define DEVICE_INTERFACES_H

#include <string>

// Abstraction chung cho các thiết bị có thể bật và tắt.
class IDevice {
public:
    virtual ~IDevice() {}

    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual const std::string& GetName() const = 0;
};

// Abstraction riêng cho các thiết bị có khả năng khóa/mở khóa.
// Không đưa Lock/Unlock vào IDevice vì đèn và quạt không có hành vi này.
class ILockable {
public:
    virtual ~ILockable() {}

    virtual void Lock() = 0;
    virtual void Unlock() = 0;
};

#endif // DEVICE_INTERFACES_H
