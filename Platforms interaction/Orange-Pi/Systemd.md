# Start a script/process to blink on-board red LED

**Step 1**

In ``/root``, create ``test.sh`` file to blink on-board red LED

```sh
#!/bin/bash
while [ true ]
do
    echo 1 > /sys/class/leds/red_led/brightness
    sleep 1
    echo 0 > /sys/class/leds/red_led/brightness
    sleep 1
done
```

**Step 2**

Create ``my-startup.service`` inside ``/etc/systemd/system``:

```sh
[Unit]
Description=My service

[Service]
ExecStart=/root/test.sh

[Install]
WantedBy=multi-user.target
```

**Step 3**

Enable the service: ``sudo systemctl enable my-startup.service``

Run it: ``sudo systemctl start my-startup.service``

With that setup, service ``my-startup.service`` will then run everytime when the board is powered on, i.e on-board red LED will blink everytime the board is powered on
