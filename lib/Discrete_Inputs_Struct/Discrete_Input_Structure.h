#pragma once
#include <Arduino.h>


class Discrete_Input_Structure
{
private:
    word start_addres; // Адрес первого эллемента
    byte n; // Колличество пинов
    byte* pins; // Массив пинов
public:
    Discrete_Input_Structure(word start_addres, byte n, byte* pins);
    bool is_available(word addres); // Проверка адреса на соответствие
    byte get(word addres); // Получение пина по адресу
};