#include <Arduino.h>
#include <Config.h>
#include <Modbus_handlers.h>

 
void setup(void)
{
    // Инициализация датчиков
    for(int i=0; i<SENSOR_NUMBRS; i++)
    {
        pinMode(SENSORS.get(i + SENSOR_START_ADDRES), INPUT);
    }

    // Подключаем обработчики запросов Modbus RTU
    SLAVE.cbVector[CB_READ_DISCRETE_INPUTS] = readDigital;

    // Инициализация порта
    SERIAL_PORT.begin(SERIAL_BAUDRATE);
    SLAVE.begin(SERIAL_BAUDRATE);
}


void loop()
{
    SLAVE.poll();
}