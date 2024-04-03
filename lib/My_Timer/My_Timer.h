#pragma once
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


namespace Timer1
{
    int begin(int count, int prescaler);
    void start();
    void stop();
}