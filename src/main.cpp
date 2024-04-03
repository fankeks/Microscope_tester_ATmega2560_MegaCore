#include <Arduino.h>
#include <My_Timer.h>


#define LEDPIN PIN_PB7
int Delay = 500;


void setup()
{
  // Частота МК 16 МГц
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  Timer1::begin(15000, 1024);
  Timer1::start();
}


void loop()
{
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
  delay(Delay);
}

ISR(TIMER1_COMPA_vect)
{
  Serial.printf("1\n");
}