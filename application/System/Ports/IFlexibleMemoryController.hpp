#pragma once

#include <cstdint>

namespace ATC {
class IFlexibleMemoryController {
public:
    struct Instruction {
        uint16_t registerAddress;
        uint16_t data;
        constexpr bool operator==(const Instruction&) const = default;
    };

    IFlexibleMemoryController() = default;
    IFlexibleMemoryController(const IFlexibleMemoryController&) = delete;
    IFlexibleMemoryController& operator=(
        const IFlexibleMemoryController&
    ) = delete;
    IFlexibleMemoryController(IFlexibleMemoryController&&) = delete;
    IFlexibleMemoryController& operator=(IFlexibleMemoryController&&) =
        delete;

    virtual ~IFlexibleMemoryController() = default;

    virtual void writeRegister(uint16_t registerAddress) = 0;
    virtual void writeData(uint16_t data) = 0;
    virtual void write(const Instruction& instruction) = 0;

    [[nodiscard]] virtual uint16_t readData() const = 0;
    [[nodiscard]] virtual uint16_t read(
        uint16_t registerAddress
    ) const = 0;
};
}