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

## Linux embedded

Main components of a Linux embedded system: 

* **Bootloader**
* **Kernel**
* **System call interface**
* **C-Runtime library**
* **System shared libraries** 
* **Root filesystem**
