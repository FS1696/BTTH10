/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "DeviceInterfaces.h"
#include <memory>
#include <string>

// Factory tập trung việc khởi tạo và lựa chọn lớp thiết bị cụ thể.
class DeviceFactory {
public:
    static std::unique_ptr<IDevice> Create(const std::string& type,
                                           const std::string& name);
};

#endif // DEVICE_FACTORY_H
