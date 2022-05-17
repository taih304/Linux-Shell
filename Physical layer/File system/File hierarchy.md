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

# etc

``/etc`` (which stands for etcetera due to its history) is a folder where all configuration files are stored.

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

### rcS

``rcS`` stands for Run Control Scripts. It is located in ``/etc/init.d``. ``rcS`` allows you to run additional programs at boot time.

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
