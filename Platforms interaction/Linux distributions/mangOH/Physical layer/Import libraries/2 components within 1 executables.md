Tree directory

```
ExtendHelloWorld/
├── extendHelloWorld.adef
├── printClient/
│   ├── client.c
│   └── Component.cdef
└── printServer/
    ├── Component.cdef
    ├── server.c
    └── server.h
```

### printServer

``server.c``

```c
#include "legato.h"
#include "interfaces.h"
#include "server.h"
 
void printer_Print(const char* message)
{
    LE_INFO("******** Client says '%s'", message);
}
 
COMPONENT_INIT
{
}
```

``server.h``

```c
#ifndef SERVER_H_INC
#define SERVER_H_INC
 
LE_SHARED void printer_Print(const char* message); //define in server.c
 
#endif
```

``Component.cdef``

```
sources:
{
    server.c
}
```

### printClient

``client.c``

```c
#include "legato.h"
#include "interfaces.h"
#include "server.h"

COMPONENT_INIT
{
    LE_INFO("Asking server to print 'Hello, world!'");
    printer_Print("Hello, world!");
}
```

``Component.cdef``

```
cflags:
{
    -I $CURDIR/../printServer
}

sources:
{
    client.c
}
```
### extendHelloWorld.adef

```
executables:
{
    helloPrint = ( printClient printServer )
}
 
processes:
{
    run:
    {
        ( helloPrint )
    }
}
```

### Result

```
Dec  8 11:18:56 swi-mdm9x28-wp user.info Legato:  INFO | helloPrint[4480]/printClient T=main | client.c _printClient_COMPONENT_INIT() 7 | Asking server to print 'Hello, world!'
Dec  8 11:18:56 swi-mdm9x28-wp user.info Legato:  INFO | helloPrint[4480]/printServer T=main | server.c printer_Print() 7 | ******** Client says 'Hello, world!'
```