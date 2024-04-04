#include <Arduino.h>


#define LEDPIN PIN_PB7


void setup()
{
  // Частота МК 16 МГц
  pinMode(LEDPIN, OUTPUT);

  cli();
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Turn on the transmission and reception circuitry
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // 8 бит сообщение
  UCSR0C &= ~(1 << USBS0);                // 1 стоповый бит
  // Скорость
  UBRR0H = (9600 >> 8);                   // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
  UBRR0L = 9600;                          // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

  UCSR0B |= (1 << RXCIE0);                // Enable the USART Receive Complete interrupt (USART_RX)
  sei();
}


void loop()
{
  
}


ISR(USART0_RX_vect)
{
  char ch = UDR0;           // Считать данные
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}