# mount

mount a filesystem. When the **mount** command is executed without any arguments, it provides a list of all currently mounted filesystems along with relevant details, e.g:
```
proc on /proc type proc (rw,relatime)
sysfs on /sys type sysfs (rw,relatime)
none on /dev type devtmpfs (rw,relatime,size=465564k,nr_inodes=116391,mode=755)
```

Everytime a block device like USB, SD card is plugged into an Ubuntu PC, it will **automatically mount** those devices into a file system.

``mount source_block_device target_folder``: Mount ``source_block_device`` (the source block device like ``USB``, ``SD card``,...)  to ``target_folder`` (the target folder). Note that ``target_folder`` must exist before mounting.

E.g: 

``sudo mount /dev/sdc1 mount_folder``: Mount SD card ``sdc1`` to ``mount_folder`` 

``mount /dev/sdb1 /mnt``: Mount the USB ``sdb1``

**Options**:
* ``-t``: indicate the filesystem type. The full list of all supported filesystems depends on your kernel.
* ``-o``: mount options

**Mount to loop device**: ``mount`` allows mounting via a loop device

E.g: ``mount -o loop=/dev/loop3 boot.img /mnt/tmp``. However, it must be sure that ``/dev/loop3`` isn't mounted to any other device yet. Use ``lsblk`` command to list out all loop devices mounted as the blocked ones.

If no explicit loop device is mentioned (but just an option ``-o loop`` is given), then mount will try to find some unused loop device and use that.

E.g: ``mount -o loop boot.img /mnt/tmp``

Notice that if the mount file is ``img``, as an image file of an OS (e.g ``rootfs.img``), after mounting it with ``mount`` to the ``target_folder``, the ``target_folder`` will then then have all files of that directory like ``boot``, ``bin``, ``home``,...

**remount**: Option ``remount`` will attempt to remount an already-mounted filesystem. This is commonly used to change the mount flags for a filesystem, especially to make a readonly filesystem writeable.
```sh
mount -o remount,rw / #This will make path / (as rootfs) to be writeable
```
# umount

``umount`` will detache/unmount a file system.

E.g: ``umount /mnt/tmp``
# df

``df [OPTION] [FILE]``: Show information about the file system on which each FILE resides, or all file systems by default.

* ``df -h``: list size of hardware, and usage of percentage
* ``df -i``: list all inode

# du

`` du [OPTION] [FILE]``: Summarize disk usage of the set of FILEs, recursively for directories.
* ``du -h``: list out disk usage in MB
* ``sudo du -h --max-depth=1``: list the size of all file and folder in current directory