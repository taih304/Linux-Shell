Master read data from slave by using malloc

### Send increasing number

**Slave**

```c
Wire.begin(0x30);
Wire.onRequest(sendNumber);

void sendNumber()
{
    Wire.write(count);
    count++;
}
```

**Master**

```c
#define SLAVE_I2C_ADDR 0x30 //I2C address of module
static const char *slave_i2c_bus = "/dev/i2c-4";
static uint8_t *buf;

static void readFromI2CSlave
(
    le_timer_Ref_t timerRef
)
{   
    buf = (uint8_t *) malloc(1);
    i2cReceiveBytes(slave_i2c_bus, SLAVE_I2C_ADDR, buf, sizeof(buf));
    LE_INFO("Received number: %d", buf[0]);
}
```

**Result**: Print out from 0 to 255

### Send string

**Slave**

```c
Wire.begin(0x30);
Wire.onRequest(sendNumber);

void sendNumber()
{
	Wire.write("Hello World");
}
```

**Master**

```c
#define SLAVE_I2C_ADDR 0x30 //I2C address of module
static const char *slave_i2c_bus = "/dev/i2c-4";
static uint8_t *buf;

static void readFromI2CSlave
(
    le_timer_Ref_t timerRef
)
{   
    buf = ((uint8_t *) malloc(11));
    i2cReceiveBytes(slave_i2c_bus, SLAVE_I2C_ADDR, buf, 11);
    LE_INFO("Received number: %s", buf);
}
```

**Result**

Print out Hello World follow with garbage value

```
 Hello World�^Q
 Hello World�^Q
 Hello WorldA^Q
 Hello World1^Q
 Hello World!^Q
 Hello World^Q^Q
 Hello World^A^Q
```

To clear all garbage value, add ``free(buf);``

```c
static void readFromI2CSlave
(
    le_timer_Ref_t timerRef
)
{   
    buf = ((uint8_t *) malloc(11));
    i2cReceiveBytes(slave_i2c_bus, SLAVE_I2C_ADDR, buf, 11);
    LE_INFO("Received number: %s", buf);
    free(buf);
}
```

### i2cReceiveBytes_v2()

``static inline int i2cReceiveBytes_v2(const char * i2c_bus, __u8 address, __u8 cmd, __u8 *data, __u8 len)``

Read received data from slave

```c
static void readFromI2CSlave
(
    le_timer_Ref_t timerRef
)
{   
    buf = ((uint8_t *) malloc(14));
    i2cReceiveBytes_v2(slave_i2c_bus, SLAVE_I2C_ADDR, SLAVE_I2C_ADDR, buf, 14);
    LE_INFO("Received with v_2: %s", buf);
    free(buf);
}
```