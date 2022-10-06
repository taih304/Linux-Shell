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

Self start a program with Linux service

Run ``test.sh`` inside ``/usr/local/sbin``:

```sh
#!/bin/bash
echo "Hello, World !"
```

Must have Shebang line for systemctl to run the shell script

``my-startup.service``

```c
[Unit]
Description=My service

[Service]
ExecStart=/usr/local/sbin/test.sh

[Install]
WantedBy=multi-user.target
```

After creating, we have to enable the service: ``sudo systemctl enable my-startup.service``

Run it: ``sudo systemctl start my-startup.service``

View its status, including log: ``sudo systemctl status my-startup.service``