#ifndef MODBUS_HANDLERS_H
#define MODBUS_HANDLERS_H

#include <Config.h>
#include <Arduino.h>
#include <ModbusSlave.h>


uint8_t readDigital(uint8_t fc, uint16_t address, uint16_t length);

#endif