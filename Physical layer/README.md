# Shell

In computing, a **shell** is a computer program which exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

Whenever we run any command in a Bash shell, a **subshell** is created by default, and a new child process is spawned (forked) to execute the command. 

```bash
username$hostname #One host name can include many user_name
```

To view the available group in your account, use command: ``groups``

To see all available groups type: ``compgen -g``

# Init process

## [Systemd](Systemd.md)

## SysV init with [rc.local](File%20system/File%20hierarchy.md#rclocal) and [rcS](File%20system/File%20hierarchy.md#rcs)

## [.netrc.md](.netrc.md)

## crontab

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

# [File system](File%20system)

[sysfs](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/File%20system#sysfs) and [procfs](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Physical%20layer/File%20system#procfs) are filesystems which allow user to monitor system resources.

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
