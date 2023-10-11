# Installation
## Modpoll Modbus Master Simulator

Modpoll Modbus Master Simulator is a CLI tool to create/simulate a Modbus master/client for Modbus communication with Modbus slave/server, e.g reading slave coils,...

Download modpoll-3.10.tgz file from the [official Modpoll Modbus Master Simulator webpage](https://www.modbusdriver.com/modpoll.html)

Then extract ``tar -xf modpoll-3.10.tgz``.

Inside the extracted folder ``modpoll``, ``x86_64-linux-gnu`` has ``modpoll`` command for the Linux environment. Same for other Embedded Linux environment with ``arm-linux-gnueabihf``,...

Then move the extracted folder ``modpoll`` to any suitable location, e.g inside ``~/``, for the later step to setup the alias.

Set up alias so that command ``modpoll`` is available. Add this line of code to ``bashrc``:
```sh
alias modpoll='~/modpoll/x86_64-linux-gnu/modpoll' #When modpoll folder is inside ~/
```
Then command ``modpoll`` is available.

## Diagslave Modbus Slave Simulator

Download diagslave-3.4.tgz file from the [official Diagslave Modbus Slave Simulator webpage](https://www.modbusdriver.com/diagslave.html)

Then extract ``tar -xf diagslave-3.4.tgz``.

Inside the extracted folder ``diagslave``, ``x86_64-linux-gnu`` has ``diagslave`` command for the Linux environment. Same for other Embedded Linux environment with ``arm-linux-gnueabihf``,...

Then move the extracted folder ``diagslave`` to any suitable location, e.g inside ``~/``, for the later step to setup the alias.

Set up alias so that command ``diagslave`` is available. Add this line of code to ``bashrc``:
```sh
alias diagslave='~/diagslave/x86_64-linux-gnu/diagslave' #When diagslave folder is inside ~/
```
Then command ``diagslave`` is available.

## Modbus RTU: Hardware setup for Modpoll and Diagslave communication

For both simulated Modbus master (Modpoll) and Modbus slave (Diagslave) communicate via **Modbus RTU**, a hardware USB-UART converter, e.g CP2102 is required. RX and TX pins of this module **must be connected to each other** so that the Modbus master and slave can transmit and receive data.
# Implementations
