#include "legato.h"
#include "interfaces.h"

#define SENSOR_TIMER_IN_MS (5)

static le_timer_Ref_t SensorTimerRef;

//--------------------------------------------------------------------------------------------------
/**
 * Sensor is triggered when a collision is detected
 */
//--------------------------------------------------------------------------------------------------
bool isTriggered(){
    if(!le_gpioPinD5_Read())//if a collision is detected
    {
        usleep(50000);//delay 50 milisecond
        if(!le_gpioPinD5_Read()) //if a collision is detected again
            return true;// the collision sensor triggers as there is a collision
    }
    return false;
}


static void CollisionSensorTimerHandler
(
    le_timer_Ref_t sensorTimerRef
)
{
    if(isTriggered())
    {
        LE_INFO("collision detected");
        usleep(2000000); //delay 2 second
    }
    else
    {
        LE_INFO("collision undetected");
    } 
}

COMPONENT_INIT {
    le_gpioPinD5_SetInput(LE_GPIOPIND5_ACTIVE_HIGH);

    SensorTimerRef = le_timer_Create("Collision sensor timer");
    le_timer_SetMsInterval(SensorTimerRef, SENSOR_TIMER_IN_MS);
    le_timer_SetRepeat(SensorTimerRef, 0);
    le_timer_SetHandler(SensorTimerRef, CollisionSensorTimerHandler);
    le_timer_Start(SensorTimerRef);
}