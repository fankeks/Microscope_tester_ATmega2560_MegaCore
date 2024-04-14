#ifndef POSITION_SENSOR_H
#define POSITION_SENSOR_H

#include <Arduino.h>

namespace Position_Sensor
{
    struct Sensor
    {
        byte __pin;
        byte __prev_value = 0;
        byte __cur_value = 0;
        void (*__interrupt_fuc)() = 0;
    };

    byte read(Sensor* sen);
    byte attachinterrupt(Sensor* sen, void (*interrupt_fuc)());
}

#endif