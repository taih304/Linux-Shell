# Fundamental concepts

The Linux kernel is the lowest level of software running on a Linux system. It is charged with managing the hardware, running user programs, and maintaining the overall security and integrity of the whole system.

### Linux bootloader

Linux bootloader is a small amount of machine specific code to initialize the system. Its duty is to:

* Configuration of the memory system.
* Loading of the kernel image and the device tree at the correct addresses.
* Optional loading of an initial RAM disk at the correct memory address.
* Setting of the kernel command-line and other parameters (e.g, device tree, machine type)

**U-Boot** is the standard bootloader for ARM Linux.

# Implementations

``bin`` : the directory ``bin`` store all the command line used in Linux

``tmp``: In Unix and Linux, the global temporary directories are ``/tmp`` and ``/var/tmp`` where temporary files of the running program are stored here. However, files created by user in those locations are not temporary as they are still in there and can still keep the value after the OS is powered off.

**Recover .bashrc and .profile to origin files**

Origin ``.bashrc`` and ``.profile`` files are stored in ``/etc/skel``

### Linux kernel-related software

* ``lsmod``: show which loadable kernel modules are currently loaded
* ``insmod``:  insert loadable kernel module
* ``rmmod``: remove loadable kernel module
* ``modinfo``: view loadable kernel module information

## Build the Linux Kernel by the cross compile method on Ubuntu 16.04

If cloning the ``linux`` repository in other folder, not in ``~``, use ``$PWD``:

```sh
export PATH=$PWD/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin:$PATH
export TOOLCHAIN=$PWD/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/
export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm
```
**Error**

When cloning branch ``rpi-5.10.y`` or ``rpi-4.9.y``, there will be error: ``rfkill not exist``.

Then Raspberry can't connect to WiFi.

**Reference**: For all steps to build the Linux kernel, check ``Building the Linux Kernel`` on page 51 of book ``Linux Driver Development for Embedded Processors, 2nd Edition``.
