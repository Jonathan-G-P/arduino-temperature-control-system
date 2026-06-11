# Arduino Temperature Control System

## Schematic
<img width="2000" height="2000" alt="Schematic Arduino Temperature Control System" src="https://github.com/user-attachments/assets/534c7cea-ca1f-4345-aaf8-2d110a210c0d" />

## Overview
This project implements a temperature monitoring and control system based on an Arduino Uno and an LM35 temperature sensor.

The system continuously measures temperature, applies a moving average filter to reduce noise, and controls a ventilation system using hysteresis to prevent rapid switching. It also includes warning and critical alarm levels indicated by LEDs and a buzzer.

This project was developed as a practical application of embedded systems, sensor interfacing, signal processing, and basic control techniques commonly used in electronic and industrial monitoring systems.

## Hardware
- Arduino Uno
- LM35 Temperature Sensor
- Relay Module
- DC Fan
- Yellow LED (Warning)
- Red LED (Critical)
- Active Buzzer
- 2N2219 NPN Transistors
- 1N4007 Flyback Diode

## Control Logic
The system implements ON/OFF control with hysteresis.

- Fan ON  : Temperature > 30°C
- Fan OFF : Temperature < 28°C

Alarm levels:

- Warning : Temperature > 35°C
- Critical: Temperature > 40°C

## Features
- Real-time temperature monitoring
- Moving average filtering
- Hysteresis-based fan control
- Warning and critical alarms
- Relay-driven ventilation
- Serial monitoring interface

## Future Improvements
- PID temperature control
- LCD display
- SD card data logging
- Wireless monitoring using ESP32
- PCB implementation
