#ifndef MY_TIMER_H
#define MY_TIMER_H

#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


namespace Timer1
{
    int begin(int count, int prescaler);
    void start();
    void stop();
}

#endif