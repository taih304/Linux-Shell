### Official document

Bluetooth official document can be found on Bluetooth webpage.

Official document: Bluetooth Core Specification

### Acronyms and abbreviations

* ``LAP``: Lower Address Part
* ``OGF``: OpCode Group Field
* ``OCF``: OpCode Command Field
* ``PDU``: Protocol Data Units

### l2ping

``L2CAP``: Logical link control and adaptation protocol

``l2ping``: Send L2CAP echo request and receive answer 

Ping a classicial bluetooth device (must run with ``sudo``)

```bash
$ sudo l2ping 0C:2F:B0:D4:03:D9
```

### hcidump

hcidump has to be installed: ``sudo apt install bluez-hcidump``