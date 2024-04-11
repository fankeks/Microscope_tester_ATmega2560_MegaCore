#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <ModbusSlave.h>
#include <Position_sensors.h>

// MCU setup
#define F_MCU 16000000

// Modbus RTU slave settings
#define SLAVE_ID 1                 // The Modbus slave ID, change to the ID you want to use.
#define RS485_CTRL_PIN PIN_PH5     // Change to the pin the RE/DE pin of the RS485 controller is connected to.
#define SERIAL_BAUDRATE 9600       // Change to the baudrate you want to use for Modbus communication.
#define SERIAL_PORT Serial         // Serial port to use for RS485 communication, change to the port you're using.
extern Modbus SLAVE;

// Discrete Inputs
#define POSITION_SENSOR_NUMBRS 24
#define POSITION_SENSOR_START_ADDRES 1
extern PositionSensors POSITION_SENSORS;

#endif