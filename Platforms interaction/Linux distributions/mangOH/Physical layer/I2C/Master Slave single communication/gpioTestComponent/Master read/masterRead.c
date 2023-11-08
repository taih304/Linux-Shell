#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"

#define SLAVE_I2C_ADDR 0x30 //I2C address of module
static const char *slave_i2c_bus = "/dev/i2c-4";
static uint8_t buf[1];

//--------------------------------------------------------------------------------------------------
/**
 * Read data from slave I2C address when Timer expires
 */
//--------------------------------------------------------------------------------------------------

static void readFromI2CSlave
(
    le_timer_Ref_t timerRef
)
{   
    i2cReceiveBytes(slave_i2c_bus, SLAVE_I2C_ADDR, buf, 1);
    LE_INFO("Data from I2C slave %d", buf[0]);
}

COMPONENT_INIT {
    le_timer_Ref_t i2cMasterTimer = le_timer_Create("I2C master timer");
    le_timer_SetMsInterval(i2cMasterTimer, 500);
    le_timer_SetRepeat(i2cMasterTimer, 0);
	le_timer_SetHandler(i2cMasterTimer, readFromI2CSlave);
    le_timer_Start(i2cMasterTimer);
}