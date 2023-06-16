Bluetooth is implemented on Linux since Linux Kernel 3.4 and later through **BlueZ 5.0**. **BlueZ** is a Bluetooth stack for Linux kernel-based family of operating systems. Its goal is to program an implementation of the Bluetooth wireless standards specifications for Linux.

Bluetooth official document, **Bluetooth Core Specification**, can be found on Bluetooth webpage.

# Acronyms and abbreviations

* ``LAP``: Lower Address Part
* ``OGF``: OpCode Group Field
* ``OCF``: OpCode Command Field
* ``PDU``: Protocol Data Units

## l2ping

``L2CAP``: Logical link control and adaptation protocol

``l2ping``: Send L2CAP echo request and receive answer 

Ping a classicial bluetooth device (must run with ``sudo``)

```bash
$ sudo l2ping 0C:2F:B0:D4:03:D9
```

## hcidump

hcidump has to be installed: ``sudo apt install bluez-hcidump``

## bluetoothctl

``bluetoothctl``: able to scan all bluetooth information

Then this will enter ``bluetoothctl`` command line mode

``scan on``: start scanning

``connect 00:81:F9:62:1F:55``: Connect to device

## gatttool

We can discover, read, and write characteristics with gatttool. GATT stands for Generic Attribute and defines a data structure for organizing characteristics and attributes. Launch gatttool in interactive mode.

``gatttool -I``: Enter interactive mode

``characteristics``: List all workable characteristic (no human description). Human readable description has to be achieved with ``bluetoothctl``.

Read value specified by UUID: ``char-read-uuid 00001805-494c-4f47-4943-544543480000``

Write value in writable characteristic: 

```sh
[00:81:F9:62:1F:55][LE]>char-write-req 0x0022 value_to_write #Characteristic Value Write (Write Request)
[00:81:F9:62:1F:55][LE]>char-write-cmd 0x0022 value_to_write #Characteristic Value Write (No response)
```

``0x0022``: char value handle

**Example**

Received data from ESP32 BLE notify

ESP32 code: ``BLE_notify.cpp`` in ``ESP32-Arduino-framework/Physical layer/Bluetooth Low Energy``

Linux shell: Read data from uuid ``beb5483e-36e1-4688-b7f5-ea07361b26a8`` of MAC ``30:ae:a4:02:9c:6e``

```sh
gatttool -I
```
```sh
connect 30:ae:a4:02:9c:6e
```
```sh
char-read-uuid beb5483e-36e1-4688-b7f5-ea07361b26a8
```