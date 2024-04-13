#include "DI_register_PS.h"


namespace DI_register_PS
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
        update(reg);
        reg -> __value = value;
        return 1;
    }

    byte step(Register* reg)
    {
        reg -> __value = digitalRead(*(reg -> __object));
        return 1;
    }
}