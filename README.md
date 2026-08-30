# gimbal-stm32
Dual-axis self-stabilizing gimbal using STM32F411 + MPU-6050 IMU.
Built from scratch without any flight controller libraries.

## Hardware
- STM32F411CEU6 (BlackPill)
- MPU-6050 IMU (I2C)
- SG90 servo x2
- ST-Link V2

## Architecture
- Custom MPU-6050 I2C driver (mpu6050.c / mpu6050.h) — raw register 
  reads, no external library
- Complementary filter fusing accelerometer + gyroscope data for 
  stable angle estimation
- PID controller with deadband and output scaling
- PWM servo control via TIM3 (50Hz, 1000-2000us pulse range)

## Current Status
**Both axes: working (sensor isolated from servo).** When the 
MPU-6050 is held/mounted separately from the servo body (not 
rigidly attached), both X and Y axes correctly estimate tilt angle 
and drive the corresponding servo in the right direction to 
compensate. Demonstrated in the video below.

-x-axis:
https://drive.google.com/file/d/1HsSbvuQHlDuv8ZtWv_lvnNa-CsRnEFdB/view?usp=sharing
-y-axis:
https://drive.google.com/file/d/1jk1Q20R54CHwHIKCQWLDTwcZgavYpe7B/view?usp=sharing

**Sensor mounted directly on servo body: not yet stable.** When 
MPU-6050 is rigidly attached to the servo body itself, servo motion 
introduces vibration into the accelerometer reading, causing the 
control loop to oscillate — see Known Limitations.



## Known Limitations
- Mounting MPU-6050 directly on a servo body introduces vibration 
  into the accelerometer reading, causing oscillation. Both axes 
  work correctly when the sensor is mechanically isolated from the 
  servo (see demo) — this is the current testing configuration. 
  Fully integrating sensor and servo onto a single rigid stabilized 
  platform requires vibration isolation between them.
- A CH340 USB-serial debug adapter failed during testing (hardware 
  fault, unrelated to the STM32/sensor/servo circuit).

