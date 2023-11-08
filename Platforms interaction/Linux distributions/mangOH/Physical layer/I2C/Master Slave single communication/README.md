### Feature

mangOH only supports the master side of the I2C bus.

* mangOH as master read data from Arduino as slave: Arduino send increasing number to mangOH
* mangOH as master send data to Arduino as slave: 
    
    mangOH send increasing number to Arduino. As ``i2cSendBytes()`` support unit_8 (8 bit), the sending number will go from 0 to 255.

### Library

```
i2cUtils/
├── Component.cdef
└── i2cUtils.h
└── i2cUtils.c
```

### Main program

``gpioTest.c`` for ``Component.cdef``