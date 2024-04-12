#ifndef POSITION_SENSORS_INTERRUPT_HANDLERS_H
#define POSITION_SENSORS_INTERRUPT_HANDLERS_H

#include <Config.h>
/*
PIN_PA0,
PIN_PA1,
PIN_PA2,
PIN_PA3,
PIN_PA4,
PIN_PA5,
PIN_PA6,
PIN_PA7,

PIN_PC0,
PIN_PC1,
PIN_PC2,
PIN_PC3,
PIN_PC4,
PIN_PC5,
PIN_PC6,
PIN_PC7,

PIN_PF0,
PIN_PF1,
PIN_PF2,
PIN_PF3,
PIN_PF4,
PIN_PF5,
PIN_PF6,
PIN_PF7,
*/

void interrupt_PA0();
void interrupt_PA1();
void interrupt_PA2();
void interrupt_PA3();
void interrupt_PA4();
void interrupt_PA5();
void interrupt_PA6();
void interrupt_PA7();

void interrupt_PC0();
void interrupt_PC1();
void interrupt_PC2();
void interrupt_PC3();
void interrupt_PC4();
void interrupt_PC5();
void interrupt_PC6();
void interrupt_PC7();

void interrupt_PF0();
void interrupt_PF1();
void interrupt_PF2();
void interrupt_PF3();
void interrupt_PF4();
void interrupt_PF5();
void interrupt_PF6();
void interrupt_PF7();

extern void (*POSITION_SENSORS_INTERRUPT_HANDLERS[POSITION_SENSOR_NUMBRS])();

#endif