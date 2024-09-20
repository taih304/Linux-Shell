# cp

``cp``: Copy ``SOURCE`` to ``DEST``, or multiple ``SOURCE(s)`` to ``DIRECTORY``.

``cp test test_copy``: copy the file ``test`` to file/folder ``test_copy``. It will overwrite the content of file ``test_copy`` if existed or create ``test_copy`` if not exit. If folder ``test_copy`` exists, ``test`` will be copied inside.

Copy file to folder can also end with ``/``: ``cp test test_copy/``

Copy folder to folder with ``-R``: ``cp -R folder_1/ folder_2/``
 
Copy a file to the current running terminal, i.e opening that file: ``cp test.c /dev/tty``

Copy input from the current running terminal to a file, i.e writing to that file: ``cp /dev/tty test.c``
# nano

``nano filename``: edit the content of file ``filename`` or create a new one if not existed.

In some cases nano will try to dump the buffer into an emergency  file. This  will  happen  mainly if ``nano`` receives a ``SIGHUP`` or ``SIGTERM`` or runs out of memory.  It will write the buffer into a file named ``nano.save`` if the  buffer didn't have a name already, or will add a ``.save`` suffix to the current filename.
 
E.g: This is a wrong operation of nano with ``<`` operator and will result in the `SIGHUP``

```sh
nano fake.md < README.md
```
**Result**

```
Received SIGHUP or SIGTERM

Buffer written to nano.save
```

``README.md`` is then written to ``fake.md.save``

# mv

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename
# dd

``dd`` is used to convert and copy files:

Parameters:

* ``if``: Input file
* ``of``: Output file
* ``bs``: Block size (bytes)

Copy file ``test.c`` to ``test.md``: ``dd if=test.c of=test.md``. If ``test.md`` is not existed, it will be created.

# tee

Write content to a file

``tee filename``: Start writing the entered content from ``tty`` to ``filename``

``tee -a filename``: Appened the written content to ``filename``

# printf

``printf hello`` and ``printf "hello"`` will printf to a stream.

``printf`` is not followed by newline character, for a new line, it has to be ``printf "hello \n"``.

``printf`` ends when encountering the space

```sh
string="Hello, World !"
printf $string #Hello,
```

Store value of ``printf`` to a variable:

```sh
text=$(printf "hello")
echo $text
```

String format:

```sh
printf "%lf" 1.2 #1.200000
printf "%.2f" 1.2 #1.20
printf "%d" 12 #12
printf "%04d" 12 #0012
printf "%x" 10
```

```sh
text=$(printf "hello %d" $1)
echo $text
```

Run ``./test.sh 123``: ``hello 123``

Notice that all implementation above print out the string, not number. To print out a number, use escape sequence ``\x`` for hex

```sh
printf "\x61" #For number 0x61
```

Character ``a`` which is corresponded to ASCII code ``0x61`` is print out on the terminal

**Application**: Using ``\x`` will help sending a number to USB port instead of string.

# sed

``sed``, which stands for stream editor, is a command for file editor.

``text.txt``

```
const 1 2 3 const 4
1 2 3 const 44
```

``sed "s/const/var/" test.txt``, with **s** stands for **substitution**, will replace ``const`` by ``var`` in the first occurrence of ``const`` in each line, then print out the result in stream. File ``test.txt`` will not be changed.

Result

```
var 1 2 3 const 4
1 2 3 var 44
```

To make change/update to file ``test.txt``, use ``-i``: ``sed "-i s/const/var/" test.txt``. The whole file ``test.txt`` now will be updated.

Replacing the ``nth`` occurrence of a pattern in a line, e.g ``2`` occurance (Index started from ``0``): ``sed -i "s/const/var/1" test.txt``

To replace all occurrence of the pattern, use ``g``: ``sed -i "s/const/var/g" test.txt``

Replacing string on a specific line number, e.g ``2``: ``sed -i "2 s/const/var/g" test.txt``

# ln

``ln``: make links between files

## Hard link

**Hard link** is just different name for the same file.

``ln source_file.txt target_file.txt``: ``target_file.txt`` now is the hard link of ``source_file.txt``, i.e a copied of ``source_file.txt``, has the same inode with ``source_file.txt``. Removing ``source_file.txt`` gives no effect to ``target_file.txt``
## Soft link

**Soft link**, also call **symbolic link**, abbreviated as **symlink**, is similar to MS Windows shortcuts.

``ln -s source_file.txt target_file.txt``: ``target_file.txt`` now is the symbolic link (also called soft link) of ``source_file.txt``. ``target_file.txt`` now has different inode with ``source_file.txt``. Its file type now is ``symbolic link`` (check by ``file``). Removing ``source_file.txt`` makes ``target_file.txt`` unable to read.

**Implementation**: [symbolic link setup is required for Python in /usr/bin/env](https://github.com/TranPhucVinh/Python/blob/master/README.md#symbolic-link-issue)
