### Creating a file

The ``>`` operator will overwrite an existing file, while the ``>>`` operator will append the output to the file.

``> filename.txt``: Create ``filename.txt``

**With touch**: ``touch filename.extension``

### Text editor

```shell
nano <name of file want to create>
```

```shell
nano index.html
```

## Permission

You can see many information like ``rw-rw-r--`` : stand for read-write/read-write....

Take this for example:

```
-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md
```

start with ``-``: mean it is a file

if start with ``d``: it is a directory

**Change permission**

* ``4``: for read
* ``2``: for write
* ``1``: execute

``mode = 4+2+1 = 7``: file can be read, write, execute

``4+2``: can be read and write

``chmod``: change mode

``chmod file_name_or_folder_name mode``

e.g ``chmod 775 name.sh``

**File permission**

the typical file permission is: ``trwxrwxrwx``

* ``t``: type
* ``-``: a file
* ``d``: directory
* ``l``: symbolic link

the next 3 group is for the owner,the owners group, and all users.

if a "-" (dash) mean a permission (r,w,x) is denied

e.g:

``-rw-rw-r--``: it is a file, owner and both read and write the file, owner group can read and write, all user can read the file

=> no user can execute the file

### ``grep`` for file handler

``grep 'character' <file to lookup'``: look for character/strings in a specific file

``grep -i "<!word>" <!file to search>``: ignore the uppcase in search

List the current connected devices:

```shell
dmesg | grep tty
```

List all files in GB size: ``du -h|grep 'G'``

### pipe

``|`` is used for pipe

```shell
echo "terrorist" | grep 't'
```

result: terrorist

``ls | grep "t"``

**Result:** Display all folder has "t" in its name