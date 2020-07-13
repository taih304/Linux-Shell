### gatttool

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