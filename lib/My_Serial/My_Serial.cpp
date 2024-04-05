#include <My_Serial.h>


namespace My_Serial0
{    
    void init(unsigned long baud)
    {
        // MCU frecuence = 16000000
        unsigned int b = 16000000 / 16 / baud - 1;
        cli();
        UBRR0H = (unsigned char) (b >> 8);
        UBRR0L = (unsigned char) b;
        UCSR0B |= (1 << TXEN0) | (1 << RXEN0);               //enable transmitter, receiver
        UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);             //8-bit data, 1 stop bit, parity disabled, asynchronous operation
        sei();
    }

    void en_interrupt_tx(void)
    {
        UCSR0B |= (1 << TXCIE0);
    }

    void dis_interrupt_tx(void)
    {
        UCSR0B &= ~(1 << TXCIE0);
    }

    void en_interrupt_rx(void)
    {
        UCSR0B |= (1 << RXCIE0);
    }

    void dis_interrupt_rx(void)
    {
        UCSR0B &= ~(1 << RXCIE0);
    }

    unsigned char read_byte(void)
    {
        while (!(UCSR0A & (1 << RXC0)));
        return UDR0;
    }

    void write_byte(unsigned char msg)
    {
        while(!(UCSR0A & (1 << UDRE0)));               //wait until transmit buffer becomes empty 
        UDR0 = msg;                                    //transmit
    }
}