#ifndef C_REGISTER_C_H
#define C_REGISTER_C_H

#include <Config.h>

namespace C_register_C
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