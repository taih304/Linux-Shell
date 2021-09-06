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

By default, the USB devices (located in ``/dev``) operate with baudrate 9600.

For other baudrate value configuration, like ``115200``: ``stty -F /dev/ttyUSB0 115200``

**Note**: Only the valid baudrate value like ``4800``, ``9600``, ``115200``,... are accept. For invalid value like ``9500``, there will be error:

```
stty: invalid argument ‘9500’
Try 'stty --help' for more information.
```

### /dev/null

``echo a > /dev/null``: Redirect the standard output but you'll still see any errors. Exit status ``0``

``ecsdasdas &> /dev/null``: Redirect all output, including errors. Exit status ``127``

### screen

The ``screen`` package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

To end ``screen``: ``Ctr+A+D``.

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