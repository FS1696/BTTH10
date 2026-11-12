/****************/
// Mã sinh viên: [Điền mã sinh viên]
// Họ tên: [Điền họ tên]
/****************/
#include "HomeConfiguration.h"
#include <stdexcept>

HomeConfiguration::HomeConfiguration()
    : homeName_("My Home"), nightLightLevel_(30) {}

HomeConfiguration& HomeConfiguration::Instance() {
    // Biến static cục bộ được khởi tạo an toàn luồng từ C++11.
    static HomeConfiguration instance;
    return instance;
}

const std::string& HomeConfiguration::GetHomeName() const {
    return homeName_;
}

void HomeConfiguration::SetHomeName(const std::string& homeName) {
    homeName_ = homeName;
}

int HomeConfiguration::GetNightLightLevel() const {
    return nightLightLevel_;
}

void HomeConfiguration::SetNightLightLevel(int level) {
    if (level < 0 || level > 100) {
        throw std::out_of_range("Night light level must be in range 0..100.");
    }
    nightLightLevel_ = level;
}
