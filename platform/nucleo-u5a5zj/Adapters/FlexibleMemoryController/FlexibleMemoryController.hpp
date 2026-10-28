#pragma once

#include "application/System/Ports/IFlexibleMemoryController.hpp"

#include <cstdint>

namespace ATC {
class FlexibleMemoryController : public IFlexibleMemoryController {
private:
    volatile uint16_t* fmcRegisterAddress_;
    volatile uint16_t* fmcDataAddress_;

public:
    FlexibleMemoryController(
        uintptr_t fmcRegisterAddress,
        uintptr_t fmcDataAddress
    );

    void writeRegister(uint16_t registerAddress) override;
    void writeData(uint16_t data) override;
    void write(const Instruction& instruction) override;

    [[nodiscard]] uint16_t readData() const override;
    [[nodiscard]] uint16_t read(uint16_t registerAddress) const override;
};
}