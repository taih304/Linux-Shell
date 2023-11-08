``client.c`` call function defined in ``server.c`` with ``library_api.api``.

### Tree directory

```
ExtendHelloWorld/
├── extendHelloWorld.adef
├── library_api.api
├── printClient/
│   ├── client.c
│   └── Component.cdef
└── printServer/
    ├── Component.cdef
    └── server.c
```

### printServer

``library_api.api``

```
FUNCTION print_helloworld();
```

``server.c``

```cpp
#include "legato.h"
#include "interfaces.h"
 
void library_api_print_helloworld()
{
    LE_INFO("Hello, World!");
}
 
COMPONENT_INIT
{
}
```

``Component.cdef``

```
provides:
{
    api:
    {
        library_api = library_api.api
    }
}

sources:
{
    server.c
}
```

**Explain**: ``FUNCTION print_helloworld()`` is defined in ``library_api.api``, in order for other program to call this function, it has to be defined by this format in ``server.c``

``<interface-name>_<api-function-name>``

Where: ``library_api = library_api.api`` with ``library_api`` is the interface; and its ``api-function-name`` is ``print_helloworld``

So its name in ``server.c`` is ``library_api_print_helloworld``

### printClient

**Component.cdef**

```
requires:
{
    api:
    {
        library_api = library_api.api
    }
}

sources:
{
    client.c
}
```

``client.c``

```c
#include "legato.h"
#include "interfaces.h"

COMPONENT_INIT
{
    library_api_print_helloworld();
}
```

### extendHelloWorld

```
executables:
{
    helloClient = ( printClient )
    helloServer = ( printServer )
}
 
processes:
{
    run:
    {
        ( helloClient )
        ( helloServer )
    }
}

 
bindings:
{
    helloClient.printClient.library_api -> helloServer.printServer.library_api
}
```