#ifndef DI_GROUP_REGISTER_PS_H
#define DI_GROUP_REGISTER_PS_H

#include <Config.h>
#include <DI_register_PS.h>

class PositionSensorsDIRegisters
{
private:
    struct DI_register_PS::DIRegisterPS* __regs;       // Массив регистров
    byte __n;                                          // Колличество регистров
public:
    PositionSensorsDIRegisters(DI_register_PS::DIRegisterPS regs[], byte n);
    bool is_available(word addres);                         // Проверка адреса на соответствие
    DI_register_PS::DIRegisterPS get(word addres);          // Получение регистра по адресу
    DI_register_PS::DIRegisterPS get_pin(byte ind);         // Получение регистра по индексу
};

void create_regs();


extern PositionSensorsDIRegisters POSITION_SENSORS_DI_REGISTERS;

#endif