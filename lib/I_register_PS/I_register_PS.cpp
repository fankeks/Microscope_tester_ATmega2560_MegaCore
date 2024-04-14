#include "I_register_PS.h"


namespace I_register_PS
{
    byte update(Register* reg)
    {
        byte pin_value;
        for(byte i=0; i < (reg -> n); i++)
        {
            pin_value = Position_Sensor::read(reg -> __object + i);
            if(pin_value == 0) reg -> __value &= ~(1 << i);
            else reg -> __value |= (1 << i);
        }
        return 1;
    }

    word get(Register* reg)
    {
        update(reg);
        return reg -> __value;
    }

    byte set(Register* reg, word value)
    {
        return 1;
    }

    byte step(Register* reg)
    {
        return 1;
    }
}


I_register_PS::Register DLS_1_16 = {POSITION_SENSORS, 16, 1, 0};
I_register_PS::Register DLS_17_24 = {POSITION_SENSORS + 16, 8, 2, 0};