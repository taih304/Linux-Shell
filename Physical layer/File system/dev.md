# File descriptors /dev/fd

``/dev/fd``: for each process, the kernel provides the special virtual directory ``/dev/fd``. This directory contains filenames of the form ``/dev/fd/n``, where ``n`` is a number corresponding to one of the open file descriptors for the process. ``/dev/fd`` is actually a symbolic link to the Linux-specific ``/proc/self/fd`` directory.

``/dev/fd/0``, ``/dev/fd/1`` and ``/dev/fd/2`` are corresponded to ``stdin`` and ``stdout`` and ``stderr``. 

As a convenience, the names ``/dev/stdin``, ``/dev/stdout``, and ``/dev/stderr`` are provided as symbolic links to, respectively, ``/proc/self/fd/0``, ``/proc/self/fd/1``, and ``/proc/self/fd/2``.

By default, ``ls dev/fd`` will return ``0 1 2 3``. If there is a running program with an opened fd is ``4``, run ``ls dev/fd`` won't return that value

# Terminal /dev/tty

``/dev/tty`` is the current running terminal, which is character special.

``tty`` command will print out the file name of the terminal connected to standard input. E.g: ``tty`` returns ``/dev/pts/19``. ``/dev/tty*`` like ``tty1``, ``tty2``,... are **virtual terminals** (sometimes called **virtual consoles**).

``/dev/pts`` (which belongs to [devpts file system](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/README.md#devpts)) stores all number of the current opening terminal, ``ls /dev/pts`` will print them out. Choosing the right terminal number will output data to the right terminal.

E.g:

If the current opening terminal has ``pts`` number is ``4`` then ``echo Hello, World ! > /dev/pts/4`` will print out ``Hello, World !`` to this terminal.

# Input /dev/input

``/dev/input`` lists all built-in hardware devices of the computer like touch pad, Power Button, Video bus,... All those devices has ``id`` like ``event1``, ``event12``, ``event15``,... All are character special.

To view all major and minor number of input: ``ls -l /dev/input``

```
crw-rw---- 1 root input 13, 64 Feb  5 10:15 event0
crw-rw---- 1 root input 13, 65 Feb  5 10:15 event1
```

Then ``13`` is major number, ``64`` and ``65`` are minor numbers.

For input device like mouse (be not to confused between **pluggable mouse** and **hardware built-in touchpad** in laptop) with input device event file like this ``/dev/input/event18``, its input device event file will only appear when the mouse hardware device is plugged in and will disappeared when mouse is unplugged. Check [Read coordinate of a mouse cursor C source code example](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/File%20IO/System%20call/Device%20file%20operations.md#read-coordinate-of-a-mouse-cursor) as an implementation of an input device event file.

# Memory /dev/mem

``/dev/mem`` is a character device file that is an image of the main memory of the computer.  It may be used, for example, to examine (and even patch) the system. Byte addresses in ``/dev/mem`` are interpreted as physical memory addresses.

# /dev/null

**/dev/null** is a special file in Unix-like operating systems that serves as a "null device" or a bit-bucket. It is used to discard data written to it and provides a way to suppress output or input redirection.

**Discarding Output**: When data is written to /dev/null, it is discarded immediately. This is often used to suppress output from commands or programs. For example, if you want to run a command but don't need to see its output, you can redirect the output to /dev/null to discard it.

```sh
ls > /dev/null
```

# /dev/kmsg

Kernel log is stored inside the kernel log buffer, which is a ring buffer, and is exported to userspace through ``/dev/kmsg``. The usual way to read it is using dmesg.

To view the kernel log realtime: ``cat /dev/kmsg``

``dmesg`` (diagnostic message) prints the message buffer of the kernel.

``dmesg`` will print time like ``[43307.062926]``

``dmesg -T`` will print time like ``[Fri Aug  6 21:16:06 2021]``

# /dev/zero

``/dev/zero`` provides as many null characters (ASCII NUL, ``0x00``) as are read from it.

Creating a 128 MB file, called ``test.md``, filled with ``null`` characters:

```sh
dd if=/dev/zero of=test.md bs=1M count=128
```
# Device files command

## stty

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

# Block devices
In ``/dev``, SD card, SD card adapter or USB are detected as ``sdc`` like ``sdc``, ``sdc1``,... ``sdc`` which are block devices.

``lsblk``: list block devices

E.g:

```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop1    7:1    0  64.8M  1 loop /snap/gtk-common-themes/1514
sdd      8:48   1  14.9G  0 disk 
├─sdd2   8:50   1  14.6G  0 part /media/username/rootfs
└─sdd1   8:49   1   256M  0 part /media/username/rootfs
```

# Loop device

A loop device, ``vnd`` (vnode disk), or ``lofi`` (loop file interface) is a pseudo-device that makes a computer file accessible as a block device. Before use, a loop device must be connected to an existed file in the file system. 
## losetup

Set up and control loop devices.

Let's say you have an image file **base_busybox.img** with the following partition table:

```sh
Device            Boot  Start    End Sectors Size Id Type
base_busybox.img1        2048 104447  102400  50M  c W95 FAT32 (LBA)
base_busybox.img2      104448 307199  202752  99M 83 Linux
```

If you want to create a loop device for the **first partition** (**base_busybox.img1**), which starts at sector 2048, you need to calculate the byte offset:

```sh
# Calculate the offset in bytes
offset=$((2048 * 512))

# Set up the loop device with the calculated offset
losetup -o $offset /dev/loop3 base_busybox.img # Suppose that /dev/loop3 is available
```

The number 512 is commonly used because it represents the size of a sector in many disk and file system formats.

Historically, the sector size for many disk drives is 512 bytes. Although modern disks often use 4096-byte sectors (4K sectors), 512 bytes is still widely used and is a standard size in many contexts.

When working with disk images or partitions, tools like **fdisk**, display partition start addresses in terms of sectors, not bytes. For example, if a partition starts at sector 2048, it means it starts 2048 sectors from the beginning of the disk. To get the offset in bytes, you multiply the sector number by the size of a sector (512 bytes).
