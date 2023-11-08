#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"
#include "mpu9250I2CUtils.h"

uint8_t buffer[14];
// uint8_t *buffer;

void setClockSource(){
    i2cSendBytes(slave_i2c_bus, I2C_ADDRESS, setClock, sizeof(setClock));
}

void setFullScaleGyroRange(){
    i2cSendBytes(slave_i2c_bus, I2C_ADDRESS, setGyroRange, sizeof(setGyroRange));
}

void setFullScaleAccelRange(){
    i2cSendBytes(slave_i2c_bus, I2C_ADDRESS, setAccelRange, sizeof(setAccelRange));
}

void getAcceleration(int16_t* ax, int16_t* ay, int16_t* az){
    int res;
    res = i2cReceiveBytes_v2(slave_i2c_bus, I2C_ADDRESS, MPU6050_RA_ACCEL_XOUT_H, buffer, 6); //request 6 byte for getAcceleration
    
     if (res != 0)
    {
        LE_INFO("LE_FAULT");
        // return LE_FAULT;
    }
    else {
        *ax = (((int16_t)buffer[0]) << 8) | buffer[1];
        *ay = (((int16_t)buffer[2]) << 8) | buffer[3];
        *az = (((int16_t)buffer[4]) << 8) | buffer[5];
    }
}

void getRotation(int16_t* x, int16_t* y, int16_t* z) {
    int res;
    res = i2cReceiveBytes_v2(slave_i2c_bus, I2C_ADDRESS, MPU6050_RA_GYRO_XOUT_H, buffer, 6); //request 6 byte for getRotation

    if (res != 0)
    {
        LE_INFO("LE_FAULT");
        // return LE_FAULT;
    }
    else {
        *x = (((int16_t)buffer[0]) << 8) | buffer[1];
        *y = (((int16_t)buffer[2]) << 8) | buffer[3];
        *z = (((int16_t)buffer[4]) << 8) | buffer[5];
    }
}

void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    // buffer = ((uint8_t *) malloc(14));

    i2cReceiveBytes_v2(slave_i2c_bus, I2C_ADDRESS, MPU6050_RA_ACCEL_XOUT_H, buffer, 14);

    *ax = (((int16_t)buffer[0]) << 8) | buffer[1];
    *ay = (((int16_t)buffer[2]) << 8) | buffer[3];
    *az = (((int16_t)buffer[4]) << 8) | buffer[5];
    *gx = (((int16_t)buffer[8]) << 8) | buffer[9];
    *gy = (((int16_t)buffer[10]) << 8) | buffer[11];
    *gz = (((int16_t)buffer[12]) << 8) | buffer[13];
    // free(buffer);
}

COMPONENT_INIT {}