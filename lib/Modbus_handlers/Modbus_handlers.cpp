#include "Modbus_handlers.h"


// Handle the function codes Read Input Status (FC=01/02) and write back the values from the digital pins (input status).
uint8_t readDigital(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (!POSITION_SENSORS_DI_REGISTERS.is_available(address) || !POSITION_SENSORS_DI_REGISTERS.is_available(address + length - 1))
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }

    // Read the digital inputs.
    for (unsigned int i = address; i<(address + length); i++)
    {
        // Write the state of the digital pin to the response buffer.
        DI_register_PS::DIRegisterPS* reg = &POSITION_SENSORS_DI_REGISTERS.get(i);
        DI_register_PS::run(reg);
        SLAVE.writeDiscreteInputToBuffer(i-address, DI_register_PS::get(reg));
    }
    return STATUS_OK;
}