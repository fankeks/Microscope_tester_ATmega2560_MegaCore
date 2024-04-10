#include "Discrete_Input_Structure.h"


Discrete_Input_Structure::Discrete_Input_Structure(word start_addres, byte n, byte* pins)
{
    start_addres = start_addres;
    n = n;
    pins = pins;
}

bool Discrete_Input_Structure::is_available(word addres)
{
    if(start_addres <= addres <= (start_addres + n)) return true;
    return false;
}

byte Discrete_Input_Structure::get(word addres)
{
    return pins[addres-start_addres];
}