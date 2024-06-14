``/etc`` (which stands for **etcetera** due to its history) is a folder where all configuration files are stored.

Scripts run when the device is boot are stored in ``/etc/init``

**Recover .bashrc and .profile to origin files**: Origin ``.bashrc`` and ``.profile`` files are stored in ``/etc/skel``

# User setup

Hostname is stored in ``/etc/hostname``.

All user information is stored in ``/etc/passwd``

``sudo su - user_name``: Login as ``user_name``

``sudo useradd user_name``: Add new user ``user_name`` (this require admin privilege)

``sudo deluser user_name``: Delete ``user_name``

``sudo -sH``: Run as root (enter ``/root`` directory)

* **passwd current_login_username**: Change password of ``current_login_username``
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
# network
```sh
username@hostname:~/$ cat /etc/network/interfaces
# This interface file used by ifup() and ifdown()
auto lo
iface lo inet loopback
```
**auto lo** instructs the system to automatically bring up the **loopback interface** (lo) during the boot process.

**iface lo inet loopback** configures the **loopback interface** (lo) with the inet address family (IPv4) to operate as a loopback device, allowing the system to communicate with itself using the loopback address 127.0.0.1.

If commenting out those 2 lines then rebooting the system, communicating through loopback address 127.0.0.1 is still available, e.g [TCP sender and receiver communication](https://github.com/TranPhucVinh/C/tree/master/Transport%20layer#a-tcp-sender-sends-string-to-a-tcp-receiver). That happens as Ubuntu has another internal mechanism to allow loopback address communication.

# modules

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

# systemd

For systemd implementation in /etc/systemd, check [systemd document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Systemd.md).

# rc.local

File ``/etc/rc.local`` runs when system is booted. Check [rc.local init script document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/README.md#rclocal) for its implementation.

# rcS

``rcS``, which is located in ``/etc/init.d``, stands for Run Control Scripts.  Check [rcS init script document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/README.md#rcs) for its implementation.

# fstab
The ``/etc/fstab`` file (short for **filesystem table**) is a crucial configuration file in Unix-like operating systems, including Linux. The system uses this file to automatically mount filesystems at boot time and manage storage devices.

Structure of /etc/fstab

```sh
<file system>  <mount point>  <type>  <options>  <dump>  <pass>
```
* **file system**: Specifies the device or remote filesystem to mount, such as a disk partition (e.g., /dev/sda1), a UUID, a label, or a network share.
* **mount point**: The directory where the filesystem will be mounted (e.g. ``/``, ``/home``, ``/mnt/data``).
* **type**: The type of filesystem (e.g., ext4, xfs, nfs, swap).
* **options**: Mount options (e.g., defaults, ro, rw, noatime). These options control the behavior of the mounted filesystem.
* **dump**: A field used by the dump utility to determine which filesystems need to be dumped (backed up). Typically set to 0 or 1.
* **pass**: Determines the order in which filesystems are checked by fsck at boot time. 1 indicates the root filesystem, and 2 indicates other filesystems. 0 means the filesystem is not checked.