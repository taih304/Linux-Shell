# Create

* ``touch filename.txt``: Create new file ``filename.txt``
* ``mkdir foldername``: make a directory (a folder)
* [File archive and compression](File%20archive%20and%20compression.md)

## fdisk

**fdisk**, abbreviated for **format disk**, is a dialog-driven program for the creation and manipulation of partition tables. Check [fdisk implementation document](fdisk.md).

# [Read](Read%20operations.md)

* [cat]()
* [read]()
* [source and .]()
* [printenv]()
* [Other commands]()

# [Write](Write%20operations.md)

* [cp](), [mv]()
* [nano](), [sed]()
* [printf](), [pipe]()
* [dd](Write%20operations.md#dd), tee, [mount](Write%20operations.md#mount), unmount
* [Redirect](Write%20operations.md#redirect): >, <, >>, <<, <<<
* [ln, soft link/symbolic link vs hard link](Write%20operations.md#ln)

## cp

``cp``: Copy ``SOURCE`` to ``DEST``, or multiple ``SOURCE(s)`` to ``DIRECTORY``.

``cp test test_copy``: copy the file ``test`` to file/folder ``test_copy``. It will overwrite the content of file ``test_copy`` if existed or create ``test_copy`` if not exit. If folder ``test_copy`` exists, ``test`` will be copied inside.

Copy file to folder can also end with ``/``: ``cp test test_copy/``

Copy folder to folder with ``-R``: ``cp -R folder_1/ folder_2/``
 
Copy a file to the current running terminal, i.e opening that file: ``cp test.c /dev/tty``

Copy input from the current running terminal to a file, i.e writing to that file: ``cp /dev/tty test.c``
## nano

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

## mv

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename
# Delete
## rm

``rm``: remove a file, not directory

``rm filename``

``rm *`` : to remove everything on the directory

``rmdir``: remove directory, You can only use this command to remove an empty directory

``rm -r``: remove a non-empty directory

``rm -rv`` (or ``rm -r -v``): remove a non-empty directory with detailed information like: remove ``filename``

To remove sudo file: ``sudo rm -rv filename``
