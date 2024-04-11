#include "Position_sensors_interrupt_handlers.h"


void interrupt_PA0()
{

}
void interrupt_PA1()
{
    
}
void interrupt_PA2()
{

}
void interrupt_PA3()
{
    
}
void interrupt_PA4()
{
    
}
void interrupt_PA5()
{
    
}
void interrupt_PA6()
{
    
}
void interrupt_PA7()
{
    
}
//-----------------------------------------------------------------------------
void interrupt_PC0()
{

}
void interrupt_PC1()
{
    
}
void interrupt_PC2()
{

}
void interrupt_PC3()
{
    
}
void interrupt_PC4()
{
    
}
void interrupt_PC5()
{
    
}
void interrupt_PC6()
{
    
}
void interrupt_PC7()
{
    
}
//-----------------------------------------------------------------------------
void interrupt_PF0()
{

}
void interrupt_PF1()
{
    
}
void interrupt_PF2()
{

}
void interrupt_PF3()
{
    
}
void interrupt_PF4()
{
    
}
void interrupt_PF5()
{
    
}
void interrupt_PF6()
{
    
}
void interrupt_PF7()
{
    
}


void (*POSITION_SENSORS_INTERRUPT_HANDLERS[POSITION_SENSOR_NUMBRS])(void) = 
{
    interrupt_PA0,
    interrupt_PA1,
    interrupt_PA2,
    interrupt_PA3,
    interrupt_PA4,
    interrupt_PA5,
    interrupt_PA6,
    interrupt_PA7,

    interrupt_PC0,
    interrupt_PC1,
    interrupt_PC2,
    interrupt_PC3,
    interrupt_PC4,
    interrupt_PC5,
    interrupt_PC6,
    interrupt_PC7,

    interrupt_PF0,
    interrupt_PF1,
    interrupt_PF2,
    interrupt_PF3,
    interrupt_PF4,
    interrupt_PF5,
    interrupt_PF6,
    interrupt_PF7,
};