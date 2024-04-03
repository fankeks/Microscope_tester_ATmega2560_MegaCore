#include <My_Timer.h>


namespace Timer1
{
    int begin(int count, int prescaler)
    {
        cli();                    // отключить глобальные прерывания
        TCCR1A = 0;               // установить регистры в 0
        TCCR1B = 0;
        
        OCR1A = count;            // установка регистра совпадения для прерывания каждую миллисекунду
        TCCR1B |= (1 << WGM12);   // включить CTC режим 

        if (prescaler == 1)
        {
            TCCR1B |= (1 << CS00);
            sei();
            return 1;
        }
        if (prescaler == 8)
        {
            TCCR1B |= (1 << CS01);
            sei();
            return 1;
        }
        if (prescaler == 64)
        {
            TCCR1B |= (1 << CS01);
            TCCR1B |= (1 << CS00);
            sei();
            return 1;
        }
        if (prescaler == 256)
        {
            TCCR1B |= (1 << CS02);
            sei();
            return 1;
        }
        if (prescaler == 1024)
        {
            TCCR1B |= (1 << CS00);
            TCCR1B |= (1 << CS02);
            sei();
            return 1;
        }
        sei();
        return 0;
    }

    void start()
    {
        TIMSK1 |= (1 << OCIE1A);  // включить прерывание по совпадению таймера 
    }

    void stop()
    {
        TIMSK1 &= ~(1 << OCIE1A);  // выключить прерывание по совпадению таймера 
    }
}


//ISR(TIMER1_COMPA_vect)
//{
  //digitalWrite(LEDPIN, !digitalRead(LEDPIN));
//}