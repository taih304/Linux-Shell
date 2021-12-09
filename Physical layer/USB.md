### Commands

Detecting USB Drive: ``sudo fdisk -l``

List USB devices: ``lsusb``

### Cannot open /dev/ttyUSB0: Permission denied

This error happen as your user account is not added to ``dialout`` or ``tty`` group.

To view the available group in your account, use command: ``groups``

To see all available groups type: ``compgen -g``

Add your account to ``dialout`` or ``tty`` groups:

```sh
sudo usermod -a -G tty yourname
sudo usermod -a -G dialout yourname
```

After this, logout your account to see the effect (Press Log out button in Settings)

## Examples

### Example 1

Sending ``H`` and ``L`` from USB port of computer to the connected MCU like ATmega328P to turn on, off its GPIO.

**Using screen**

Enter screen ``screen /dev/ttyUSB0``, then starts sending value.

**Using echo**

Arduino boards have auto-reset circuit to reset the board if new connection is initiated on USB. It is good for convenient upload or to reset for debugging at Serial Monitor open. But it causes troubles if you want to communicate with MCU from computer over USB from command line tools, scripts, python, C++, C#, Java.

To disable this feature: ``stty -F /dev/ttyACM0 -hupcl``

``hupcl`` is equal to ``hupc``: Send a hangup signal when the last process closes the tty.

* ``echo H > /dev/ttyUSB0`` or ``echo 'H' > /dev/ttyUSB0``: Turn ON
* ``echo L > /dev/ttyUSB0`` or ``echo 'L' > /dev/ttyUSB0``: Turn OFF

Sending number to turn, off the MCU GPIO:

* Using echo: ``echo -e "\x1" > /dev/ttyUSB0``
* Using printf: ``printf "\x1" > /dev/ttyUSB0``

To send more than 2 bytes to MCU: 

* ``echo -e "\x12\x34" > /dev/ttyUSB0``
* ``printf "\x12\x34" > /dev/ttyACM0``

### Example 2

Read data from USB port

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