``ls /dev/*i2c*``: Check user-mode I2C port

**Example result**: 

```
/dev/i2c-0  /dev/i2c-1  /dev/i2c-2  /dev/i2c-3  /dev/i2c-4
```

## libi2c-dev

``libi2c-dev`` package includes I2C commands like ``i2cdetect``, ``i2cset`` and ``i2cget`` and ``i2c/smbus.h`` C library.

Install

```sh
sudo apt-get install libi2c-dev
```

**i2cdetect**

Detect I2C device in port ``1``:

```bash
$ sudo i2cdetect -y 1
```

``i2cdetect -l``: List all existed I2C bus

**i2cset**: ``-y`` will disable confirmation message. Without ``-y``, there will be message, for example:

```
WARNING! This program can confuse your I2C bus, cause data loss and worse!
I will write to device file /dev/i2c-10, chip address 0x03, data address
0x11, data 0x42, mode byte.
Continue? [Y/n]
```

Set value ``0x42`` to register address ``0x11`` at I2C slave ``0x03`` in I2C bus ``10``

```sh
i2cset -y 10 0x03 0x11 0x42
```

**i2cget**:

Read value at register address ``0x11`` at I2C slave ``0x03``

```sh
sudo i2cget -y 10 0x03 0x11
```
