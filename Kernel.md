# Fundamental concepts

The Linux kernel is the lowest level of software running on a Linux system. It is charged with managing the hardware, running user programs, and maintaining the overall security and integrity of the whole system.

## Linux bootloader

Linux bootloader is a small amount of machine specific code to initialize the system. Its duty is to:

* Configuration of the memory system.
* Loading of the kernel image and the device tree at the correct addresses.
* Optional loading of an initial RAM disk at the correct memory address.
* Setting of the kernel command-line and other parameters (e.g, device tree, machine type)

**U-Boot** (fullname Das U-Boot) is the boot loader used in embedded devices to package the instructions to boot the device's operating system kernel. It is available for various computer architectures, like ARM, RISC-V, x86,...

**U-Boot** is the standard bootloader for ARM Linux.

## Linux booting process

Linux booting process will follow those steps:

1. The boot process begins at POR (Power On Reset) where the hardware reset logic forces the ARM core to begin execution starting from the on-chip boot ROM. The boot ROM can support several devices (e.g, NOR flash, NAND Flash, SD/eMMC). 

2. The U-Boot loads both the kernel image and the compiled device tree binary into RAM (like DDR3 RAM) and passes the memory address of the device tree binary into the kernel as part of the launch.

3. The U-Boot jumps to the kernel code.

4. Kernel runs low level kernel initialization, enabling MMU and creating the initial table of memory pages, and setting up caches. This is done in ``arch/arm/kernel/head.S``. The file ``head.S`` contains CPU architecture specific but platform independent initialization code. Then the system switches to the non architecture specific kernel startup function ``start_kernel()``.

5. Kernel runs ``start_kernel()`` located in ``init/main.c`` that:

* Initializes the kernel core (e.g., memory, scheduling, interrupts,...). 
* Initializes statically compiled drivers.
* Mounts the root filesystem based on bootargs passed to the kernel from U-Boot.
* Executes the first user process, init. The three init programs that you usually find in Linux embedded devices are BusyBox init, System V init, and systemd.

State machine for those 5 steps

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/booting_process.png)

OS source file are stored in the storage media (SD card, NAND flash,...) and is loaded into RAM when running.

6 steps detail:

* [BIOS](#BIOS): System startup/Hardware init
* Bootloader stage 1: [Master Boot Record (MBR)](#MBR) executes GRUB
* Bootloader stage 2: [GRUB](#GRUB) executes Kernel
* [Kernel](#Kernel) will executes process init located in ``/sbin/init``
* Execute ``init`` process
* Run level: Start userspace for command line

### BIOS

BIOS (Basic Input/Output System) will perform some system integrity checks, then search, load, and executes the boot loader program.

When setting up the PC, you can press a key (typically F12 of F2, but it depends on your system) during the BIOS startup to change the boot sequence.

Once the boot loader program is detected and loaded into the memory, BIOS gives the control to it.

### MBR

MBR is located in the 1st sector of the bootable disk, typically in ``/dev/sda``. MBR contains information about GRUB 

### GRUB

* GRUB stands for Grand Unified Bootloader. If you have multiple kernel images installed on your system, you can choose which one to be executed.
* GRUB displays a splash screen, waits for few seconds, if you don’t enter anything, it loads the default kernel image as specified in the grub configuration file.
* GRUB has the knowledge of the filesystem.
* GRUB configuration file is ``/boot/grub/grub.cfg``. In Ubuntu 20.04 ``grub.cfg`` file, it contains ``initrd`` (Initial RAM Disk) image (checked by searching ``initrd`` in that file). ``initrd`` is used by kernel as temporary root file system until kernel is booted and the real root file system is mounted. It also contains necessary drivers compiled inside, which helps it to access the hard drive partitions, and other hardware.

### Kernel

* Kernel mount the root file system as specified in ``grub.cfg``.
* Kernel executes the ``/sbin/init`` program. Since init was the 1st program to be executed by Linux Kernel, it has the process id (PID) of 1. 

**Command**

* ``sudo init 6``: Reboot the OS

# Linux kernel module

## Fundamental concepts

For kernel driver/device driver definition, check [Device drivers document](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/Device%20files#device-drivers).

Kernel driver is implemented by C source code. Check [loadable kernel module document in C for kernel driver implementation](https://github.com/TranPhucVinh/C/tree/master/Kernel).

The ``/dev/kmsg`` character device node provides userspace access to the kernel's ``printk`` buffer.

## Commands

* ``lsmod``: show which loadable kernel modules are currently loaded
* ``insmod``:  insert loadable kernel module
* ``rmmod``: remove loadable kernel module
* ``modinfo``: view loadable kernel module information

### depmod

``depmod`` will generate ``modules.dep`` and map files for system kernel modules.

``-a``: Probe all modules. This option is enabled by default if no file names are given in the command-line. Any changes (create or remove) with kernel modules in ``/lib/modules/$(uname -r)`` needs running ``sudo depmod -a`` again for latest update in ``modules.dep``.

``depmod`` is used to setup for [modprobe](#modprobe) (to ``insmod``/``rmmod`` kernel modules) and to load a module at boot time (with [/etc/modules](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/File%20hierarchy.md#modules) or ``/etc/modules-load.d/modules.conf``).

### modprobe

To load/unload (remove) a module with modprobe

**Precondition**: ``ubuntu_kernel_module.ko`` located in directory ``~/username/module``:

**Step 1**: Copy ``ubuntu_kernel_module.ko`` to ``/lib/modules/$(uname -r)``

```sh
username$hostname:~/username/module$ sudo cp ubuntu_kernel_module.ko /lib/modules/$(uname -r)
```

**Step 2**: Run ``depmod -a`` to update ``modules.dep`` file

```sh
username$hostname:~/username/module$ depmod -a
```

**Step 3**: 

Load/insmod that module

```sh
username$hostname:~/username/module$ sudo modprobe ubuntu_kernel_module
```

Unload/rmmod that module:

```sh
username$hostname:~/username/module$ sudo modprobe -r ubuntu_kernel_module
```

To revert the system kernel modules setup back to the original, remove ``ubuntu_kernel_module.ko`` in ``/lib/modules/$(uname -r)``, then run ``depmod -a`` again.
