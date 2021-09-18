``bin`` : the directory ``bin`` store all the command line used in Linux

**Recover .bashrc and .profile to origin files**

Origin ``.bashrc`` and ``.profile`` files are stored in ``/etc/skel``

### Linux kernel-related software

``lsmod``: show which loadable kernel modules are currently loaded

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