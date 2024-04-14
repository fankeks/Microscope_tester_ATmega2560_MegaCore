#include "Config.h"


// Modbus object
Modbus SLAVE(SERIAL_PORT, SLAVE_ID, RS485_CTRL_PIN);


// Sensor object
Position_Sensor::Sensor PS_1 = {PIN_PA0, 0, 0, 0};
Position_Sensor::Sensor PS_2 = {PIN_PA1, 0, 0, 0};
Position_Sensor::Sensor PS_3 = {PIN_PA2, 0, 0, 0};
Position_Sensor::Sensor PS_4 = {PIN_PA3, 0, 0, 0};
Position_Sensor::Sensor PS_5 = {PIN_PA4, 0, 0, 0};
Position_Sensor::Sensor PS_6 = {PIN_PA5, 0, 0, 0};
Position_Sensor::Sensor PS_7 = {PIN_PA6, 0, 0, 0};
Position_Sensor::Sensor PS_8 = {PIN_PA7, 0, 0, 0};

Position_Sensor::Sensor PS_9 = {PIN_PC0, 0, 0, 0};
Position_Sensor::Sensor PS_10 = {PIN_PC1, 0, 0, 0};
Position_Sensor::Sensor PS_11 = {PIN_PC2, 0, 0, 0};
Position_Sensor::Sensor PS_12 = {PIN_PC3, 0, 0, 0};
Position_Sensor::Sensor PS_13 = {PIN_PC4, 0, 0, 0};
Position_Sensor::Sensor PS_14 = {PIN_PC5, 0, 0, 0};
Position_Sensor::Sensor PS_15 = {PIN_PC6, 0, 0, 0};
Position_Sensor::Sensor PS_16 = {PIN_PC7, 0, 0, 0};

Position_Sensor::Sensor PS_17 = {PIN_PF0, 0, 0, 0};
Position_Sensor::Sensor PS_18 = {PIN_PF1, 0, 0, 0};
Position_Sensor::Sensor PS_19 = {PIN_PF2, 0, 0, 0};
Position_Sensor::Sensor PS_20 = {PIN_PF3, 0, 0, 0};
Position_Sensor::Sensor PS_21 = {PIN_PF4, 0, 0, 0};
Position_Sensor::Sensor PS_22 = {PIN_PF5, 0, 0, 0};
Position_Sensor::Sensor PS_23 = {PIN_PF6, 0, 0, 0};
Position_Sensor::Sensor PS_24 = {PIN_PF7, 0, 0, 0};

Position_Sensor::Sensor POSITION_SENSORS[POSITION_SENSOR_NUMBRS] = {
    PS_1,
    PS_2,
    PS_3,
    PS_4,
    PS_5,
    PS_6,
    PS_7,
    PS_8,

    PS_9,
    PS_10,
    PS_11,
    PS_12,
    PS_13,
    PS_14,
    PS_15,
    PS_16,

    PS_17,
    PS_18,
    PS_19,
    PS_20,
    PS_21,
    PS_22,
    PS_23,
    PS_24,
};

// Captures object
byte CAPTURES[CAPTURES_NUMBERS] = {
    PIN_PJ0,
    PIN_PJ1,
    PIN_PJ2,
    PIN_PJ3,
    PIN_PJ4,
    PIN_PJ5,
    PIN_PJ6,
    PIN_PJ7,
};