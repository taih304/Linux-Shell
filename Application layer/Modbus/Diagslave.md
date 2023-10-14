# Parameters
* ``-m rtu``: Modbus RTU protocol
* ``-a #``: Slave address (1-255 for RTU/ASCII, 0-255 for TCP)

# Initiate a Modbus RTU slave/server
Initiate a Modbus RTU slave/server with address ``123``:
```sh
diagslave -b 9600 -p none -m rtu -a 123 /dev/ttyUSB0
```
# Initiate a Modbus ASCII slave/server
```sh
diagslave -b 115200 -p none -m ascii -a 1 /dev/ttyUSB0
```
# Initiate a Modbus TCP slave/server
Initiate a Modbus TCP slave/server with address ``1`` at localhost port 8000
```sh
diagslave -m tcp -p 8000 -a 1
```
