List USB devices: ``lsusb``

Ubuntu 18.04 and 20.04 has kernel module installed by default for CP210x (e.g CP2102) and CH341, which are located in ``/lib/modules/5.15.0-79-generic/kernel/drivers/usb/serial``. Those kernel modules are not loaded when CP210x and CH341 are not plugged in.

For usb keyboard, most kernels already go with default built-in ``usbhid`` module. Experiment with removal of default kernel module ``usbhid`` could be problematic for the system and maybe difficult to recover.

All USB HID devices are automatically managed by usbhid driver. For example with CP2102, every time a CP2102 is plugged into the USB port, usbhid driver will automatically load the cp210x.ko kernel module as CP2102 device driver for usage.

# Cannot open /dev/ttyUSB0: Permission denied

This error happen as your user account is not added to ``dialout`` or ``tty`` group.

Add your account to ``dialout`` or ``tty`` groups:

```sh
sudo usermod -a -G tty yourname
sudo usermod -a -G dialout yourname
```

Or ``sudo usermod -aG tty ${USER}``

After this, logout your account to see the effect (Press Log out button in Settings)

# Access USB from terminal

``lsblk`` to list out the partitions in the USB for later mount.

E.g of a ``lsblk``:

```sh
NAME         MAJ:MIN    RM   SIZE RO TYPE MOUNTPOINT
mmcblk0         179:0    0   7.4G  0 disk 
├─mmcblk0p1     179:1    0   256M  0 part /boot
├─mmcblk0p2     179:2    0   7.1G  0 part 
```

Mount a partition, like ``mmcblk0p2`` to a directory: ``sudo mount /dev/mmcblk0p2 /media/usb``

After finish using, unmount to save memory: ``sudo umount /media/usb``

# GTKTerm 
**GTKTerm** is a useful tool to work with USB port which is only availabe in Unix OS. It supports:
* Two-way communication with USB port
* List out all connected USB ports
**Examples**: [Configuration for DRF1605H zigbee module](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Sensors%20and%20Modules/DRF1605H%20zigbee%20module.md#working-with-serial-frame-on-gtkterm).
# Examples

## Send characters from PC to MCU to control its GPIO

Sending ``H`` and ``L`` from USB port of computer to the connected MCU like ATmega328P to turn on, off its GPIO.

**Using screen**

Enter screen ``screen /dev/ttyUSB0``, then starts sending value.

**Using echo**

Arduino boards have auto-reset circuit to reset the board if new connection is initiated on USB. It is good for convenient upload or to reset for debugging at Serial Monitor open. But it causes troubles if you want to communicate with MCU from computer over USB from command line tools, scripts, python, C++,...

To disable this feature, use [stty](Device%20files/README.md#stty): ``stty -F /dev/ttyACM0 -hupcl``

``hupcl`` is equal to ``hupc``: Send a hangup signal when the last process closes the tty.

* ``echo H > /dev/ttyUSB0`` or ``echo 'H' > /dev/ttyUSB0``: Turn ON
* ``echo L > /dev/ttyUSB0`` or ``echo 'L' > /dev/ttyUSB0``: Turn OFF

Sending number to turn, off the MCU GPIO:

* Using echo: ``echo -e "\x1" > /dev/ttyUSB0``
* Using printf: ``printf "\x1" > /dev/ttyUSB0``

To send more than 2 bytes to MCU: 

* ``echo -e "\x12\x34" > /dev/ttyUSB0``
* ``printf "\x12\x34" > /dev/ttyACM0``

## Read data from USB port

**Using cat**: 

```sh
while [ true ]
do
    cat /dev/ttyUSB0
done 
```

**Using read**: Read a number of bytes from the USB port

```sh
while [ true ]
do
    read -a store_array -N 14 < /dev/ttyUSB0
    for value in ${store_array[@]}
    do
        echo $value
    done 
done 
```

## Two way communication

Two way communication

* If MCU received ``0x12`` from PC, sends ``Received 0x12`` to PC USB port.
* If MCU received ``0x34`` from PC, sends ``Received 0x34`` to PC USB port.

```sh
while [ true ]
do
    printf "\x34" > /dev/ttyACM0
    read -a store_array -N 13 < /dev/ttyACM0
    for value in ${store_array[@]}
    do
        echo $value
    done 
    sleep 1
done 
```
