#include "FlexibleMemoryController.hpp"

namespace ATC {
FlexibleMemoryController::FlexibleMemoryController(
    uintptr_t fmcRegisterAddress,
    uintptr_t fmcDataAddress
) :
    fmcRegisterAddress_ {
        reinterpret_cast<decltype(fmcRegisterAddress_)>( // NOLINT
            fmcRegisterAddress
        )
    },
    fmcDataAddress_ {
        reinterpret_cast<decltype(fmcDataAddress_)>( // NOLINT
            fmcDataAddress
        )
    } {}

void FlexibleMemoryController::writeRegister(uint16_t registerAddress) {
    *fmcRegisterAddress_ = registerAddress;
}

void FlexibleMemoryController::writeData(uint16_t data) {
    *fmcDataAddress_ = data;
}

void FlexibleMemoryController::write(const Instruction& instruction) {
    *fmcRegisterAddress_ = instruction.registerAddress;
    *fmcDataAddress_ = instruction.data;
}

uint16_t FlexibleMemoryController::readData() const {
    return *fmcDataAddress_;
}

uint16_t FlexibleMemoryController::read(uint16_t registerAddress) const {
    *fmcRegisterAddress_ = registerAddress;

    return *fmcDataAddress_;
}
}