# Repository overview
Documents in this repository is organized based on the Internet protocol stack which consists of five layers: [physical](Physical%20layer), [link](Link%20layer), [network](Network%20layer), transport, and [application layers](Application%20layer).

**Repository working environment**: Document and source code in this project are implemented mainly in Ubuntu 16.04. Some specific steps are implmented in Ubuntu 20.04

# Ubuntu 16.04 unresolvable issues till 3 June 2023
* Github: Unable to copy file by Copy button
* [GCC is fixed with 5.0 and is unable to upgrade to newer version, which causes issue when compiling device tree in Raspbian](https://github.com/TranPhucVinh/Raspberry-Pi-GNU/blob/main/Kernel/Device%20tree/Add%20a%20new%20node%20to%20device%20tree%20by%20dtsi%20file%20modification.md)
* [Raspberry Pi Imager fails to flash/write Raspbian to the SD card](https://github.com/TranPhucVinh/Raspberry-Pi-GNU/blob/main/Environment/Install%20and%20config.md#using-raspberry-pi-imager)
* [Linux kernel 4.15.0-142-generic which doesn't support epoll events like EPOLLET, EPOLLIN, EPOLLOUT, EPOLLHUP,... in kernel space](https://github.com/TranPhucVinh/C/tree/master/Kernel/Character%20device/Character%20device%20operations/Poll#epoll-handling-in-character-device)
* [STM32CubeIDE](https://github.com/TranPhucVinh/STM32-HAL-Layer-Framework/blob/main/Environment/Install%2C%20run%20and%20debug.md):
  * v1.4.1.: Live Expression can't be used to watch/debug the Global variable
  * v1.5.1: 
    * Can't flash firmware to STM32 board by STlink v2.
    * Can't import an existed project to workspace while STM32CubeIDE v1.4.0 can import it normally.
  * STM32CubeIDE v1.7.0: Can't import an existed project to workspace.

# Computer networks
* [Internet hardware and software components](): A services description, addressing process
* Protocol Layers and Their Service Models: A human analogy to computer network protocol, commmunication protocol in computer network
* Internet accessing: Broadband residential access, Internet access in enterprise and home by Ethernet and WiFi and [Wide-area wireless access by cellular network]()
* [OS overview]()