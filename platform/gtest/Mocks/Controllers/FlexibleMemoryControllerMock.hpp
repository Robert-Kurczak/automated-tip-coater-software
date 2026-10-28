#pragma once

#include "application/System/Ports/IFlexibleMemoryController.hpp"

#include "gmock/gmock.h"

using namespace testing;

namespace ATC {
class FlexibleMemoryControllerMock : public IFlexibleMemoryController {
public:
    MOCK_METHOD(void, writeRegister, (uint16_t), (override));

    MOCK_METHOD(void, writeData, (uint16_t), (override));

    MOCK_METHOD(void, write, (const Instruction&), (override));

    MOCK_METHOD(uint16_t, readData, (), (const override));

    MOCK_METHOD(uint16_t, read, (uint16_t), (const override));
};
};