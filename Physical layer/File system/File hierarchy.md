Root folder ``/`` contains those folder:

* ``home``: User directories
* ``boot``: For booting system
* ``sbin``: System file
* [bin](#bin):  Commands and programs
* [usr](#usr): Application files
* [var](#var): Variable files
* [dev](#dev)
* [etc](#etc): Configuration files
* ``opt``: Optional
* [tmp](#tmp)

# bin

Directory ``bin`` stores all the command line used in Linux

Example: [Set up command from a C process by using the /bin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).

# var

``sudo cat /var/log/syslog``: View all system log, like ``crontab``, ``systemctl``
# dev
``/dev`` is the location of special or device files. Check [/dev document](dev.md)
# etc

``/etc`` (which stands for **etcetera** due to its history) is a folder where all configuration files are stored.

Scripts run when the device is boot are stored in ``/etc/init``

**Recover .bashrc and .profile to origin files**: Origin ``.bashrc`` and ``.profile`` files are stored in ``/etc/skel``

## User setup

All user information is stored in ``/etc/passwd``

``sudo useradd user_name``: Add new user ``user_name`` (this require admin privilege)

``sudo deluser user_name``: Delete ``user_name``

``sudo -sH``: Run as root (enter ``/root`` directory)

* ``passwd current_login_username``: Change password of current logged in username, e.g ``passwd username`` where ``username`` is the current logged in username.
* ``who``: show how many user has logged in the system
* ``hostname``

**Issue**: ``User is not in the sudoers file. This incident will be reported.``

```bash
$ sudo nano /etc/sudoers
```

Go to ``#User privilege specification``, then add 

```
new_user_name ALL=(ALL:ALL) ALL
```

**Issue**: ``sudo: unable to resolve host user_name``

This error might happen as the devicename is changed

* ``sudo nano /etc/hosts``
* Then add ``127.0.0.1	user_name`` below the existed hosts

``sudo nano /etc/hosts`` will also help you change the hostname
## network
```sh
username@hostname:~/$ cat /etc/network/interfaces
# This interface file used by ifup() and ifdown()
auto lo
iface lo inet loopback
```
**auto lo** instructs the system to automatically bring up the **loopback interface** (lo) during the boot process.

**iface lo inet loopback** configures the **loopback interface** (lo) with the inet address family (IPv4) to operate as a loopback device, allowing the system to communicate with itself using the loopback address 127.0.0.1.

If commenting out those 2 lines then rebooting the system, communicating through loopback address 127.0.0.1 is still available, e.g [TCP sender and receiver communication](https://github.com/TranPhucVinh/C/tree/master/Transport%20layer#a-tcp-sender-sends-string-to-a-tcp-receiver). That happens as Ubuntu has another internal mechanism to allow loopback address communication.

## modules

``/etc/modules`` file is used for kernel modules to load at boot time.

To load kernel module at boot time:

**Step 1**: Add the kernel module, e.g ``ubuntu_kernel_module.ko``, to ``/lib/modules/$(uname -r)``, then run ``depmod -a``

**Step 2**: Update file ``/etc/modules`` with that kernel modules:

```sh
# /etc/modules: kernel modules to load at boot time.
#
# This file contains the names of kernel modules that should be loaded
# at boot time, one per line. Lines beginning with "#" are ignored.
#
ubuntu_kernel_module
```

From now, kernel module ``ubuntu_kernel_module`` will load at boot time.

``/etc/modules-load.d/modules.conf`` file is the symbolic link of ``/etc/modules``. Performing the same setup on ``/etc/modules-load.d/modules.conf`` with ``/etc/modules`` will allow a kernel module to load at boot time.

## systemd

For systemd implementation in /etc/systemd, check [systemd document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Systemd.md).

## rc.local

File ``/etc/rc.local`` runs when system is booted. Check [rc.local init script document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/README.md#rclocal) for its implementation.

## rcS

``rcS``, which is located in ``/etc/init.d``, stands for Run Control Scripts.  Check [rcS init script document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/README.md#rcs) for its implementation.

# usr

* ``/usr/local/bin`` and ``/usr/sbin``: [Set up command from a C process by using the /usr/local/bin or /usr/sbin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).
* ``/usr/lib``: Store program libraries. Example: [Shared library (.so file)](https://github.com/TranPhucVinh/C/blob/master/Environment/Shared%20library.md)

# tmp

In Unix and Linux, the global temporary directories are ``/tmp`` and ``/var/tmp`` where temporary files of the running program are stored here. However, files created by user in those locations are not temporary as they are still in there and can still keep the value after the OS is powered off.

# ~/.local

Trash folder are located under ``~/.local/share/Trash``
