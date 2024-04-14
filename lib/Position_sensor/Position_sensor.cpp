#include "Position_sensor.h"


namespace Position_Sensor
{
    byte read(Sensor* sen)
    {
        sen -> __prev_value = sen -> __cur_value;
        sen -> __cur_value = digitalRead(sen -> __pin);
        if (sen -> __interrupt_fuc) sen -> __interrupt_fuc();
        return sen -> __cur_value;
    }

    byte attachinterrupt(Sensor* sen, void (*interrupt_fuc)())
    {
        sen -> __interrupt_fuc = interrupt_fuc;
    }
}