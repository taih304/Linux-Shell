# Parameters
* ``-c #``: Number of values to read/write; value: 1-125, 1 is default
* ``-r #``: Start reference (1-65536, 100 is default)

# Read operation
## Read holding register 
Initiate a **Modbus RTU** master/client with 9600 baud, no parity to read 10 holding register starting from register address ``500``at slave/server address ``123`` on ``/dev/ttyUSB0``:
```sh
modpoll -b 9600 -p none -m rtu -a 3 -r 500 -c 10 /dev/ttyUSB0
```
```sh
username@hostname:~$ modpoll -b 9600 -p none -m rtu -a 123 -r 500 -c 10 /dev/ttyUSB0
<Ommit modpoll software version and description>
Protocol configuration: Modbus RTU, FC3
Slave configuration...: address = 123, start reference = 500, count = 10
Communication.........: /dev/ttyUSB0, 9600, 8, 1, none, t/o 1.00 s, poll rate 1000 ms
Data type.............: 16-bit register, output (holding) register table

-- Polling slave... (Ctrl-C to stop)
[500]: 0 # No data on this register yet
[501]: 0
[502]: 0
[503]: 0
[504]: 0
[505]: 0
[506]: 0
[507]: 0
[508]: 0
[509]: 0
-- Polling slave... (Ctrl-C to stop)
[500]: 0
[501]: 0
[502]: 0
[503]: 0
[504]: 0
[505]: 0
[506]: 0
[507]: 0
[508]: 0
[509]: 0
-- Polling slave... (Ctrl-C to stop)
...
```

## Read coil/discrete output
Read 10 coils starting from coil address ``2``
```sh
modpoll -b 9600 -p none -m rtu -a 1 -t 0 -r 2 -c 10 /dev/ttyUSB0
```
Initiate a **Modbus ASCII** master/client to read 10 coils starting from coil address ``2``:
```sh
modpoll -b 9600 -p none -m ascii -a 1 -t 0 -r 2 -c 10 /dev/ttyUSB0
```
**Modbus TCP** master/client reads 10 holding register from modbus TCP slave/server at address 0x01, localhost (127.0.0.1), port 8000
```sh
modpoll -m tcp -a 1 -r 1 -c 10 -p 8000 127.0.0.1
```
# Write operation
Write to 1 holding register starting at address ``500``, at slave/server address ``123`` with Modbus RTU at 9600 baud, no parity on ``/dev/ttyUSB0``:
```sh
username@hostname:~$ modpoll -b 9600 -p none -m rtu -a 123 -r 500 -c 1 /dev/ttyUSB0 123
<Ommit modpoll software version and description>

Protocol configuration: Modbus RTU, FC6
Slave configuration...: address = 123, start reference = 500, count = 1
Communication.........: /dev/ttyUSB0, 9600, 8, 1, none, t/o 1.00 s, poll rate 1000 ms
Data type.............: 16-bit register, output (holding) register table

Written 1 reference.
```
Then read value at that register address to check the write operation:
```sh
username@hostname:~$ modpoll -b 9600 -p none -m rtu -a 123 -r 500 -c 10 /dev/ttyUSB0
Protocol configuration: Modbus RTU, FC6
Slave configuration...: address = 123, start reference = 500, count = 1
Communication.........: /dev/ttyUSB0, 9600, 8, 1, none, t/o 1.00 s, poll rate 1000 ms
Data type.............: 16-bit register, output (holding) register table
-- Polling slave... (Ctrl-C to stop)
[500]: 123
[501]: 0
[502]: 0
[503]: 0
[504]: 0
[505]: 0
[506]: 0
[507]: 0
[508]: 0
[509]: 0
-- Polling slave... (Ctrl-C to stop)
Reply time-out!
....
```
