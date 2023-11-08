#ifndef MPU9250I2CUTILS_H
#define MPU9250I2CUTILS_H

#include "legato.h"
#include "interfaces.h"


#define I2C_ADDRESS 0x68
#define MPU9150_RA_MAG_ADDRESS 0x0C
#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C

#define MPU6050_RA_WHO_AM_I 0x75
#define MPU6050_RA_ACCEL_XOUT_H 0x3B
#define MPU6050_RA_GYRO_XOUT_H  0x43
#define MPU9150_RA_MAG_XOUT_L	0x03
#define MPU6050_RA_INT_PIN_CFG  0x37

#define set_clock 0x01 //0b00000001
#define gyro_250dps 0x00
#define accel_2g 0x00

uint8_t setClock[2] = {PWR_MGMT_1, set_clock};
uint8_t setGyroRange[2] = {GYRO_CONFIG, gyro_250dps};
uint8_t setAccelRange[2] = {ACCEL_CONFIG, accel_2g};
uint8_t interruptConfig[2] = {MPU6050_RA_INT_PIN_CFG, 0x02};
uint8_t magnetometerReadCommand[2] = {0x0A, 0x01};

const char *slave_i2c_bus = "/dev/i2c-4";

extern uint8_t buffer[14];

LE_SHARED void i2cReadData(uint8_t i2cSlaveAddress, uint8_t registerAddress, uint8_t *dataBuffer, uint8_t length);
LE_SHARED void setClockSource();
LE_SHARED void setFullScaleGyroRange();
LE_SHARED void setFullScaleAccelRange();
LE_SHARED void testConnection();
LE_SHARED void getAcceleration(int16_t* ax, int16_t* ay, int16_t* az);
LE_SHARED void getRotation(int16_t* x, int16_t* y, int16_t* z);
LE_SHARED void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
// LE_SHARED void getMotion9(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz);

#endif