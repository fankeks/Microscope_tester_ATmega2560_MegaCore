#ifndef DI_REGISTER_PS_H
#define DI_REGISTER_PS_H

#include <Config.h>

namespace DI_register_PS
{
    struct DIRegisterPS
    {
        byte __object;
        word __addr;
        byte __value;
    };

    byte get(DIRegisterPS* reg);
    bool set(DIRegisterPS* reg, byte value);
    byte run(DIRegisterPS* reg);
}

#endif