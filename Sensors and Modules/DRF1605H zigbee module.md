DRF1605H Zigbee module is able to communicate with other MCU by UART with 3.3V logic level. So it is able to communicate and configured with computer when connected by CP2102.

### Connection

| DRF1605H | CP2102 |
| ------- |:------:|
| 3.3V   | 3.3V    |
| GND     | GND    |
| TX (5 J2)  | RX   |
| RX (4 J2)      | TX   |

DRF1605H works normally with PlatformIO by reading its data from Serial port.

### Working with Serial frame on GTKTerm

Notice that serial frame must be enter with space like ``FC 02``.

Go to ``View`` -> ``Hexadecimal``. Then choose ``Send hexadecimal data``.

Set up Port: ``Configuration`` -> Choose connected port, then choose 8 bits data, baudrate ``38400`` (default). Other remain value like parity, stop-bit can be set to any other value.

Set address ``56 78``: ``FC 02 91 01 56 78 5E``. If entering this command for the first time, it will return ``56 78``. If keep entering this command for the next time, other hex string will be returned.

Setting address action require you to restart the board, so restart the board. Then:

``FC 00 91 03 A3 B3 E6``: Read PAN ID

It will return the ID that has just been set, as ``56 78``.

Sending a serial frame ``FC 00 91 08 A8 B8 F5`` will be count as sending 7 bytes.

``FC`` is stored in 1 byte (8 bit) as evey 1 hex character is stored in 4 bit.

**Other frame**

``FC 00 91 08 A8 B8 F5``: Return MAC address

### Set up baudrate

Set baudrate 38400: ``FC 01 91 06 03 F6 8D``. This will return on screen: ``00 03 08 04 00 00``

``FC 00 91 07 97 A7 D2``: Test UART baudrate

### Issue with Serial Monitor and Putty

Current Serial monitor of Arduino IDE and Putty are not well supported for hex data sending and receving, so using those tool to config Zigbee DRF1605H will not work.
