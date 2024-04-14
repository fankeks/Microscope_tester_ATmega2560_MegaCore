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
        SLAVE.writeDiscreteInputToBuffer(i-address, DI_register_PS::get(&POSITION_SENSORS_DI_REGISTERS.get(i)));
    }
    return STATUS_OK;
}

I_register_PS::Register I_group_register_PS[2] = {DLS_1_16, DLS_17_24};

// Handle the function code Read Input Registers (FC=04) and write back the values from the analog input pins (input registers).
uint8_t readInput(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (address < 1 || (address + length - 1) > 2)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }

    // Read the analog inputs
    for (int i = 0; i < length; i++)
    {
        if (1 <= i + 1 <= 2)
        // Write the state of the analog pin to the response buffer.
        SLAVE.writeRegisterToBuffer(i, I_register_PS::get(&I_group_register_PS[i]));
    }

    return STATUS_OK;
}

C_register_C::Register C_GROUP_REGISTERS_C[CAPTURES_NUMBERS];
C_register_C::Register* create_C_GROUP_REGISTERS_C(C_register_C::Register* regs)
{
    for (byte i=0; i<CAPTURES_NUMBERS; i++)
    {
        regs[i].__object = CAPTURES + i;
        regs[i].__addr = CAPTURES_START_ADDRES + i;
        regs[i].__value = 0;
    }
    return regs;
}

// Handle the function codes Read Input Status (FC=01/02) and write back the values from the digital pins (input status).
uint8_t readCoil(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (address < 1 || (address + length - 1) > CAPTURES_NUMBERS)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }

    // Read the digital inputs.
    for (int i = 0; i < CAPTURES_NUMBERS; i++)
    {
        // Write the state of the digital pin to the response buffer.
        SLAVE.writeCoilToBuffer(i, C_register_C::get(C_GROUP_REGISTERS_C + i));
    }

    return STATUS_OK;
}

// Handle the function codes Force Single Coil (FC=05) and Force Multiple Coils (FC=15) and set the digital output pins (coils).
uint8_t writeCoil(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (address < 1 || (address + length - 1) > CAPTURES_NUMBERS)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }

    // Set the output pins to the given state.
    for (int i = 0; i < length; i++)
    {
        // Write the value in the input buffer to the digital pin.
        C_register_C::set(C_GROUP_REGISTERS_C + i, SLAVE.readCoilFromBuffer(i));
        C_register_C::step(C_GROUP_REGISTERS_C + i);
    }

    return STATUS_OK;
}