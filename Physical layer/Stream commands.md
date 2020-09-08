**bin** : the directory bin store all the command line used in Linux

``Ctrl+D`` logs out of the interface (quite similar to Ctr+C to exit)

### Basic Command

``cd ../..``: change to previous folder

``pwd``: print working directory

``realpath filename``: print out path of a file

``mkdir foldername``: make a directory (a folder)

``cp``: copy

``cp test username``: copy the file ``test`` to folder ``username``

``type linux_command``: information of that command

``type cd``: information of ``cd`` command

### ls to list

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

**list all devices**

```shell
$ cd /dev/
$ ls
```

### mv to move

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename

### rm to remove

rm stands for remove: used to remove a file, not directory

``rm filename``

``rm *`` : to remove everything on the directory

``rmdir``: remove directory, You can only use this command to remove an empty directory

``rm -r``: remove a non-empty directory

``rm -rv`` (or ``rm -r -v``): remove a non-empty directory with detailed information like: remove ``filename``

To remove sudo file: ``sudo rm -rv filename``

### Help

```shell
$ ls --help
```

```shell
$ man ls
```

### wildcard

``*`` : alias

``?`` : every "?" stand for one character

### word count

``wc``: word count, used to count words in a file

```shell
$ wc -w filename #print total word in filename
```

**Result**: ``10 filename``

(``filename`` has 10 words)

```shell
$ wc -w test.sh
```
**Result**: ``10``

* ``wc -l``: print newline count
