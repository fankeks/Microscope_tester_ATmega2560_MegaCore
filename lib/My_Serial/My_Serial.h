#pragma once
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


namespace My_Serial0
{
    void init(unsigned long baud);

    void en_interrupt_tx(void);
    void dis_interrupt_tx(void);

    void en_interrupt_rx(void);
    void dis_interrupt_rx(void);

    unsigned char read_byte(void);
    void write_byte(unsigned char msg);
}