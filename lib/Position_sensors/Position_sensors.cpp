#include "Position_sensors.h"


PositionSensors::PositionSensors(word start_addres, byte n, byte* pins)
{
    __start_addres = start_addres;
    __n = n;
    __pins = pins;
}

bool PositionSensors::is_available(word addres)
{
    if((__start_addres <= addres) & (addres < (__start_addres + __n))) return true;
    return false;
}

byte PositionSensors::get(word addres)
{
    return __pins[addres - __start_addres];
}

byte PositionSensors::get_pin(byte ind)
{
    return __pins[ind];
}