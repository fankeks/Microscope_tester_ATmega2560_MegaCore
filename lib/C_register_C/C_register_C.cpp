#include "C_register_C.h"


namespace C_register_C
{
    byte update(Register* reg)
    {
        reg -> __value = digitalRead(*(reg -> __object));
        return 1;
    }

    byte get(Register* reg)
    {
        update(reg);
        return reg -> __value;
    }

    byte set(Register* reg, byte value)
    {
        reg -> __value = value;
        return 1;
    }

    byte step(Register* reg)
    {
        if(reg -> __value != digitalRead(*(reg -> __object)))
        {
            digitalWrite(*(reg -> __object), reg -> __value);
        }
        return 1;
    }
}