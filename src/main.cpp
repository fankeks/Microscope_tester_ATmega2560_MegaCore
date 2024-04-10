#include <Arduino.h>
#include "config.h"

 
void setup(void)
{
    // Инициализация датчиков
    for(int i=0; i<SENSOR_NUMBRS; i++)
    {
        pinMode(sensors.get(i+SENSOR_START_ADDRES), INPUT);
    }
    // Инициализация порта
    Serial.begin(9600);
}


void loop()
{
    Serial.write((char) digitalRead(sensors.get(20+SENSOR_START_ADDRES)));
    delay(500);
}