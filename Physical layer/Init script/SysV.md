SysV uses scripts stored in ``/etc/init.d/``. Processes are started and stopped using symbolic links in ``/etc/rc[0-6].d/``.

# rc.local
File ``/etc/rc.local`` runs when system is booted. It exists in Ubuntu 16.04 and doesn't exist in Ubuntu 20.04 

0rigin file ``/etc/rc.local`` in Ubuntu 16.04

```sh
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.

exit 0
```

Adding a script to that file to run that script from boot time, e.g:

```sh
echo "Hello, World ! from /etc/rc.local"

exit 0
```

To make that script executable after rebooting, change its mode to ``777``: ``sudo chmod 777 /etc/rc.local``

After rebooting the OS, view the log of ``/etc/rc.local`` in ``/var/log/syslog``.
# rcS
``rcS`` stands for Run Control Scripts. It is located in ``/etc/init.d``. ``rcS`` allows you to run additional programs at boot time.

File ``rcS`` is availale in Ubuntu OS 16.04 and [Armbian 3.4.113-sun8i Orange Pi](https://github.com/TranPhucVinh/Orange-Pi), and is not available in Ubuntu 20.04, Raspbian and ubuntu docker.

Original content of ``rcS`` file in Ubuntu 16.04:

```sh
#! /bin/sh
#
# rcS
#
# Call all S??* scripts in /etc/rcS.d/ in numerical/alphabetical order
#

exec /etc/init.d/rc S
```

Adding echo log like this won't print out on ``/var/log/syslog``.

```c
echo "Hello, World !"
exec /etc/init.d/rc S
```
**Mdev** has a config file for controlling ownership/permissions of device nodes if your system needs something more than the default root/root ``660`` permissions. For this, you need to have hotplugging enabled in your kernel.

So a typical code snippet from the ``rcS`` init script will be:
```sh
mount -t proc proc /proc
mount -t sysfs sysfs /sys
echo /sbin/mdev > /proc/sys/kernel/hotplug
mdev -s
```
For the virtual filesystem, like procfs, sysfs, tmpfs, ``none`` can be added to mean that there is no physical disk partition linked to the mount point. The [rcS script in the customized Linux OS run on Raspbian](https://github.com/TranPhucVinh/Raspberry-Pi-GNU/blob/main/Kernel/Customized%20Linux%20distro%20from%20scratch/rootfs.md) has that none value when setting procfs and sysfs.

``mdev -s`` will scan ``/sys`` to create ``/dev``. Base on [its implementation in Busybox](https://coral.googlesource.com/busybox/+/refs/tags/1_18_2/util-linux/mdev.c), ``mdev -s`` scans ``/sys/class/xxx``, looking for directories which have ``dev`` file, e.g ``/sys/class/tty/tty0/dev``. Then ``mdev`` creates the ``/dev/device_name`` node.
# /etc/inittab
/etc/inittab is a configuration file used by the traditional SysV-style init system in Unix-like operating systems to define how the system should set up and manage various processes during startup and while the system is running. 

The file consists of lines with the following format:

```sh
id:runlevels:action:process
```
* **id**: A unique identifier for the entry.
* **runlevels**: Specifies the runlevels at which the entry should be executed.
* **action**: Defines the action to be taken, such as ``respawn``, ``wait``, ``once``, ``sysinit``, etc.
* **process**: The command or script to be executed

**Common Actions**
* respawn: Restarts the process if it terminates.
* wait: Executes the process once when the specified runlevel is entered, then waits until it terminates.
* once: Executes the process once when the specified runlevel is entered.
* sysinit: Executes the process during system initialization.