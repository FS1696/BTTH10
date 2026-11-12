/****************/
// Mã sinh viên: [Điền mã sinh viên]
// Họ tên: [Điền họ tên]
/****************/
#include "DeviceFactory.h"
#include "SmartDevices.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace {
// Chuẩn hóa chuỗi: bỏ khoảng trắng hai đầu và chuyển thành chữ thường.
std::string NormalizeType(const std::string& type) {
    const std::string::size_type first = type.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "";
    }

    const std::string::size_type last = type.find_last_not_of(" \t\n\r");
    std::string normalized = type.substr(first, last - first + 1);

    std::transform(normalized.begin(), normalized.end(), normalized.begin(),
        [](unsigned char ch) {
            return static_cast<char>(std::tolower(ch));
        });

    return normalized;
}
}

std::unique_ptr<IDevice> DeviceFactory::Create(const std::string& type,
                                               const std::string& name) {
    const std::string normalizedType = NormalizeType(type);

    if (normalizedType == "light") {
        return std::unique_ptr<IDevice>(new SmartLight(name));
    }
    if (normalizedType == "fan") {
        return std::unique_ptr<IDevice>(new SmartFan(name));
    }
    if (normalizedType == "door") {
        return std::unique_ptr<IDevice>(new SmartDoor(name));
    }

    // Tương đương yêu cầu ArgumentException trong đề C#.
    throw std::invalid_argument("Unsupported device type: " + type);
}
