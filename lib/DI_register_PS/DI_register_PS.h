#ifndef DI_REGISTER_PS_H
#define DI_REGISTER_PS_H

#include <Config.h>

namespace DI_register_PS
{
    struct Register
    {
        byte* __object;
        word __addr;
        byte __value;
    };

    byte update(Register* reg);
    byte get(Register* reg);
    byte set(Register* reg, byte value);
    byte step(Register* reg);
}

#endif