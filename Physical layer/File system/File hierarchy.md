Root folder ``/`` contains those folder:

* ``home``: User directories
* ``boot``: For booting system
* ``sbin``: System file
* ``bin``:  Commands and programs
* ``usr``: Application files
* ``var``: Variable files
* ``dev``: Device files
* ``etc``: Configuration files
* ``opt``: Optional
* ``tmp`` 

# bin

Directory ``bin`` stores all the command line used in Linux

Example: [Set up command from a C process by using the /bin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).

# etc

``/etc`` (which stands for etcetera due to its history) is a folder where all configuration files are stored.

**Recover .bashrc and .profile to origin files**: Origin ``.bashrc`` and ``.profile`` files are stored in ``/etc/skel``

### User setup

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

### modules

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

### rcS

``rcS`` stands for Run Control Scripts. It is located in ``/etc/init.d``. ``rcS`` allows you to run additional programs at boot time.

File ``rcS`` is availale in Ubuntu OS 16.04 and Armbian 3.4.113-sun8i, and is not available in Ubuntu 20.04, Raspbian and ubuntu docker.

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

# usr

[Set up command from a C process by using the /usr/local/bin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).

# tmp

In Unix and Linux, the global temporary directories are ``/tmp`` and ``/var/tmp`` where temporary files of the running program are stored here. However, files created by user in those locations are not temporary as they are still in there and can still keep the value after the OS is powered off.

# ~/.local

Trash folder are located under ``~/.local/share/Trash``
