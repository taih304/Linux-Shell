#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"

#define SLAVE_I2C_ADDR 0x30 //I2C address of module
static const char *slave_i2c_bus = "/dev/i2c-4";
static uint8_t count = 0;

//--------------------------------------------------------------------------------------------------
/**
 * Send increasing number from master to slave I2C address when Timer expires 
 */
//--------------------------------------------------------------------------------------------------


static void sendToI2CSlave
(
    le_timer_Ref_t timerRef
)
{
    i2cSendBytes(slave_i2c_bus, SLAVE_I2C_ADDR, &count, 1);
    count++;
}

COMPONENT_INIT {
    le_timer_Ref_t i2cMasterTimer = le_timer_Create("I2C master timer");
    le_timer_SetMsInterval(i2cMasterTimer, 500);
    le_timer_SetRepeat(i2cMasterTimer, 0);
	le_timer_SetHandler(i2cMasterTimer, sendToI2CSlave);
    le_timer_Start(i2cMasterTimer);
}
