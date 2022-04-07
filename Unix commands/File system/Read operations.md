``less filename``: Read a file, the opened filename will be opened to cover the current terminal window.

``file file_name``: determine file type of ``file_name``

``stat``: Display file or file system status. E.g: ``stat folder_1``, ``stat test.txt``

``readlink``: Get path of a file. User have to be inside the folder where that file is in then type ``readlink -f file.txt``

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

Read the entered string into variable

```sh
username$hostname: read var_1 var_2
Hello, World ! String
username$hostname: echo $var_1
Hello,
username$hostname: echo $var_2
World ! String
```

By default, unless the ``-r`` option is specified, backslash ('\') shall act as an escape character. Use ``-r`` and ``<<`` to handle with backslash, space reading.

```sh
username$hostname: read -r var_1 << "end_string"
> hello, world !
> end_string
username$hostname: echo $var_1
hello, world !
```

``-a``: array

``read -a store_array``: Read enterd string in the current running terminal and store to ``store_array``. The stored string will be broken if encounter space.

``read -a store_array -N 14``: Read 14 entered characters from the current running terminal (including space), it will break if having enough character.

Read and print out every line of file

```sh
while read textLine
do    
    echo $textLine    
done < test.c
```
**Notice**: If the file has no new line at the end, the software above is unable to read the last line

To read the whole file when that file has no new line at the end:

```sh
textLine=""
while read textLine
do   
    echo $textLine    
done < test.csv
echo $textLine
```

Attempt to ``read`` with ``echo`` and ``pipe`` fail in Bash

```sh
$ echo 1 2 3 4 5 | read a b dump
$ echo $b $a 
  
$
```

That happens as ``bash`` runs the right-hand side of a pipeline in a subshell context, so changes to variables (which is what read does) are not preserved — they die when the subshell does, at the end of the command.

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

Print out all the folder in current directory

``-l``: list in long format, show more detail of the file/list detail information

``-i``: view inode

``-a``: list all file and directory (including hidden files).

In the result, a file start with ``.`` (dot) mean it is a hidden files

To hide a file rename it to ``.itsname``

**Combine**

```bash
$ ls -l -a
$ ls -la
```

``ls -li test.c``: List all files information (including inode)

Result of ``ls -l``:

```
-rw-rw-r--  1 owner group   1108 Feb  5  2021 test.md
drwxrwxr-x  8 owner group   4096 Jul 26 11:48 Folder 1
lrwxrwxrwx  1 owner group      9 Sep 10 23:30 symlink_file -> test.md
```

(From left to right): File type + permission, links, owner, group, file size, Creation date or last modified time, file name

E.g: 

* ``Feb  5  2021`` of ``test.md`` is creation date
* ``Jul 26 11:48`` is modified date.

File types include file (``-``), directory (``d``), character device (``c``) and symbolic link (``l``).

For character devices (located in ``/dev``), e.g:

```
crw-------  1 root root    238,   0 Sep 14 15:39 Character device
crw-------  1 root root      5,   1 Sep 14 11:54 console
```

(From left to right): File type + permission, owner, group, major number, minor number, Creation date or last modified time, file name.

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
