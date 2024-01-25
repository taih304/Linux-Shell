# About

Board: Orange Pi Zero

# Main development boards

Orange Pi Zero with SoC is H2Quad-coreCortex-A7H.265/HEVC4K (belong to ``Allwinner H2+`` family)

After [installing](Install.md) the Armbian image to the SD card, only 1 partition rootfs is available which takes up the whole memory of the SD card.

# arm-linux-gnueabihf-gcc

Compiler arm-linux-gnueabihf-gcc is available on Armbian: ``arm-linux-gnueabihf-gcc test.c``. ``a.out`` file will then be the output.

# Kernel

``ls /lib/modules``: ``3.4.113-sun8i``

By default on ``3.4.113-sun8i``, there is no Makefile to build the kernel.

Device tree of Armbian can't be read as folder ``/sys/firmware/`` is empty

## config file for KConfig in Armbian Orange Pi Zero board

``config.gz`` file, which includes ``CONFIG_*`` flags, is available by default in ``/proc`` in Armbian Orange Pi Zero board.

``CONFIG_*`` flags of ``config`` file (``gunzip`` from ``config.gz``) will be like:
```
#
# Automatically generated file; DO NOT EDIT.
# Linux/arm 3.4.113 Kernel Configuration
#
CONFIG_ARM=y
CONFIG_ARM_HAS_SG_CHAIN=y
CONFIG_SYS_SUPPORTS_APM_EMULATION=y
CONFIG_GENERIC_GPIO=y
...
```
