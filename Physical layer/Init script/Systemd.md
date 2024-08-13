# Fundamental concepts

systemd is a **software suite** that provides an array of system components for **Linux operating systems**. It provides a system and service manager that **runs as PID 1** and **starts the rest of the system**. Other parts include a logging daemon, utilities to control basic system configuration like the hostname, date, locale, maintain a list of logged-in users and running containers and virtual machines, system accounts, runtime directories and settings, and daemons to manage simple network configuration, network time synchronization, log forwarding, and name resolution.

The service setup by systemd will run automatically when the OS is booted/powered on.

systemd unit file locations:
* ``/lib/systemd/system``: Standard systemd unit files
* ``/usr/lib/systemd/system``: Locally installed packages (e.g via ``apt-get``)
* ``/run/systemd/system``: transient unit files
* ``/etc/systemd/system``: Custom unit files

Commands:
* ``systemctl`` is a command to inspect and control the state of the systemd system and service manager
* ``timedatectl``: display the current time, both, the system clock and the hardware clock

**Install systemd**: ``sudo apt install systemd``

Check version: ``systemd --version``

As **systemd runs as PID 1** and **starts the rest of the system**, this command will return **systemd** as the result:
```sh
ps -p 1 -o comm=
```

For **system which doesn't have systemd installed by default like WSL**, if typing its command like ``systemctl``, there will be error:

```
System has not been booted with systemd as init system (PID 1). Can't operate.
Failed to create bus connection: Host is down
```
**WSL** has SysV installed by default instead.
# systemctl

Self start a program with Linux service ``my-startup.service``

Run ``test.sh`` inside ``/home/tranphucvinh/Documents/``:

```sh
#!/bin/bash
echo "Hello, World !"
```

Must have Shebang line for systemctl to run the shell script

``my-startup.service`` must be located inside ``/etc/systemd/system``:

```c
[Unit]
Description=My service

[Service]
ExecStart=/home/tranphucvinh/Documents/test.sh

[Install]
WantedBy=multi-user.target
```

After creating, we have to enable the service: ``sudo systemctl enable my-startup.service``

Run it: ``sudo systemctl start my-startup.service``

View its status, including log: ``sudo systemctl status my-startup.service``

Result:

```
● my-startup.service - My service
   Loaded: loaded (/etc/systemd/system/my-startup.service; enabled; vendor preset: enabled)
   Active: inactive (dead) since Sat 2022-10-08 16:17:43 +07; 5s ago
  Process: 11598 ExecStart=/home/tranphucvinh/Documents/test.sh (code=exited, status=0/SUCCESS)
 Main PID: 11598 (code=exited, status=0/SUCCESS)

Oct 08 16:17:43 tranphucvinh systemd[1]: Started My service.
Oct 08 16:17:43 tranphucvinh test.sh[11598]: Hello, World !
```

``echo`` log from ``test.sh`` will also be printed out on syslog (``/var/log/syslog``) and is marked with ``test.sh`` prefix.

Specify ``test.sh`` in other directory (e.g: ``/home/username/Documents/``) with ``WorkingDirectory``:

```sh
[Service]
ExecStart=/bin/bash test.sh
WorkingDirectory=/home/username/Documents/
```

In ``ExecStart``, ``test.sh`` can only be run by ``/bin/bash``. ``sh test.sh``, ``./test.sh``, ``. test.sh`` and ``source test.sh`` won't work.

**StandardOutput**: ``StandardOutput`` will display the log in ``systemctl status`` by default

``StandardOutput`` by default is set to ``journal``.

To output ``StandardOutput`` log to a file, use ``file``

```
[Unit]
Description=My service

[Service]
ExecStart=/home/username/work-in-progress/test.sh
StandardOutput=file:/home/username/work-in-progress/log.txt

[Install]
WantedBy=multi-user.target
```

With that setting, ``StandardOutput`` log will not display in ``systemctl status``.

To append ``StandardOutput`` log to a file, use ``append``

```
StandardOutput=append:/home/username/work-in-progress/log.txt
```
## Run a.out file

For ``a.out`` file (C process), it can be run with the whole path:

```
[Service]
ExecStart=/home/username/Documents/Gitlab/work-in-progress/a.out
```

``a.out`` can't be run with ``workingdirectory`` like this:

```
[Unit]
Description=My service

[Service]
ExecStart=a.out
WorkingDirectory=/home/username/work-in-progress/

[Install]
WantedBy=multi-user.target
```

To run ``a.out`` without path in ``ExecStart``, it must be embedded in ``test.sh`` 

``test.sh``:

```sh
#!/bin/bash
/home/username/Documents/
```

Then run ``test.sh`` with ``WorkingDirectory`` as usual.
