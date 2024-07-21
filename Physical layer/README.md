# [Init script](Init%20script)
Init script includes:
* [Systemd](Init%20script/Systemd.md)
* SysV init with [rc.local](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/File%20hierarchy.md#rclocal) and [rcS](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/File%20hierarchy.md#rcs)
* [.netrc](Init%20script/.netrc.md)
* [crontab](crontab)

# [Connectivity](Connectivity)
Connectivity implementation on Linux Shell includes:
* [I2C]()
* [USB]()
* [Bluetooth]()
* [Zigbee]()
* [NFC]()

# Miscellaneous system handler commands

* ``groups``: View the available group in your account, use command:
* ``compgen -g``: See all available groups type: 
* ``uname``: Name of OS
* ``shutdown``
* ``reboot``
* ``cat /etc/os-release``: View OS information

Name of OS:

* ``uname -v``: Name of Kernel version, e.g: ``#82-Ubuntu SMP Fri Sep 4 12:23:10 UTC 2020``
* ``uname -m``: Machine hardware name, e.g ``x86_64``
* ``sudo lshw``: list system hardware information
* ``xinput``: list all available input devices

# Virtual machine
**Virtualization** is a form of resource optimization that allows multiple systems to run on the same hardware. These system are called virtual machines.

Virtual machines recreate a full representation of the hardware. The software layer that enable this representation is called a **hypervisor**.

An **instance** is a **virtual machine** (VM) hosted on Google or AWS's infrastructure.
