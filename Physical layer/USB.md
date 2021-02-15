## Commands

Detecting USB Drive: ``sudo fdisk -l``

Mount the USB: ``mount /dev/sdb1 /mnt``

List USB devices: ``lsusb``

### stty

``stty`` displays or changes the characteristics of the terminal.

```
stty [-F DEVICE | --file=DEVICE] [SETTING]...
```

**Example**

View existed config information of ``ttyS0`` of Raspberry Pi

```
stty -F /dev/ttyS0
```

**Result**

```
speed 115200 baud; line = 0;
min = 1; time = 0;
-brkint -icrnl -imaxbel iutf8
-isig -icanon -iexten -echo -echoe -echok -echoctl -echnoke
```

### /dev/null

``echo a > /dev/null``: Redirect the standard output but you'll still see any errors. Exit status ``0``

``ecsdasdas &> /dev/null``: Redirect all output, including errors. Exit status ``127``

## Example

### Example 1: Sending data from USB port of Linux computer to ATmega328

Send ``9``, ``8`` from Terminal Linux to turn ON/OFF LED on ATmega328.

**ATmega328 code**: ``Slave`` in ``AVR-Arduino-framework/Physical layer/UART/Master and Slave.md``

**Using screen**

The screen package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

Enter screen: ``screen /dev/ttyUSB0``. Then starts sending value.

To end screen: ``Ctr+A+D``

**Using echo**

Arduinos have auto-reset circuit to reset the board if new connection is initiated on USB. It is good for convenient upload or to reset for debugging at Serial Monitor open. But it causes troubles if you want to communicate with MCU from computer over USB from command line tools, scripts, python, C++, C#, Java.

To disable this feature: ``stty -F /dev/ttyACM0 -hupcl``

``hupcl`` is equal to ``hupc``: Send a hangup signal when the last process closes the tty.

Then:

``echo 9 > /dev/ttyUSB0``: Turn ON

``echo 8 > /dev/ttyUSB0``: Turn OFF

### Example 2: Read serial port data

**Arduino**

```c
Serial.println("Hello, World");
delay(1000);
```

**Using cat to read**: ``cat /dev/ttyUSB0``. This can just only read the baudrate of ``9660`` by default.

To read with other baudrate value like ``115200``:

```sh
stty -F /dev/ttyUSB0 115200
cat /dev/ttyUSB0
```

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