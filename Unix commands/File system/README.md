## Types

### sysfs

``sysfs`` is a pseudo file system (``/sys``) provided by the Linux kernel that exports information about various kernel subsystems, hardware devices, and associated device drivers from the kernel's device model to user space through virtual files.

On PC with an OS, as ``ls`` on ``/sys/class/gpio`` only return ``export`` and ``unexport`` (GPIO chip like ``gpiochip0``, ``gpiochip100``, ``gpiochip504``,... are included) so the virtual GPIO files sytem can't be created.

``echo 1  > export`` has error: ``bash: echo: write error: Invalid argument``

To view virtual GPIO debug information: ``cat /sys/kernel/debug/gpio``

### procfs

``procfs`` is pseudo filesystem (``/proc``) containing information about the system resources, including currently running processes, kernel, hardware. 

## Commands

``pwd``: print working directory

``realpath filename``: print out path of a file

``mkdir foldername``: make a directory (a folder)

### cp

``cp``: copy

``cp test username``: copy the file ``test`` to folder ``username``

### type

``type command_name``: information of that command

``type cd``: information of ``cd`` command

### mv

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename

### rm

``rm``: remove a file, not directory

``rm filename``

``rm *`` : to remove everything on the directory

``rmdir``: remove directory, You can only use this command to remove an empty directory

``rm -r``: remove a non-empty directory

``rm -rv`` (or ``rm -r -v``): remove a non-empty directory with detailed information like: remove ``filename``

To remove sudo file: ``sudo rm -rv filename``

## ls

``ls``: print out all the folder in current directory

``ls -l``: list in long format, show more detail of the file/ list detail information

``ls -a``: list all file and directory (including hidden files).

In the result, a file start with ``.`` (dot) mean it is a hidden files

To hide a file rename it to ``.itsname``

**Combine**

```bash
$ ls -l -a
$ ls -la
```

**list all devices**

```shell
$ cd /dev/
$ ls
```

``ls -li test.c``: List all files information

**Output**: ``7997323 -rw-rw-r-- 1 username devicename 332 Thg 9   8 21:44 test.c``

``7997323``: inode

### dir

``dir``: print out all files and folders in current directory

### printf

``printf hello`` and ``printf "hello"`` will printf to a stream.

``printf`` is not followed by newline character, for a new line, it has to be ``printf "hello \n"``.

Store value of ``printf`` to a variable:

```sh
text=$(printf "hello")
echo $text
```

Represent pattern:

```sh
text=$(printf "hello %d" $1)
echo $text
```

Run ``./test.sh 123``: ``hello 123``

``printf`` ends when encountering the space

```sh
string="Hello, World !"
printf $string #Hello,
```
