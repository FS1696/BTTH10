/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#include "SmartHomeFacade.h"
#include "HomeConfiguration.h"
#include <iostream>

SmartHomeFacade::SmartHomeFacade(IDevice& light, IDevice& fan, ILockable& door)
    : light_(light), fan_(fan), door_(door) {}

void SmartHomeFacade::GoToWork() {
    std::cout << "--- Mode: GO TO WORK ---" << std::endl;
    light_.TurnOff();
    fan_.TurnOff();
    door_.Lock();
}

void SmartHomeFacade::GoToSleep() {
    std::cout << "--- Mode: GO TO SLEEP ---" << std::endl;
    fan_.TurnOff();
    door_.Lock();
    light_.TurnOn();

    const int level = HomeConfiguration::Instance().GetNightLightLevel();
    // Theo đặc tả, facade đọc cấu hình và thông báo mức sáng được áp dụng.
    std::cout << "Night light level: " << level << "%" << std::endl;
}
