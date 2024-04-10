#pragma once
#include <Arduino.h>
#include "Discrete_Input_Structure.h"

// MCU setup
#define F_MCU 16000000

// Discrete Inputs
#define SENSOR_NUMBRS 24
#define SENSOR_START_ADDRES 1
byte pins[SENSOR_NUMBRS] = {
    PIN_PA0,
    PIN_PA1,
    PIN_PA2,
    PIN_PA3,
    PIN_PA4,
    PIN_PA5,
    PIN_PA6,
    PIN_PA7,
    PIN_PC0,
    PIN_PC1,
    PIN_PC2,
    PIN_PC3,
    PIN_PC4,
    PIN_PC5,
    PIN_PC6,
    PIN_PC7,
    PIN_PF0,
    PIN_PF1,
    PIN_PF2,
    PIN_PF3,
    PIN_PF4,
    PIN_PF5,
    PIN_PF6,
    PIN_PF7,
};
Discrete_Input_Structure sensors(SENSOR_START_ADDRES, SENSOR_NUMBRS, pins);