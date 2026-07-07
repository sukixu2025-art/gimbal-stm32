/*
 * mpu6050.h
 *
 *  Created on: Jul 7, 2026
 *      Author: cuike
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_


#include "stm32f4xx_hal.h"
#include <stdint.h>

void MPU6050_Init(void);
void MPU6050_Read(int16_t *ax, int16_t *ay, int16_t *az,
                  int16_t *gx, int16_t *gy, int16_t *gz);


#endif /* INC_MPU6050_H_ */
