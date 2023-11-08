### Print out every 1 second

```c
#include "legato.h"
#include "interfaces.h"

COMPONENT_INIT {
   
    while(1){
        LE_INFO("Hello, World");
        usleep(1000000);
    }    
}
```
### Working with function

```c
#include "legato.h"
#include "interfaces.h"

void print_function(){
    LE_INFO("Hello, World print_function!");
}

void print_function_parameter(char* message){
    LE_INFO(message);
}

COMPONENT_INIT{
    print_function();
    print_function_parameter("print message");
}
```

Add ``while()`` for infinite loop

```c
void print_function(){
    while(1){
        LE_INFO("Hello, World!");
    }    
}
```

### Data type

Print out int number

```c
int number = 19;
LE_INFO("%d", number); //19
```

Convert int to char

```c
int asciiChar = 67;
LE_INFO("Data from I2C slave %c", (char)asciiChar); //character C
```

Print out a string with char

```c
char hw[15] = "Hello, World!";

LE_INFO("Receive string %s", hw);
```
