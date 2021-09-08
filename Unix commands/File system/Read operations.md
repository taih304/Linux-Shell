``less filename``: Read a file, the opened filename will be opened to cover the current terminal window.

``file file_name``: determine file type of ``file_name``

``stat``: Display file or file system status. E.g: ``stat folder_1``, ``stat test.txt``

``pwd``: print working directory

``dir``: print out all files and folders in current directory

``realpath filename``: print out path of a file

``sudo nautilus``: Open the folder with root permission

### cat

``cat [option] [file]``: display content of a file on terminal

``cat filename1.md filename2.md``: display the content of 2 files

Using ``cat`` to create a new file then enter the value for it: ``cat > filename1.md``.

After finishing, type ``Ctrl+D`` or ``Ctrl+C``.

### read

Read a line from the standard input and split it into fields.

``read -a store_array``: Read enterd string in the current running terminal and store to ``store_array``. The stored string will be broken if encounter space.

``read -a store_array -N 14``: Read 14 entered characters from the current running terminal (including space), it will break if having enough character.

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

### ls

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

``ls -li test.c``: List all files information

**Output**: ``7997323 -rw-rw-r-- 1 username devicename 332 Thg 9   8 21:44 test.c``

``7997323``: inode

### type

``type command_name``: information of that command

``type cd``: information of ``cd`` command

### df

``df [OPTION] [FILE]``: Show information about the file system on which each FILE resides, or all file systems by default.

* ``df -h``: list size of hardware, and usage of percentage
* ``df -i``: list all inode

### du

`` du [OPTION] [FILE]``: Summarize disk usage of the set of FILEs, recursively for directories.

* ``du -h``: list out disk usage in MB
* ``sudo du -h --max-depth=1``: list the size of all file and folder in current directory

## Other commands

``gnome-open filename``: gnome to open a file

``libreoffice --writer file.odt``or ``libreoffice --writer file.doc``: Open libreoffice doc