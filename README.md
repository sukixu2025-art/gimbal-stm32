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
**X-axis: working.** Closed-loop stabilization demonstrated — 
tilting the sensor produces a correctly-directed servo correction 
that returns the platform toward level. Stable to within ±0.1° 
at rest.

**Y-axis: implemented, not fully stable.** Angle estimation and PID 
computation are correct (verified via serial output), but closing 
the loop on the servo currently causes oscillation — traced to 
mechanical vibration coupling between the servo and IMU when 
mounted together (see Known Limitations).

## Known Limitations
- Mounting MPU-6050 directly on a servo body introduces vibration 
  into the accelerometer reading, causing the control loop to react 
  to its own corrections. Confirmed by testing with the sensor 
  mechanically isolated from the servo, where tracking is smooth. 
  This is a known challenge in gimbal design.
- Y-axis PID gains have not yet converged on a stable configuration.
- A CH340 USB-serial debug adapter failed during testing (hardware 
  fault, unrelated to the STM32/sensor/servo circuit).

## Next Steps
- Vibration-isolate the IMU mount (foam standoff)
- Low-pass filter on raw accelerometer data before angle estimation
- Re-tune Y-axis PID gains
- Real-time PID tuning over serial (no reflash required)
