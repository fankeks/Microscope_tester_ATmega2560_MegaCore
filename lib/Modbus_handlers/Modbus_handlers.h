#ifndef MODBUS_HANDLERS_H
#define MODBUS_HANDLERS_H

#include <Arduino.h>
#include <ModbusSlave.h>
#include <DI_group_register_PS.h>
#include <I_register_PS.h>


uint8_t readDigital(uint8_t fc, uint16_t address, uint16_t length);

uint8_t readInput(uint8_t fc, uint16_t address, uint16_t length);

#endif