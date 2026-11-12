/****************/
// Mã sinh viên: 202419074
// Họ tên: Vũ Thành Lâm
/****************/
#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H

#include "DeviceInterfaces.h"

// Facade cung cấp các thao tác mức cao cho một nhóm thiết bị.
// Lớp này chỉ phụ thuộc vào abstraction, không phụ thuộc lớp cụ thể.
class SmartHomeFacade {
private:
    IDevice& light_;
    IDevice& fan_;
    ILockable& door_;

public:
    SmartHomeFacade(IDevice& light, IDevice& fan, ILockable& door);

    void GoToWork();
    void GoToSleep();
};

#endif // SMART_HOME_FACADE_H
