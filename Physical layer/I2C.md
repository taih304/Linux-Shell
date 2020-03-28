``ls /dev/*i2c*``: Check user-mode I2C port

**Example result**: 

```
/dev/i2c-0  /dev/i2c-1  /dev/i2c-2  /dev/i2c-3  /dev/i2c-4
```

Detect I2C device's address in a specific port

```bash
$ sudo i2cdetect -y 1
```