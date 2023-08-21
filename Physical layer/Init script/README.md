# [Systemd](Systemd.md)
# SysV init 
## rc.local
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
## rcS
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
# [.netrc](.netrc.md)
# crontab

``crontab`` command is used to setup a program to run in a specific time or when just start up. ``crontab`` is not available in default [ubuntu docker](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Docker/ubuntu%20docker.md).

Command: ``sudo crontab -e``

**Example**

Make program ``test.sh`` run when computer reboot

```
# For example, you can run a backup of all your user accounts
# at 5 a.m every week with:
# 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
#
# For more information see the manual pages of crontab(5) and cron(8)
#
# m h  dom mon dow   command
@reboot /bin/bash /home/username/test/test.sh  #1 space after /bin/bash
```

``/bin/bash`` is for bash shell

* ``m``: minute
* ``h``: hour
* ``dom``: day of month
* ``dow``: day of week

To make ``test.sh`` to run every 1 minute

```sh
* * * * * /bin/bash /home/username/work-in-progress/test.sh
```

Check the example in [Raspberry-Pi-Bash to run a.out which blink LED every 1 second by direct memory access to run every 1 minute](https://github.com/TranPhucVinh/Raspberry-Pi-Bash/blob/main/Physical%20layer/README.md#crontab).

**Note**: If ``test.sh`` includes ``echo`` like this

```sh
#!/bin/bash
echo "Hello, World !"
```

And ``/var/mail`` is empty, then there will be error:

```
CRON[3134]: (CRON) info (No MTA installed, discarding output)
CRON[3139]: (root) CMD (/bin/bash /home/username/work-in-progress/test.sh
```

By default, the output of each cron job is collected by cron and sent via email when the job is complete. If there is no output, no mail is sent. That error mean that there is output from your cron job but your server does not have a **Message Transfer Agent** (MTA) installed (located in ``/var/mail``) to process the output into an email.

The same issue happen if running the ``a.out`` file from crontab which includes ``printf()``.

To avoid that MTD issue, output log to a file with absolute path:

```sh
#!/bin/bash
echo "Hello, World !" > /home/username/work-in-progress/log.txt
```

Absolute path must be used as cron jobs run in their own shell so without absolute path, they don't know where to log the ``echo`` output to.
