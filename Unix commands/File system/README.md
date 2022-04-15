## Types

### sysfs

``sysfs`` is a pseudo file system (``/sys``) provided by the Linux kernel that exports information about various kernel subsystems, hardware devices, and associated device drivers from the kernel's device model to user space through virtual files.

On PC with an OS, as ``ls`` on ``/sys/class/gpio`` only return ``export`` and ``unexport`` (GPIO chip like ``gpiochip0``, ``gpiochip100``, ``gpiochip504``,... are not included) so the virtual GPIO files sytem can't be created.

``echo 1  > export`` has error: ``bash: echo: write error: Invalid argument``

To view virtual GPIO debug information: ``cat /sys/kernel/debug/gpio``

``sys/dev`` stores all block (``block`` directory) and character (``char``) devices.

``sys/dev/char`` has structure: ``major_number:minor_number``. Eg: ``10:1``.

### procfs

``procfs`` is pseudo filesystem (``/proc``) containing information about the system resources, including currently running processes, kernel, hardware. 

### devpts

``devpts`` is a virtual filesystem contains solely devices files used to implement terminal emulators. It is normally mounted at ``/dev/pts`` and represent slaves to the multiplexing master located at ``/dev/ptmx``.

## File permission

``r``,``w``: stand for read, write

Permission ``-rw-rw-r--`` means:

* The first character is ``-`` means it is a file
* The next 3 characters ``rw-`` represents the permissions for the file's owner: in this case, the owner may read from, write to, or execute the file.
* The next 3 characters ``rw-`` represent the permissions for members of the file group.
* The next 3 characters ``r--`` is the permission for "others" (everyone else) 

If a ``-`` means a permission (r,w,x) is denied.

**Example**:

```
-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md
```

This means it is a file, owner can both read and write the file, owner group can read and write, all user can read the file but can't execute the file.

First character acceptance value 
* ``t``: type
* ``-``: a file
* ``d``: directory
* ``l``: symbolic link

**Change permission**

* ``4``: for read
* ``2``: for write
* ``1``: execute

``mode = 4+2+1 = 7``: file can be read, write, execute

``4+2``: can be read and write

``chmod``: change mode of folder or file

E.g ``chmod 775 name.sh``

``chmod +x``: Make file executable

The typical file permission is: ``trwxrwxrwx``

**Example**: Cannot open /dev/ttyUSB0: Permission denied

```bash
$ sudo chmod -R 777 /dev/ttyUSB0
```

File type + file permission can be view by ``stat`` command. File type + file permission are displayed under octal numeral system.

E.g: ``stat test.c`` gives ``Access: (0664/-rw-rw-r--)``
