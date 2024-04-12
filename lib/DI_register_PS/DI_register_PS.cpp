#include "DI_register_PS.h"


namespace DI_register_PS
{
    byte get(DIRegisterPS* reg)
    {
        return reg -> __value;
    }

    bool set(DIRegisterPS* reg, byte value)
    {
        reg -> __value = value;
        return true;
    }

    byte run(DIRegisterPS* reg)
    {
        reg -> __value = digitalRead(*(reg -> __object));
        return 1;
    }
}