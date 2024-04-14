#include <Arduino.h>
#include <Config.h>
#include <Modbus_handlers.h>
#include <Position_sensors_interrupt_handlers.h>

 
void setup(void)
{
    // Инициализация переферии для тестирования
    pinMode(LEDPIN, OUTPUT);

    // Инициализация датчиков положения
    for(byte i=0; i<POSITION_SENSOR_NUMBRS; i++)
    {
        pinMode(POSITION_SENSORS[i].__pin, INPUT);
        Position_Sensor::attachinterrupt(POSITION_SENSORS + i, POSITION_SENSORS_INTERRUPT_HANDLERS[i]);
    }

    // Подключаем обработчики запросов Modbus RTU
    SLAVE.cbVector[CB_READ_DISCRETE_INPUTS] = readDigital;
    SLAVE.cbVector[CB_READ_INPUT_REGISTERS] = readInput;

    // Инициализация порта
    SERIAL_PORT.begin(SERIAL_BAUDRATE);
    SLAVE.begin(SERIAL_BAUDRATE);
}


void loop()
{
    for (byte i=0; i< POSITION_SENSOR_NUMBRS; i++)
    {
        Position_Sensor::read(POSITION_SENSORS + i);
    }
    SLAVE.poll();
}