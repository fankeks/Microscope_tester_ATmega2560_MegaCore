#include "Discrete_Input_Structure.h"


Discrete_Input_Structure::Discrete_Input_Structure(word start_addres, byte n, byte* pins)
{
    __start_addres = start_addres;
    __n = n;
    __pins = pins;
}

bool Discrete_Input_Structure::is_available(word addres)
{
    if((__start_addres <= addres) & (addres <= (__start_addres + __n))) return true;
    return false;
}

byte Discrete_Input_Structure::get(word addres)
{
    return __pins[addres - __start_addres];
}