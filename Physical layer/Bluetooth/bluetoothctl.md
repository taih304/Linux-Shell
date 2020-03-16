### bluetoothctl

``bluetoothctl``: able to scan all bluetooth information

Then this will enter ``bluetoothctl`` command line mode

``scan on``: start scanning

``connect 00:81:F9:62:1F:55``: Connect to device

### Gatttool

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