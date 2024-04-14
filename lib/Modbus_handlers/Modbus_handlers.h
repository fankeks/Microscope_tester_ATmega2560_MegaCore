#ifndef MODBUS_HANDLERS_H
#define MODBUS_HANDLERS_H

#include <Arduino.h>
#include <ModbusSlave.h>
#include <DI_group_register_PS.h>
#include <I_register_PS.h>
#include <C_register_C.h>


uint8_t readDigital(uint8_t fc, uint16_t address, uint16_t length);

uint8_t readInput(uint8_t fc, uint16_t address, uint16_t length);

uint8_t readCoil(uint8_t fc, uint16_t address, uint16_t length);

uint8_t writeCoil(uint8_t fc, uint16_t address, uint16_t length);

extern C_register_C::Register C_GROUP_REGISTERS_C[CAPTURES_NUMBERS];
C_register_C::Register* create_C_GROUP_REGISTERS_C(C_register_C::Register* regs);

#endif