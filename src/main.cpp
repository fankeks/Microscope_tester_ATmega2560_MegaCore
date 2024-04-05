#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <My_Serial.h>

#define LEDPIN PIN_PB7

unsigned char ch;

 
void setup(void)
{
  pinMode(LEDPIN, OUTPUT);

  My_Serial0::init(9600);
  My_Serial0::en_interrupt_rx();
  My_Serial0::en_interrupt_tx();
}


void loop()
{

}


ISR(USART0_RX_vect)
{
  My_Serial0::dis_interrupt_rx();
  ch = My_Serial0::read_byte();
  My_Serial0::write_byte(ch);
  My_Serial0::en_interrupt_rx();
}


ISR(USART0_TX_vect)
{
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}