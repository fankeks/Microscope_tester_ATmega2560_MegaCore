#ifndef POSITION_SENSORS_H
#define POSITION_SENSORS_H

#include <Arduino.h>


class PositionSensors
{
private:
    word __start_addres; // Адрес первого эллемента
    byte __n;            // Колличество пинов
    byte* __pins;        // Массив пинов
public:
    PositionSensors(word start_addres, byte n, byte* pins);
    bool is_available(word addres); // Проверка адреса на соответствие
    byte get(word addres);          // Получение пина по адресу
    byte get_pin(byte ind);         // Получение пина по индексу
};

#endif