**bin** : the directory bin store all the command line used in Linux

``Ctrl+D`` logs out of the interface (quite similar to Ctr+C to exit)

### Basic Command

``cd ../..``: change to previous folder

``pwd``: print working directory

``realpath filename``: print out path of a file

``mkdir name_of_folder``: make a directory (a folder)

``cp``: copy

For example, we have a folder ``username``

``cp test username``

=> we copy the file test to folder ``username``

### List

``ls``: print out all the folder in current directory

Help: 

```shell
$ ls --help
$ man ls
```

``ls -l``: list in long format, show more detail of the file/ list detail information

``ls -a``: list all file and directory (including hidden files).

In the result, a file start with "." (dot) mean it is a hidden files

To hide a file rename it to ``.itsname``

**Combine**

```b
$ ls -l -a
$ ls -la
```

**list all devices**

```shell
$ cd /dev/
$ ls
```

### Move mv

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename

### Remove rm

rm stands for remove: used to remove a file, not directory

``rm <name of file>``

``rm *`` : to remove everything on the directory

``rmdir``: remove directory, You can only use this command to remove an empty directory

``rm -r``: remove a non-empty directory

``rm -rv`` (or ``rm -r -v``): remove a non-empty directory with detailed information like: remove <name of file>

To remove sudo file: ``sudo rm -rv <name of file>``

### Wildcard

``*`` : alias

``?`` : every "?" stand for one character

### Word count

``wc``: word count, used to count words in a file

```shell
wc -w <name of file>
```

* ``wc -w``: print words count
* ``wc -l``: print newline count

To know all about ``wc``, type ``man wc``
