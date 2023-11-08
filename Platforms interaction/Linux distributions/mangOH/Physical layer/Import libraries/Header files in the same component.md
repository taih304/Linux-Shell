### Code defined in header file

Import ``.h`` file from the same folder

```
test_mangoh_yellow/
├── test_component/
│   ├── Component.cdef
│   └── main.c
|   └── test_library.c
|   └── test_library.h
└── main.adef
```
**test_library.h**
```c
#include "legato.h"

void helloworld(){
	LE_INFO("Hello, world in test library");
}
```
**test_library.c**
```c
#include "legato.h"

COMPONENT_INIT
{}
```
**main.c**
```c
#include "legato.h"
#include "interfaces.h"
#include "test_library.h"


COMPONENT_INIT {
    while(1){
        helloworld();
    }    
}
```

### Code define in c file

(Same architecture like above)

**test_library.h**

```c
#include "legato.h"

void helloworld();
```

**test_library.c**

```c
#include "test_library.h"

void helloworld(){
	LE_INFO("Hello, world in seperated file 123");
}
```
**Component.cdef**
```c
sources:
{
    test_library.c
    main.c
}
```
