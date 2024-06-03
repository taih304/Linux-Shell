# Shell

In computing, a **shell** is a computer program which exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

Whenever we run any command in a Bash shell, a **subshell** is created by default, and a new child process is spawned (forked) to execute the command. 

```bash
username$hostname #One host name can include many user_name
```

To view the available group in your account, use command: ``groups``

To see all available groups type: ``compgen -g``

To change group, use ``chgrp`` command. Change group to ``root`` for all files inside a folder: ``sudo chgrp root folder_name/*``

# [Init script](Init%20script)
Init script includes:
* [Systemd](Init%20script/Systemd.md)
* SysV init with [rc.local](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/File%20hierarchy.md#rclocal) and [rcS](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/File%20hierarchy.md#rcs)
* [.netrc](Init%20script/.netrc.md)
* [crontab](crontab)

# [File system](File%20system)

* [sysfs](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/File%20system#sysfs) and [procfs](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/File%20system#procfs) are filesystems which allow user to monitor system resources.
* File operations: Create, read and write 
* [Storage services](): On-premise storage includes DAS, NAS and SAN
# [Connectivity](Connectivity)
Connectivity implementation on Linux Shell includes:
* [I2C]()
* [USB]()
* [Bluetooth]()
* [Zigbee]()
* [NFC]()

# Miscellaneous system handler commands

Other commands:

* ``shutdown``
* ``reboot``
* ``cat /etc/os-release``: View OS information

Name of OS:

* ``uname``: Name of OS
* ``uname -v``: Name of Kernel version. E.g: ``#82-Ubuntu SMP Fri Sep 4 12:23:10 UTC 2020``
* ``sudo lshw``: list system hardware information
* ``xinput``: list all available input devices
# Virtual memory
User space applications are not allowed to access peripheral registers, storage media or even RAM memory directly. Instead, the hardware is accessed via  kernel drivers, and RAM memory is managed by the memory management unit (MMU), with user space applications operating on **virtual addresses**.

**Virtual memory** is a section of volatile memory created temporarily on the storage drive. It is created when a computer is running many processes at once and RAM is running low.

The OS’s process abstraction provides each process with a virtual memory space so address of a variable inside a process is virtual address.

Because processes operate within their own virtual address spaces, operating systems must make an important distinction between two types of memory addresses.
Virtual addresses refer to storage locations in a process’s virtual address space, and physical addresses refer to storage locations in physical memory (RAM).

Swapping is the process the OS uses to move data between RAM and virtual memory. The OS moves data from processes that are not immediately needed out of the RAM and stores them in virtual memory. It copies the data back into RAM when the process is needed again. Using virtual memory slows the computer down because copying to a hard disk takes much longer than reading and writing RAM.

# Virtual machine
**Virtualization** is a form of resource optimization that allows multiple systems to run on the same hardware. These system are called virtual machines.

Virtual machines recreate a full representation of the hardware. The software layer that enable this representation is called a **hypervisor**.

An **instance** is a **virtual machine** (VM) hosted on Google or AWS's infrastructure.
