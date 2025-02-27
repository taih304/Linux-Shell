# sysfs

``sysfs`` is a pseudo file system (``/sys``) provided by the Linux kernel that exports information about various kernel subsystems, hardware devices, and associated device drivers from the kernel's device model to user space through virtual files.

## Kernel

The ``/sys/class/`` directory offers a view of the device drivers grouped by classes.

``cat /sys/class/thermal/thermal_zone0/temp``: read temperature on Linux

``sys/dev`` stores all block (``block`` directory) and character (``char``) devices.

``sys/dev/char`` has structure: ``major_number:minor_number``. Eg: ``10:1``.

## GPIO

On PC with an OS, as ``ls`` on ``/sys/class/gpio`` only return ``export`` and ``unexport`` (GPIO chip like ``gpiochip0``, ``gpiochip100``, ``gpiochip504``,... are not included) so the virtual GPIO files sytem can't be created.

``echo 1  > export`` has error: ``bash: echo: write error: Invalid argument``

To view virtual GPIO debug information: ``cat /sys/kernel/debug/gpio``

# procfs

``procfs`` is pseudo filesystem (``/proc``) containing information about the system resources, including currently running processes, kernel, hardware. 

For ``/proc`` to monitor process, check [process document folder](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/Process)

For ``/proc`` to monitor device file, ``cat /proc/devices`` will list all character devices and block devices with major number. For file descriptors, check [Device files - file descriptors](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Device%20files/dev.md#file-descriptors).

For ``/proc`` to monitor kernel and hardware:

* ``less /proc/cpuinfo``: View CPU info
* ``cat /proc/interrupts``: List all available interrupts on current running Unix OS
* ``sudo cat /proc/ioports``: Check address of all ports. Must run with ``sudo``. Without ``sudo``, all returned address from this command will be ``0``. ``sudo cat /proc/ioports`` in both [Raspbian](https://github.com/TranPhucVinh/Raspberry-Pi-Bash) and [Armbian](https://github.com/TranPhucVinh/Orange-Pi) will return NULL as they all are empty file.

# tmpfs

**tmpfs** is a temporary file system that resides in memory. It allows you to create a file system in RAM, which means that the data stored in a tmpfs file system exists only in volatile memory and is not persisted across reboots.

The **tmpfs** filesystem is used for managing the [/tmp](File%20hierarchy.md#tmp) directory.

# devpts

``devpts`` is a virtual filesystem contains solely devices files used to implement terminal emulators. It is normally mounted at ``/dev/pts`` and represent slaves to the multiplexing master located at ``/dev/ptmx``.

# FAT and FatFs

A FAT file system is a specific type of computer file system architecture and a family of industry-standard file systems utilizing it.

**FatFs** is a generic FAT/exFAT filesystem module for small embedded systems. The FatFs module is written in compliance with ANSI C (C89) and completely separated from the disk I/O layer. Therefore it is independent of the platform. It can be incorporated into small microcontrollers with limited resource, such as 8051, PIC, AVR, ARM, Z80, RX and etc.

![](../../Environment/Images/FatFs.png)
