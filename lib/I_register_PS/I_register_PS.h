#ifndef I_REGISTER_PS_H
#define I_REGISTER_PS_H

#include <Config.h>

namespace I_register_PS
{
    struct Register
    {
        byte* __object;
        byte n;

        word __addr;
        word __value;
    };

    byte update(Register* reg);
    word get(Register* reg);
    byte set(Register* reg, word value);
    byte step(Register* reg);
}

extern I_register_PS::Register DLS_1_16;
extern I_register_PS::Register DLS_17_24;
#endif