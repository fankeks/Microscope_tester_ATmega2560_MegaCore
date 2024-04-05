#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <My_Serial.h>

#define LEDPIN PIN_PB7

unsigned char ch;
unsigned char mes_buffer[64];
unsigned char ans_buffer[64];
int count = 0;
bool flag = false;

 
void setup(void)
{
  pinMode(LEDPIN, OUTPUT);

  My_Serial0::init(9600);
  My_Serial0::en_interrupt_rx();
  My_Serial0::dis_interrupt_tx();
}


void loop()
{

}


ISR(USART0_RX_vect)
{
  My_Serial0::dis_interrupt_rx();

  ch = My_Serial0::read_byte();
  ans_buffer[count++] = ch;
  if (ch == '\n')
  {
    count = 0;
    My_Serial0::en_interrupt_tx();
    My_Serial0::write_byte(ans_buffer[count++]);
  }

  My_Serial0::en_interrupt_rx();
}


ISR(USART0_TX_vect)
{
  if (count < 64) My_Serial0::write_byte(ans_buffer[count++]);
  else 
  {
    count = 0;
    My_Serial0::dis_interrupt_tx();
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
  }
}