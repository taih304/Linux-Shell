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

**Other commands**

* ``sudo lshw``: list system hardware information
