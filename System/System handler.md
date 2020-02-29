```bash
user_name$hostname #One host name can include many usaer_name
```

``Ctrl+Alt+F1``: enter textmode

``Ctrl+Alt+F7``: switch back to desktop

* ``date``: show current date

### Hardware handler

**Port**: 16-bit port means computer can open up to 65536 port.

**Hardware command**

* ``sudo lshw``: list hardware
* ``du -h``: list out disk usage in MB
* ``df -h``: list size of hardware, and usage of percentage
* ``cat /sys/class/thermal/thermal_zone0/temp``: read temperature on Linux
* ``df -i``: list all inode

**Issue**: Cannot open /dev/ttyUSB0: Permission denied

```bash
$ sudo chmod -R 777 /dev/ttyUSB0
```

### User setup

All user information is stored in ``/etc/passwd``

``passwd current_login_username``: Change password of current logged in username

``sudo useradd user_name``: Add new user ``user_name`` (this require admin privilege)

``sudo deluser user_name``: Delete ``user_name``

* ``who``: show how many user has log in the system
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

### GUI setup

``xrandr --size 1366x768``: Change size of current screen to ``1366x768``

### netstat

``netstat -tulpn``: Find out which process is listening upon a port

### Error IUSE 100% in ``CentOS``

If error happen, CentOS will not allow user to ``yum install`` more file.

fix: ``sudo rm -rf /var/cache/*``

### System handler

* ``shutdown``
* ``cat /etc/os-release``: View OS information

**Program run at specific time**

To let a program run in a specific time or when just start up

``sudo crontab -e``

**Example**

```shell
		#                    m     h     dom    mon     dow     command
(every 5 minutes)       */5					                      /bin/bash  /home/....(path to shell program)									
(every 10 minutes)      */10
run when start up	       @reboot
```

**Example**

Make program ``blink.sh`` run when computer reboot

```
# For example, you can run a backup of all your user accounts
# at 5 a.m every week with:
# 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
#
# For more information see the manual pages of crontab(5) and cron(8)
#
# m h  dom mon dow   command
@reboot /bin/bash /home/pi/test/blink.sh  #1 space after /bin/bash
```

``/bin/bash`` is for bash shell

* ``m``: minute
* ``h``: hour
* ``dom``: day of month
* ``dow``: day of week
