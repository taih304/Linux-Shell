#include "legato.h"
#include "interfaces.h"
#include "i2cUtils.h"

#define SLAVE_I2C_ADDR 0x11 //I2C address of module
#define CHANNEL_CONTROL_ADDRESS 0x10
#define READ_FIRMWARE_VERSION_ADDRESS 0x13

//1: Channel ON
//0: Channel OFF
#define SET_UP_CHANNEL_STATE 0b1111 //Turn on 4 relay

static const char *slave_i2c_bus = "/dev/i2c-4";

uint8_t control_relay[2] = {CHANNEL_CONTROL_ADDRESS, SET_UP_CHANNEL_STATE};
uint8_t read_firmware_version[1] = {READ_FIRMWARE_VERSION_ADDRESS};
uint8_t firmware_version[1];

//--------------------------------------------------------------------------------------------------
/**
 * Control relay
 */
//--------------------------------------------------------------------------------------------------
static void controlRelay()
{
    i2cSendBytes(slave_i2c_bus, SLAVE_I2C_ADDR, control_relay, sizeof(control_relay));
}

//--------------------------------------------------------------------------------------------------
/**
 * Read firmware version
 */
//--------------------------------------------------------------------------------------------------
static void readFirmWareVersion()
{    
    //Send read_firmware_version command to ask for firmware version
    i2cSendBytes(slave_i2c_bus, SLAVE_I2C_ADDR, read_firmware_version, sizeof(read_firmware_version));

    //Receive firmware version response from module
    i2cReceiveBytes(slave_i2c_bus, SLAVE_I2C_ADDR, firmware_version, 1);
    LE_INFO("Firmware version %d", firmware_version[0]);
}

COMPONENT_INIT {
    controlRelay();
    readFirmWareVersion();
}
