## GPIO handler

### Set ON-OFF for PIN

Folder tree

```
GPIOTest/
├── gpioTestComponent/
│   ├── Component.cdef
│   └── gpioTest.c
└── gpioTest.adef
```

**gpioTest.c**

```c
#include "legato.h"
#include "interfaces.h"

//Power off Pin D5 - le_gpioPin8
//Pin D5 on IoT expansion card
static void power_off_pin_D5(){
    // le_gpioPin8_SetPushPullOutput(LE_GPIOPIN8_ACTIVE_HIGH, true);

    //This will turn OFF the LED
    le_gpioPin8_SetPushPullOutput(LE_GPIOPIN8_ACTIVE_LOW, true);
}

COMPONENT_INIT {
    power_off_pin_D5();
}
```

**Component.cdef**

```
requires:
{
    api:
    {
        le_gpioPin8 = le_gpio.api
    }
}


sources:
{
    gpioTest.c
}
```

**main.adef**

```
executables:
{
    gpioTest = ( gpioTestComponent )
}

bindings:
{
    gpioTest.gpioTestComponent.le_gpioPin8 -> gpioService.le_gpioPin8
}
 
processes:
{
    run:
    {
        ( gpioTest )
    }
}
```

### Blink LED with timer delay

```c
#include "legato.h"
#include "interfaces.h"

bool status = true;

void changeLEDStatus
(
	le_timer_Ref_t timer_refer
)
{
    status = !status;
    le_gpioPin8_SetPushPullOutput(LE_GPIOPIN8_ACTIVE_HIGH, status);
}

void timerFunction(int delayTime){
    le_timer_Ref_t delayInterval = le_timer_Create("Blink LED Timer");
    le_timer_SetMsInterval(delayInterval, delayTime);
    le_timer_SetRepeat(delayInterval, 0);
	le_timer_SetHandler(delayInterval, changeLEDStatus);
	le_timer_Start(delayInterval);
}

COMPONENT_INIT {
    timerFunction(1000);
}
```

### Binding

* Bind GPIO 8 to Socket D5-Pin D5 on Grove IoT expansion shield.
* Print out while Blinking LED.

**gpioTest.adef**

```c
executables:
{
    gpioTest = ( gpioTestComponent )
}

bindings:
{
    gpioTest.gpioTestComponent.le_gpioPinD5 -> gpioService.le_gpioPin8
}
 
processes:
{
    run:
    {
        ( gpioTest )
    }
}
```
**Component.cdef**
```
requires:
{
    api:
    {
        le_gpioPinD5 = le_gpio.api
    }
}


sources:
{
    gpioTest.c
}
```
**gpioTest.c**
```c
#include "legato.h"
#include "interfaces.h"

bool status = true;

void changeLEDStatus
(
	le_timer_Ref_t timer_refer
)
{
    LE_INFO("Delay 2 second");
    status = !status;
    le_gpioPinD5_SetPushPullOutput(LE_GPIOPIND5_ACTIVE_HIGH, status);
}

void timerFunction(int delayTime){
    le_timer_Ref_t delayInterval = le_timer_Create("Blink LED Timer");
    le_timer_SetMsInterval(delayInterval, delayTime);
    le_timer_SetRepeat(delayInterval, 0);
	le_timer_SetHandler(delayInterval, changeLEDStatus);
	le_timer_Start(delayInterval);
}

COMPONENT_INIT {
    timerFunction(2000);
}
```

### Read value from PIN

```c
#include "legato.h"
#include "interfaces.h"

static void read_from_pin_D5(){

    le_gpioPin8_SetInput(LE_GPIOPIN8_ACTIVE_HIGH);
    while(1){
        LE_INFO("%d",le_gpioPin8_Read());
    }
}

COMPONENT_INIT {
    read_from_pin_D5();
}
```
