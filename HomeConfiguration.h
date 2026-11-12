/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#ifndef HOME_CONFIGURATION_H
#define HOME_CONFIGURATION_H

#include <string>

// Singleton lưu cấu hình dùng chung trong toàn bộ ứng dụng.
class HomeConfiguration {
private:
    std::string homeName_;
    int nightLightLevel_;

    HomeConfiguration();

    // Ngăn sao chép để không tạo thêm thể hiện Singleton.
    HomeConfiguration(const HomeConfiguration&) = delete;
    HomeConfiguration& operator=(const HomeConfiguration&) = delete;

public:
    static HomeConfiguration& Instance();

    const std::string& GetHomeName() const;
    void SetHomeName(const std::string& homeName);

    int GetNightLightLevel() const;
    void SetNightLightLevel(int level);
};

#endif // HOME_CONFIGURATION_H
