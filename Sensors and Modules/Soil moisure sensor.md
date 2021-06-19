Soil moisure sensor ES-SM-TH-01S

## Connection

Connect sensor pins to RS485 to USB converter.

## Software

### PlatformIO

Enter device monitor with baudrate 9600: ``pio device monitor --port /dev/ttyUSB0 --baud 9600 --echo --encoding hexlify``

Then type command ``01 03 00 12 00 01 24 0F`` for soil moisure query

The result will be like ``01 03 02 00 00 B8 44`` or ``01 03 02 00 2D 78 59`` 

