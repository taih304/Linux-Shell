## hcitool

``hcitool``: configure Bluetooth connections

``hciconfig`` prints name and basic information about all the Bluetooth devices installed in the system.

Same result with ``hciconfig dev``

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

## Bluetooth Low Energy

``sudo hcitool lescan``: Start Bluetooth BLE devices scanning (must run with ``sudo``)

``sudo hcitool lecc 00:81:F9:62:1F:55``: create a LE connection to this BLE device

## HCI command

``hcitool cmd`` is used to send abitary command to HCI.

For list of command and description: 

``Vol 4: Host controller interface`` -> ``HOST CONTROLLER INTERFACE FUNCTIONAL SPECIFICATION`` -> ``7 HCI COMMANDS AND EVENTS``

### Controller & Baseband commands

OGF is defined as 0x03

Plug in Bluetooth USB dongle

``sudo hcitool cmd 0x03 0x03``: HCI_Reset command

The ``HCI_Reset`` command will reset the ``Controller`` and the ``Link Manager`` on the BR/EDR Controller, the PAL on an AMP Controller, or the Link Layer on an LE Controller.

**Result**:

```
< HCI Command: ogf 0x03, ocf 0x0003, plen 0
> HCI Event: 0x0e plen 4
  01 03 0C 00 
```

``0x0E``: Used by controller to send status and event parameters to the host for the particular command.

* plen: packet lengeth
* HCI Event packet: used by the Controller to notify the Host when events occur

The return number in ``HCI Event`` is not useful and the informative information has to be analysed by ``btmon``

```
> HCI Event: 0x0e plen 4
  01 03 0C 00 
```  

### Running with btmon

``btmon``: Bluetooth monitor

In terminal 1: ``sudo hcitool cmd 0x03 0x03``

In terminal 2: ``sudo btmon``

**Result in terminal 2**

```
@ RAW Open: hcitool (privileged) version 2.22       {0x0004} [hci0] 1734.465742
< HCI Command: Reset (0x03|0x0003) plen 0                #57 [hci0] 1734.465824
> HCI Event: Command Complete (0x0e) plen 4              #58 [hci0] 1734.474914
      Reset (0x03|0x0003) ncmd 2
        Status: Success (0x00)
@ RAW Close: hcitool                                {0x0004} [hci0] 1734.475068
```

## Scan 

LE Set Scan Parameters command

| Command | OCF | Command parameters|Return parameters|
| ------- |:------:|:------:|:------:|
|``HCI_LE_Set_Scan_Parameters``|0x000B|``LE_Scan_Type``, ``LE_Scan_Interval``, ``LE_Scan_Window``, ``Own_Address_Type``, ``Scanning_Filter_Policy``|Status|

* ``LE_Scan_Type``: 1 octet (1 byte)
* ``LE_Scan_Interval``: 2 octets (2 byte)
* ``LE_Scan_Window``: 2 octets (2 byte)
* ``Own_Address_Type``: 1 octet
* ``Scanning_Filter_Policy``: 1 octet

```
sudo hcitool cmd 0x08 0x0b 00 00 10 00 10 00 00
```

**Result in btmon**

```
< HCI Command: LE Set Scan Paramet.. (0x08|0x000b) plen 7  #17 [hci0] 71.623098
        Type: Passive (0x00)
        Interval: 2560.000 msec (0x1000)
        Window: 2560.000 msec (0x1000)
        Own address type: Public (0x00)
        Filter policy: Accept all advertisement (0x00)
> HCI Event: Command Complete (0x0e) plen 4                #18 [hci0] 71.623929
      LE Set Scan Parameters (0x08|0x000b) ncmd 1
        Status: Success (0x00)
```

### Analyse the command

**Paramter in hcitool cmd**

Each parameter in ``hcitool cmd`` will take 1 byte for every parameter, for example

``sudo hcitool cmd 0x08 0x0b 00 00 10 00 10 00 00`` will take 1 byte for every ``0x08``, `` 0x0b``, ``00``, ``00``, ``10``, ``00``, ``10``, ``00`` and ``00``.

If a value that is bigger than 1 byte is used, e.g ``0x2019``, only ``0x19`` is received.

So for 2 octets paramter, it has to be: ``00 10`` for ``0x1000``

**Sending multiple byte in hcitool cmd**

Multi-octet fields within the Attribute protocol shall be sent least significant octet
first (little-endian) with the exception of the Attribute Value field. So sending ``00 10`` will be interpreted as ``0x1000``

### For 10 ms scan config

```
sudo hcitool -i hci0 cmd 0x08 0x0b 0x00 0x10 0x00 0x10 0x00 0x00 0x00
```
**Result in btmon**
```
@ RAW Open: hcitool (privileged) version 2.22       {0x0004} [hci0] 3094.827372
< HCI Command: LE Set Scan Param.. (0x08|0x000b) plen 7  #41 [hci0] 3094.827609
        Type: Passive (0x00)
        Interval: 10.000 msec (0x0010)
        Window: 10.000 msec (0x0010)
        Own address type: Public (0x00)
        Filter policy: Accept all advertisement (0x00)
> HCI Event: Command Complete (0x0e) plen 4              #42 [hci0] 3094.828218
      LE Set Scan Parameters (0x08|0x000b) ncmd 1
        Status: Success (0x00)
@ RAW Close: hcitool     
```