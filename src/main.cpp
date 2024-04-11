#include <Arduino.h>
#include <Config.h>
#include <Modbus_handlers.h>
#include <Position_sensors_interrupt_handlers.h>

 
void setup(void)
{
    // Инициализация датчиков положения
    for(int i=0; i<POSITION_SENSOR_NUMBRS; i++)
    {
        pinMode(POSITION_SENSORS.get_pin(i), INPUT);
        attachInterrupt(digitalPinToInterrupt(POSITION_SENSORS.get_pin(i)), POSITION_SENSORS_INTERRUPT_HANDLERS[i], RISING);
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