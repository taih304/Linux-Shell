``sudo lshw``: list hardware

``passwd username``: Change password

``du -h``: list out disk usage in MB

``df -h``: list size of hardware, and usage of percentage

``xrandr --size 1366x768``: Change size of current screen to ``1366x768``

### Error: ``sudo: unable to resolve host user_name``

This error might happen as the devicename is changed

* ``sudo nano /etc/hosts``
* Then add ``127.0.0.1	user_name`` below the existed hosts

### netstat

``netstat -tulpn``: Find out which process is listening upon a port

### Cannot open /dev/ttyUSB0: Permission denied

```shell
sudo chmod -R 777 /dev/ttyUSB0
```

``df -i``: list all inode

### Error IUSE 100% in ``CentOS``

If error happen, CentOS will not allow user to ``yum install`` more file.

fix: ``sudo rm -rf /var/cache/*``

### Program run at specific time

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

