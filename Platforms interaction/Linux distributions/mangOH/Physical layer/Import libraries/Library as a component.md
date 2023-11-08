### Import library as a component

Calling function inside ``testLibrary.h`` for ``gpioTest.c``

```
GPIOTest/
├── gpioTestComponent/
│   ├── Component.cdef
│   └── gpioTest.c
|── testLibraryComponent/
|    ├── Component.cdef
|    └── testLibrary.c
|    └── testLibrary.h
└──gpioTest.adef
```

**testLibraryComponent/testLibrary.h**

```c
#include "legato.h"
#include "interfaces.h"

void printFunction(){
    LE_INFO("Hello World testLibrary");
}
```

**testLibraryComponent/testLibrary.c**

```c
#include "testLibrary.h"

COMPONENT_INIT {
    printFunction();
}
```
**testLibraryComponent/Component.cdef**
```c
sources:
{
    testLibrary.c
}
```


**gpioTestComponent/gpioTest.c**

```c
#include "legato.h"
#include "interfaces.h"
#include "testLibrary.h"

COMPONENT_INIT {
    le_timer_Ref_t delayInterval = le_timer_Create("Hello World timer");
    le_timer_SetMsInterval(delayInterval, 1000);
    le_timer_SetRepeat(delayInterval, 0);
	le_timer_SetHandler(delayInterval, printFunction);
    le_timer_Start(delayInterval);
}
```

**testLibraryComponent/Component.cdef**
```c
cflags:
{
    -I$CURDIR/../testLibraryComponent
    -std=c99
}

requires:
{
    component:
    {
        $CURDIR/../testLibraryComponent
    }
}

sources:
{
    gpioTest.c
}
```
**gpioTest.adef**
```c
executables:
{
    gpioTest = ( gpioTestComponent )
}
 
processes:
{
    run:
    {
        process1 = ( gpioTest )
    }
}
```