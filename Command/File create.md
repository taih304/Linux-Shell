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

This means it is a file, owner can both read and write the file, owner group can read and write, all userd can read the file but can't execute the file.

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

**File permission**

The typical file permission is: ``trwxrwxrwx``

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
