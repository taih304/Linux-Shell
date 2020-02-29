### Redirect

The ``>`` operator will overwrite an existing file, while the ``>>`` operator will append the output to the file.

``> filename.txt``: Create ``filename.txt``

* ``>``: redirect ouput to a file
* ``<``: redirect input from a file

### Text editor

```shell
nano filename
```

``nano`` allows user to edit content of file or create a new one if not existed.

**Create new file with touch**: ``touch filename.extension``

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

``chmod +x``: Make file executable

**File permission**

The typical file permission is: ``trwxrwxrwx``

### pipe

``|`` (pipe): send the output of one program to the input of another

### grep

```sh
grep [OPTIONS] PATTERN [FILE...]
```

``grep`` searches for PATTERN in each FILE.

``grep "i" test.sh``: find all character ``i`` in ``test.sh``

``echo "test" | grep 't'``: print out where character ``t`` existed in ``test``.

``ls | grep "t"``: display all folder has "t" in its name

``dmesg | grep tty``: list the current connected devices

``du -h|grep 'G'``: list all files in GB size: 