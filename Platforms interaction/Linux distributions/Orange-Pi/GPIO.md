# GPIO

Orange Pi Zero board has 2 on-board LED:
* A red LED, connected to the PA17 pin.
* A green LED, connected to the PL10 pin.

## Control GPIO with sysfs

For controlling with ``/sys/class/gpio/``, check [the corresponding document](https://github.com/TranPhucVinh/Raspberry-Pi-Bash/blob/main/Physical%20layer/GPIO/sysfs.md) in Raspberry Pi Bash as their implementations are identical.

On-board LED are can be accessed from ``/sys/class/leds/``.

```sh
root@orangepizero:~# ls /sys/class/leds/
green_led  red_led
```

Turn on red LED: ``echo 1 > /sys/class/leds/red_led/brightness``

Turn off red LED: ``echo 0 > /sys/class/leds/red_led/brightness``

Turn on green LED: ``echo 1 > /sys/class/leds/green_led/brightness``

Turn off green LED: ``echo 0 > /sys/class/leds/green_led/brightness``

# I2C

2 I2C devices ``/dev/i2c-0`` and ``/dev/i2c-1`` are enabled by default in Orange Pi Armbian.

# SPI

2 SPI devices ``/dev/spidev0.0`` and ``/dev/spidev1.0`` are enabled by default in Orange Pi Armbian