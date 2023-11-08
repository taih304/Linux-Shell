### API

``le_result_t le_timer_SetRepeat (le_timer_Ref_t timerRef, uint32_t  repeatCount)``: Set how many times the timer will repeat.

A value of 0 means repeat indefinitely. The default is 1, so that a one-shot timer is the default.


### Example

Using Timer for 1 second delay: Print out ``"Hello, World!"`` after every 1 second.

```c
#include "legato.h"
#include "interfaces.h"

void printFunction(le_timer_Ref_t adcTimerRef){
    LE_INFO("Hello World timer_function");
}

void timerFunction(int delayTime){
    le_timer_Ref_t delayInterval = le_timer_Create("Hello World timer");
    le_timer_SetMsInterval(delayInterval, delayTime);
    le_timer_SetRepeat(delayInterval, 0);
	le_timer_SetHandler(delayInterval, printFunction);
	le_timer_Start(delayInterval);
}

COMPONENT_INIT {
    timerFunction(3000);
}
```