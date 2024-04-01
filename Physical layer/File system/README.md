# [Fundamental concepts](Fundamental%20concepts.md)

* [Filesystem architecture](Fundamental%20concepts.md#filesystem-architecture)
* [inode](Fundamental%20concepts.md#inode)
* [File system types](Fundamental%20concepts.md#types): [sysfs](Fundamental%20concepts.md#sysfs), [procfs](Fundamental%20concepts.md#procfs), [devpts](Fundamental%20concepts.md#devpts), [FAT and FatFs](Fundamental%20concepts.md#fat-and-fatfs)
* [File permission](Fundamental%20concepts.md#file-permission)
# [File hierarchy](File%20hierarchy.md)
For file hierarchy inside a Linux system, check [file hierarchy document](File%20hierarchy.md)

# Basic commands

* ``readlink``: Get path of a file. User have to be inside the folder where that file is in then type ``readlink -f file.txt``
* ``pwd``: print working directory
* ``dir``: print out all files and folders in current directory
* ``realpath filename``: print out path of a file
* ``file file_name``: determine file type of ``file_name``

**E.g**: ``file main.c`` will return ``main.c: C source, ASCII text, with CRLF line terminators``

* ``sudo nautilus``: Open the folder with ``root`` permission
# [File operations](File%20operations)

## Create
* touch
* mkdir
* [File archive and compression](File%20operations/File%20archive%20and%20compression.md): zip, unzip, unrar, ar, tar, gzip and gunzip; Searching the compressed file: zgrep, zipgrep and zcat
## [Read](File%20operations/Read%20operations.md)
* cat
* read
* source and .
* printf
* tree: display the tree of all files inside a directory
* sort: arrange contents inside a file into alphabetical order
* type: give information of a command
* file: determine file type
* df, du
## [Write](Write%20operations.md)
* cp
* nano
* mv
* dd
* tee
* mount, umount
* Redirect operators: >, <, >>, <<, <<<
* pipe: send the output of the program
* sed: Stream editor
* ln: Hard link, soft link
## [Delete](File%20operations.md#delete)
* rm: Remove a file, not directory
* rmdir: Remove an empty directory
# ls

Print out all the folder in current directory

``-l``: list in long format, show more detail of the file/list detail information, ``ll`` is the alias for ``ls -l``.

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