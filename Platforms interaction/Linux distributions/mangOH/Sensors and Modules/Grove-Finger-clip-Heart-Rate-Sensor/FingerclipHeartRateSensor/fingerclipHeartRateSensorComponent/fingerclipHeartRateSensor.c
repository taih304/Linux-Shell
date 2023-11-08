#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"

#define HEART_RATE_SENSOR_I2C_ADDR        0x50 //I2C address of module
static const char *heart_rate_sensor_i2c_bus = "/dev/i2c-4";
static uint8_t buf[1];

//--------------------------------------------------------------------------------------------------
/**
 * Read heart rate from sensor when timer expires
 */
//--------------------------------------------------------------------------------------------------

static void heartRateSensorRead
(
    le_timer_Ref_t ledTimerRef
)
{
    i2cReceiveBytes(heart_rate_sensor_i2c_bus, HEART_RATE_SENSOR_I2C_ADDR, buf, 1);
    LE_INFO("Heart rate is %d", buf[0]);
}

COMPONENT_INIT {
    le_timer_Ref_t heartRateSensorTimer = le_timer_Create("Heart rate sensor timer");
    le_timer_SetMsInterval(heartRateSensorTimer, 1000);
    le_timer_SetRepeat(heartRateSensorTimer, 0);
    le_timer_SetHandler(heartRateSensorTimer, heartRateSensorRead);
    le_timer_Start(heartRateSensorTimer);
}