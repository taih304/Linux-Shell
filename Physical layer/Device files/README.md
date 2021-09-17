``/dev`` is the location of special or device files.

### /dev/null

``echo a > /dev/null``: Redirect the standard output but you'll still see any errors. Exit status ``0``

``ecsdasdas &> /dev/null``: Redirect all output, including errors. Exit status ``127``

### stty

``stty`` displays or changes the characteristics of the terminal.

```
stty [-F DEVICE | --file=DEVICE] [SETTING]...
```

``-a, --all``: print all current settings in human-readable form

This also include size of the current running terminal:

```sh
stty --all
```

```
speed 38400 baud; rows 31; columns 173; line = 0;
[...]
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