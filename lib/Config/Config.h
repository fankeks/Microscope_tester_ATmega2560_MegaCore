#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <ModbusSlave.h>
#include <Position_sensor.h>

// MCU setup
#define F_MCU 16000000

// Peripherals for testing
#define LEDPIN PIN_PL1

// Modbus RTU slave settings
#define SLAVE_ID 1                 // The Modbus slave ID, change to the ID you want to use.
#define RS485_CTRL_PIN PIN_PH5     // Change to the pin the RE/DE pin of the RS485 controller is connected to.
#define SERIAL_BAUDRATE 115200       // Change to the baudrate you want to use for Modbus communication.
#define SERIAL_PORT Serial         // Serial port to use for RS485 communication, change to the port you're using.
extern Modbus SLAVE;

// Position sensors
#define POSITION_SENSOR_NUMBRS 24
#define POSITION_SENSOR_START_ADDRES 1
extern Position_Sensor::Sensor POSITION_SENSORS[POSITION_SENSOR_NUMBRS];

// Captures
#define CAPTURES_NUMBERS 8
#define CAPTURES_START_ADDRES 1
extern byte CAPTURES[CAPTURES_NUMBERS];

#endif