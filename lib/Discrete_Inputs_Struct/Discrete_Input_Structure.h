#ifndef DISCRETE_INPUT_STRUCTURE_H
#define DISCRETE_INPUT_STRUCTURE_H

#include <Arduino.h>


class Discrete_Input_Structure
{
private:
    word __start_addres; // Адрес первого эллемента
    byte __n;            // Колличество пинов
    byte* __pins;        // Массив пинов
public:
    Discrete_Input_Structure(word start_addres, byte n, byte* pins);
    bool is_available(word addres); // Проверка адреса на соответствие
    byte get(word addres);          // Получение пина по адресу
};

#endif