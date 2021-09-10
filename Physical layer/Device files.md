``/dev`` is the location of special or device files.

``/dev/tty`` is the current running terminal. 

``tty`` command will print out the file name of the terminal connected to standard input. E.g: ``tty`` returns ``/dev/pts/19``

``/dev/fd``: for each process, the kernel provides the special virtual directory ``/dev/fd``. This directory contains filenames of the form ``/dev/fd/n``, where ``n`` is a number corresponding to one of the open file descriptors for the process. ``/dev/fd`` is actually a symbolic link to the Linux-specific ``/proc/self/fd`` directory.

``/dev/fd/0``, ``/dev/fd/1`` and ``/dev/fd/2`` are corresponded to ``stdin`` and ``stdout`` and ``stderr``. 

As a convenience, the names ``/dev/stdin``, ``/dev/stdout``, and ``/dev/stderr`` are provided as symbolic links to, respectively, ``/dev/fd/0``, ``/dev/fd/1``, and ``/dev/fd/2``.

``/dev/pts`` stores all number of the current opening terminal. Choosing the right terminal number will output data to the right terminal.

E.g:

If the current opening terminal has ``pts`` number is ``4`` then ``echo Hello, World ! > /dev/pts/4`` will print out ``Hello, World !`` to this terminal.

``/dev/input`` lists all built-in hardware devices of the computer like touch pad, Power Button, Video bus,... All those devices has ``id`` like ``event1``, ``event12``, ``event15``,...

To view the corressponding ID of the those devices: ``xinput``

``id=2`` corrresponds to ``event2``.

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