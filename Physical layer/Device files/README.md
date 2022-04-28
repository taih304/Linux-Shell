# Fundamental concepts

* [Character devices]()
* [Block devices]()

List all character devices and block devices with major number: ``cat /proc/devices``

A Memory Technology Device (MTD) is a type of device file in Linux for interacting with flash memory.

**UBIFS** file-system stands for UBI File System. UBI stands for “Unsorted Block Images”. UBIFS is a flash file system, which means it is designed to work with flash devices. It is important to understand, that UBIFS is completely different to any traditional file-system in Linux, like Ext2, XFS, JFS, etc. UBIFS represents a separate class of file-systems which work with **MTD devices**, not block devices.

# /dev

``/dev`` is the location of special or device files.

### /dev/null

``echo a > /dev/null``: Redirect the standard output but you'll still see any errors. Exit status ``0``

E.g: ``ecsdasdas &> /dev/null``: Redirect all output, including errors. Exit status ``127``

### /dev/kmsg

Kernel log is stored inside the kernel log buffer, which is a ring buffer, and is exported to userspace through ``/dev/kmsg``. The usual way to read it is using dmesg.

To view the kernel log realtime: ``cat /dev/kmsg``

``dmesg`` (diagnostic message) prints the message buffer of the kernel.

``dmesg`` will print time like ``[43307.062926]``

``dmesg -T`` will print time like ``[Fri Aug  6 21:16:06 2021]``

# Device files command

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
