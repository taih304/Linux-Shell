# pwd
Print working directory
# dir
Print out all files and folders in current directory
# sudo nautilus
Open the folder with ``root`` permission
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
# tree

``tree`` command is used to display the tree of all files inside a directory

tree command install

```sh
sudo apt install tree
```

``tree directory_name``: Display the tree of all files inside ``directory_name``