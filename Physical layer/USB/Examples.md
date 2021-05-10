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

### Example 2

Read serial port data

**Using cat**: 

```sh
while [ true ]
do
    cat /dev/ttyUSB0
done 
```
