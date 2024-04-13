#include "DI_group_register_PS.h"


PositionSensorsDIRegisters::PositionSensorsDIRegisters(DI_register_PS::Register* regs, byte n)
{
    __regs = regs;
    __n = n;
}

bool PositionSensorsDIRegisters::is_available(word addres)
{
    word start_addr = __regs[0].__addr;
    word end_addr = start_addr + __n;
    if((start_addr <= addres) & (addres < end_addr)) return true;
    return false;
}

DI_register_PS::Register PositionSensorsDIRegisters::get(word addres)
{
    return __regs[addres - __regs[0].__addr];
}

DI_register_PS::Register PositionSensorsDIRegisters::get_pin(byte ind)
{
    return __regs[0];
}

DI_register_PS::Register regs[POSITION_SENSOR_NUMBRS];
DI_register_PS::Register* create_regs(DI_register_PS::Register* regs)
{
    for (int i=0; i<POSITION_SENSOR_NUMBRS; i++)
    {
        regs[i].__object = &(POSITION_SENSORS[i]);
        regs[i].__addr = POSITION_SENSOR_START_ADDRES + i;
        regs[i].__value = 0;
    }
    return regs;
}

PositionSensorsDIRegisters POSITION_SENSORS_DI_REGISTERS(create_regs(regs), POSITION_SENSOR_NUMBRS);