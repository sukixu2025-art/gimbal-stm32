/*
 * mpu6050.c
 *
 *  Created on: Jul 7, 2026
 *      Author: cuike
 */

#include "mpu6050.h"
#include "main.h"

#define MPU_ADDR      (0x68 << 1)
#define REG_PWR_MGMT  0x6B
#define REG_ACCEL     0x3B

extern I2C_HandleTypeDef hi2c1;

void MPU6050_Init(void) {
    uint8_t d = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MPU_ADDR, REG_PWR_MGMT, 1, &d, 1, 100);
}

void MPU6050_Read(int16_t *ax, int16_t *ay, int16_t *az,
                  int16_t *gx, int16_t *gy, int16_t *gz) {
    uint8_t buf[14];
    HAL_I2C_Mem_Read(&hi2c1, MPU_ADDR, REG_ACCEL, 1, buf, 14, 100);
    *ax = (int16_t)(buf[0]  << 8 | buf[1]);
    *ay = (int16_t)(buf[2]  << 8 | buf[3]);
    *az = (int16_t)(buf[4]  << 8 | buf[5]);
    *gx = (int16_t)(buf[8]  << 8 | buf[9]);
    *gy = (int16_t)(buf[10] << 8 | buf[11]);
    *gz = (int16_t)(buf[12] << 8 | buf[13]);
}
