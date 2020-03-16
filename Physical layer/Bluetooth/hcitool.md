### hcitool

``hcitool``: configure Bluetooth connections

``hciconfig`` prints name and basic information about all the Bluetooth devices installed in the system.

Same result with ``hciconfig dev`

```bash
$ hciconfig
$ hciconfig dev #same result
```

```
hci0:	Type: Primary  Bus: USB
	BD Address: F4:96:34:7C:59:4C  ACL MTU: 1021:4  SCO MTU: 96:6
	UP RUNNING PSCAN ISCAN 
	RX bytes:1913 acl:0 sco:0 events:245 errors:0
	TX bytes:46663 acl:0 sco:0 commands:245 errors:0
```

``hcitool scan on``: Scan classical bluetooth devices

``hcitool rssi MAC_address``: Get the RSSI of a connected classical Bluetooth device (doesn't work with BLE devices)

### l2ping

``L2CAP``: Logical link control and adaptation protocol

``l2ping``: Send L2CAP echo request and receive answer 

Ping a classicial bluetooth device (must run with ``sudo``)

```bash
$ sudo l2ping 0C:2F:B0:D4:03:D9
```

### Bluetooth Low Energy

``sudo hcitool lescan``: Start Bluetooth BLE devices scanning (must run with ``sudo``)

``sudo hcitool lecc 00:81:F9:62:1F:55``: create a LE connection to this BLE device

Developer can't do any other things after this.