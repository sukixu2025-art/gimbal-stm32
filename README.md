# gimbal-stm32

Dual-axis self-stabilizing gimbal using STM32F411 + MPU-6050 IMU.
Built from scratch without any flight controller libraries.

## Hardware
- STM32F411CEU6 (BlackPill)
- MPU-6050 IMU (I2C)
- SG90 servo x2
- ST-Link V2

## Current Status
- STM32 toolchain setup and first flash
- UART debug output via printf
- MPU-6050 I2C driver (raw data + physical units)
- Angle estimation via accelerometer (atan2)
- Separated MPU6050 driver into mpu6050.c / mpu6050.h

## In Progress
- Complementary filter (gyro + accelerometer fusion)
- PID controller
- Dual-axis servo stabilization

## Relevance
Directly targets AeroDesign Avionics Firmware requirements:
custom sensor fusion algorithms, STM32 embedded development, IMU integration.
