## Basic Command

``cd ../..``: change to previous folder

``pwd``: print working directory

``realpath filename``: print out path of a file

``mkdir <name of folder>``: make a directory (a folder)

``cp``: copy

For example, we have a folder ``username``

``cp test username``

=> we copy the file test to folder ``username``

### List

``ls``: print out all the folder in current directory

``ls -l``: list in long format, show more detail of the file/ list detail information

``ls -a``: list all file and directory (including hidden files).

In the result, a file start with "." (dot) mean it is a hidden files

To hide a file rename it to ``.itsname``

**list all devices**

```shell
cd /dev/
ls
```

List the current connected devices

```shell
dmesg | grep tty
```

**NOTE**

Combine:

```shell
ls -l -a
ls -la
```

### System handler

``passwd username``: Change password

### Permission

You can see many information like ``rw-rw-r--`` : stand for read-write/read-write....

Take this for example:

```
-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md
```
start with -: mean it is a file

if start with d: it is a directory

**change permission**

``4``: for read

``2``: for write

``1``: execute

``mode = 4+2+1 = 7``: file can be read, write, execute

4+2: can be read and write

``chmod``: change mod

``chmod <name of file/folder> mode``

e.g ``chmod 775 name.sh``

**File permission**

the typical file permission is: ``trwxrwxrwx``

with ``t``: type
``-``: a file

``d``: directory

``l``: symbolic link

the next 3 group is for the owner,the owners group, and all users.

if a "-" (dash) mean a permission (r,w,x) is denied

e.g:

``-rw-rw-r--``: it is a file, owner and both read and write the file, owner group can read and write, all user can read the file

=> no user can execute the file
