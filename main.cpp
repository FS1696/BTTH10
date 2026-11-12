/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#include "DeviceFactory.h"
#include "HomeConfiguration.h"
#include "SmartDevices.h"
#include "SmartHomeFacade.h"

#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// In kết quả cho từng tình huống kiểm thử và cập nhật thống kê.
void ReportTest(bool passed, const std::string& description,
                int& passedCount, int& failedCount) {
    if (passed) {
        ++passedCount;
        std::cout << "[PASS] " << description << std::endl;
    } else {
        ++failedCount;
        std::cout << "[FAIL] " << description << std::endl;
    }
}

int main() {
    int passedCount = 0;
    int failedCount = 0;

    // T1: Factory tạo đúng ba loại thiết bị và trả về abstraction IDevice.
    std::unique_ptr<IDevice> light =
        DeviceFactory::Create("light", "Living room light");
    std::unique_ptr<IDevice> fan =
        DeviceFactory::Create("fan", "Living room fan");
    std::unique_ptr<IDevice> door =
        DeviceFactory::Create("door", "Main door");

    const bool t1 = dynamic_cast<SmartLight*>(light.get()) != NULL
                 && dynamic_cast<SmartFan*>(fan.get()) != NULL
                 && dynamic_cast<SmartDoor*>(door.get()) != NULL
                 && light->GetName() == "Living room light"
                 && fan->GetName() == "Living room fan"
                 && door->GetName() == "Main door";
    ReportTest(t1, "T1 - Factory creates light, fan and door correctly",
               passedCount, failedCount);

    // T2: Loại thiết bị không được hỗ trợ phải phát sinh invalid_argument.
    bool t2 = false;
    try {
        std::unique_ptr<IDevice> camera =
            DeviceFactory::Create("camera", "Front camera");
    } catch (const std::invalid_argument&) {
        t2 = true;
    }
    ReportTest(t2, "T2 - Unsupported camera type throws invalid_argument",
               passedCount, failedCount);

    // T3: Hai lần truy cập Singleton phải trả về cùng một đối tượng.
    HomeConfiguration& config1 = HomeConfiguration::Instance();
    HomeConfiguration& config2 = HomeConfiguration::Instance();
    const bool t3 = &config1 == &config2;
    ReportTest(t3, "T3 - HomeConfiguration returns the same instance",
               passedCount, failedCount);

    // Lấy interface khóa/mở khóa từ thiết bị cửa do Factory tạo.
    ILockable* lockableDoor = dynamic_cast<ILockable*>(door.get());
    if (lockableDoor == NULL) {
        std::cout << "Cannot obtain ILockable interface from SmartDoor." << std::endl;
        return 1;
    }

    SmartLight* lightConcrete = dynamic_cast<SmartLight*>(light.get());
    SmartFan* fanConcrete = dynamic_cast<SmartFan*>(fan.get());
    SmartDoor* doorConcrete = dynamic_cast<SmartDoor*>(door.get());

    // Facade nhận các abstraction, không cần biết tên lớp cụ thể.
    SmartHomeFacade facade(*light, *fan, *lockableDoor);

    // Chuẩn bị trạng thái ban đầu để quan sát chế độ Đi làm.
    lightConcrete->TurnOn();
    fanConcrete->TurnOn();
    lockableDoor->Unlock();

    // T4: GoToWork phải tắt đèn, tắt quạt và khóa cửa.
    std::cout << std::endl;
    facade.GoToWork();
    const bool t4 = !lightConcrete->IsOn()
                 && !fanConcrete->IsOn()
                 && doorConcrete->IsLocked();
    ReportTest(t4, "T4 - GoToWork turns off light/fan and locks the door",
               passedCount, failedCount);

    // T5: GoToSleep phải tắt quạt, khóa cửa, bật đèn và đọc cấu hình ánh sáng.
    config1.SetNightLightLevel(45);
    std::cout << std::endl;
    facade.GoToSleep();
    const bool t5 = !fanConcrete->IsOn()
                 && doorConcrete->IsLocked()
                 && lightConcrete->IsOn()
                 && config2.GetNightLightLevel() == 45;
    ReportTest(t5, "T5 - GoToSleep applies device states and reads night-light level",
               passedCount, failedCount);

    // T6: Factory không phân biệt chữ hoa/thường và bỏ khoảng trắng hai đầu.
    std::unique_ptr<IDevice> mixedCaseLight =
        DeviceFactory::Create("  LiGhT  ", "Bedroom light");
    const bool t6 = dynamic_cast<SmartLight*>(mixedCaseLight.get()) != NULL;
    ReportTest(t6, "T6 - Factory accepts mixed-case type with surrounding spaces",
               passedCount, failedCount);

    // T7: Có thể sử dụng cửa thông qua ILockable mà không cần gọi SmartDoor trực tiếp.
    lockableDoor->Unlock();
    const bool unlockedThroughInterface = !doorConcrete->IsLocked();
    lockableDoor->Lock();
    const bool lockedThroughInterface = doorConcrete->IsLocked();
    ReportTest(unlockedThroughInterface && lockedThroughInterface,
               "T7 - SmartDoor supports the separate ILockable abstraction",
               passedCount, failedCount);

    std::cout << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "TEST SUMMARY: " << passedCount << " PASS, "
              << failedCount << " FAIL" << std::endl;
    std::cout << "==============================================" << std::endl;

    return (failedCount == 0) ? 0 : 1;
}
