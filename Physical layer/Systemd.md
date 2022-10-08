## Fundamental concepts

For system not supporting ``systemd`` like WSL, if typing its command like ``systemctl``, there will be error:

```
System has not been booted with systemd as init system (PID 1). Can't operate.
Failed to create bus connection: Host is down
```

Commands:
* ``systemctl`` is a command to inspect and control the state of the systemd system and service manager
* ``timedatectl``: display the current time, both, the system clock and the hardware clock

## systemctl

Self start a program with Linux service ``my-startup.service``

Run ``test.sh`` inside ``/home/tranphucvinh/Documents/``:

```sh
#!/bin/bash
echo "Hello, World !"
```

Must have Shebang line for systemctl to run the shell script

``my-startup.service`` must located inside ``/etc/systemd/system``:

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
