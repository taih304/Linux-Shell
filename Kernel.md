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

# Linux kernel module

## Commands

* ``lsmod``: show which loadable kernel modules are currently loaded
* ``insmod``:  insert loadable kernel module
* ``rmmod``: remove loadable kernel module
* ``modinfo``: view loadable kernel module information

### depmod

``depmod`` will generate ``modules.dep`` and map files for system kernel modules.

``-a``: Probe all modules. This option is enabled by default if no file names are given in the command-line. Any changes (create or remove) with kernel modules in ``/lib/modules/$(uname -r)`` needs running ``sudo depmod -a`` again for latest update in ``modules.dep``.

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
