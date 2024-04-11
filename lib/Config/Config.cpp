#include "Config.h"


// Modbus object
Modbus SLAVE(SERIAL_PORT, SLAVE_ID, RS485_CTRL_PIN);


// Sensor object
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
Discrete_Input_Structure SENSORS(SENSOR_START_ADDRES, SENSOR_NUMBRS, pins);