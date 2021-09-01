## Read file

``less filename``: Read a file, the opened filename will be opened to cover the current terminal window.

``nano filename``: edit the content of file ``filename`` or create a new one if not existed.

``touch filename.txt``: Create new file ``filename.txt``

``stat``: Display file or file system status. E.g: ``stat folder_1``, ``stat test.txt``

``sudo nautilus``: Open the folder with root permission

### cat

``cat [option] [file]``: display content of a file on terminal

``cat filename1.md filename2.md``: display the content of 2 files

Using ``cat`` to create a new file then enter the value for it: ``cat > filename1.md``.

After finishing, type ``Ctrl+D`` or ``Ctrl+C``.

### df

``df [OPTION] [FILE]``: Show information about the file system on which each FILE resides, or all file systems by default.

* ``df -h``: list size of hardware, and usage of percentage
* ``df -i``: list all inode

### du

`` du [OPTION] [FILE]``: Summarize disk usage of the set of FILEs, recursively for directories.

* ``du -h``: list out disk usage in MB
* ``sudo du -h --max-depth=1``: list the size of all file and folder in current directory

### source and ``.``

``source``: ``source filename [arguments]``

``.``: ``. filename [arguments]``

``source`` and ``.`` execute commands from a file in the current shell. Read and execute commands from ``FILENAME`` in the current shell. 

E.g: File ``test.txt`` has content ``ls``

``source test.txt`` and ``. text.txt`` will run ``ls`` command

### printenv

``printenv``: Print out all environment variable

All environment variable can be print out with ``echo $env``, e.g: ``echo $USER``

E.g: ``echo user: $USER``

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

**File permission**

The typical file permission is: ``trwxrwxrwx``


**Example**: Cannot open /dev/ttyUSB0: Permission denied

```bash
$ sudo chmod -R 777 /dev/ttyUSB0
```

## Other commands

``gnome-open filename``: gnome to open a file

``libreoffice --writer file.odt``or ``libreoffice --writer file.doc``: Open libreoffice doc