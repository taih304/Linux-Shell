Soil moisure sensor ES-SM-TH-01S

## Connection

Connect sensor pins to RS485 to USB converter.

For connection between modules to USB to UART then UART to RS845, connect 2 GND pins between ``A/B`` and ``TX/RX`` side

## Software

### PlatformIO

Enter device monitor with baudrate 9600: ``pio device monitor --port /dev/ttyUSB0 --baud 9600 --echo --encoding hexlify``

Then type command ``01 03 00 12 00 01 24 0F`` for soil moisure query

The result will be like ``01 03 02 00 00 B8 44`` or ``01 03 02 00 2D 78 59`` 

**Other inquiry by reading Holding Registers**: 

Read 1 register, starting from register device with address ``0x0100``: 

Request: ``01 03 01 00 00 01 85 f6`` -> Response: 01 03 02 00 01 79 84

Read 2 register, starting from register device with address ``0x0100``: 

Request: ``01 03 01 00 00 02 c5 f7`` -> Response: 01 03 04 00 01 00 02 2A 32 

Read 1 register, starting from register baud rate address ``0x0100``: 

Request: ``01 03 01 01 00 01 d4 36`` -> Response: ``01 03 02 00 02 39 85``
