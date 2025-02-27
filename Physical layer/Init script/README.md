# [Systemd](Systemd.md)
# [SysV init](SysV.md)
| SysV | Systemd |
| ------- |:------:|
| sudo service docker start   | sudo systemctl start docker   |
| sudo service docker stop     | sudo systemctl stop docker    |
| sudo service docker status     | sudo systemctl status docker    |

# OpenRC

OpenRC is a Linux init systems. It's compatible with SysVinit, can be used as a drop-in replacement. It provides dependency-based service management.

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
