#include "mpu9250I2CUtils.h"
#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

float Axyz[3];
float Gxyz[3];
float Mxyz[3];

uint8_t buffer_m[6]; //buffer_m to read magnetometer data
uint8_t bufferWhoAmI[1]; //bufferWhoAmI to check device connection

void getCompassData(void)
{
    i2cReceiveBytes_v2(slave_i2c_bus, MPU9150_RA_MAG_ADDRESS, MPU9150_RA_MAG_XOUT_L, buffer_m, 6);
	
    mx = ((int16_t)(buffer_m[1]) << 8) | buffer_m[0] ;
	my = ((int16_t)(buffer_m[3]) << 8) | buffer_m[2] ;
	mz = ((int16_t)(buffer_m[5]) << 8) | buffer_m[4] ;	
	
	Mxyz[0] = (double) mx * 1200 / 4096;
	Mxyz[1] = (double) my * 1200 / 4096;
	Mxyz[2] = (double) mz * 1200 / 4096;
}

static void getData
(
    le_timer_Ref_t ledTimerRef
)
{
    // getAcceleration(&ax, &ay, &az);
    // getRotation(&gx, &gy, &gz); 
    getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    //To DO
    //getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);

    //TO DO
    //getCompassData();

    Axyz[0] = (double) ax / 16384;
    Axyz[1] = (double) ay / 16384;
    Axyz[2] = (double) az / 16384; 

    Gxyz[0] = (double) gx * 250 / 32768;
    Gxyz[1] = (double) gy * 250 / 32768;
    Gxyz[2] = (double) gz * 250 / 32768;

    LE_INFO("Axyz[0]: %f", Axyz[0]);
    LE_INFO("Axyz[1]: %f", Axyz[1]);
    LE_INFO("Axyz[2]: %f", Axyz[2]);
    LE_INFO("Gxyz[0]: %f", Gxyz[0]);
    LE_INFO("Gxyz[1]: %f", Gxyz[1]);
    LE_INFO("Gxyz[2]: %f", Gxyz[2]);
    // LE_INFO("Mxyz[0]: %f", Mxyz[0]);
    // LE_INFO("Mxyz[1]: %f", Mxyz[1]);
    // LE_INFO("Mxyz[2]: %f", Mxyz[2]);
}

COMPONENT_INIT {
    setClockSource();
    setFullScaleGyroRange();
    setFullScaleAccelRange();

    //Test connection with IMU9DOF
    i2cReceiveBytes_v2(slave_i2c_bus, I2C_ADDRESS, MPU6050_RA_WHO_AM_I, bufferWhoAmI, 1);
    LE_INFO("device ID: 0x%x \n", bufferWhoAmI[0]);

    i2cSendBytes(slave_i2c_bus, I2C_ADDRESS, interruptConfig, sizeof(interruptConfig));
    usleep(10000); //sleep 10 milisecond
	
    i2cSendBytes(slave_i2c_bus, MPU9150_RA_MAG_ADDRESS, magnetometerReadCommand, sizeof(magnetometerReadCommand));
    usleep(10000); //sleep 10 milisecond

    le_timer_Ref_t imu9dofTimer = le_timer_Create("IMU9DOF timer");
    le_timer_SetMsInterval(imu9dofTimer, 1000);
    le_timer_SetRepeat(imu9dofTimer, 0);
    le_timer_SetHandler(imu9dofTimer, getData);
    le_timer_Start(imu9dofTimer);
}