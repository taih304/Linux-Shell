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

# mount

mount a filesystem. Everytime a block device like USB, SD card is plugged into an Ubuntu PC, it will **automatically mount** those devices into a file system.

``mount source_block_device target_folder``: Mount ``source_block_device`` (the source block device like ``USB``, ``SD card``,...)  to ``target_folder`` (the target folder). Note that ``target_folder`` must exist before mounting.

E.g: 

``sudo mount /dev/sdc1 mount_folder``: Mount SD card ``sdc1`` to ``mount_folder`` 

``mount /dev/sdb1 /mnt``: Mount the USB ``sdb1``

**Options**:
* ``-t``: indicate the filesystem type. The full list of all supported filesystems depends on your kernel.
* ``-o``: mount options

**Mount to loop device**: ``mount`` allows mounting via a loop device

E.g: ``mount -o loop=/dev/loop3 boot.img /mnt/tmp``

If no explicit loop device is mentioned (but just an option ``-o loop`` is given), then mount will try to find some unused loop device and use that.

E.g: ``mount -o loop boot.img /mnt/tmp``

Notice that if the mount file is ``img``, as an image file of an OS (like ``rootfs.img``, the whole files from ``~``), after mounting it with ``mount`` to the ``target_folder``. The ``target_folder`` will then then have all files of that directory like ``boot``, ``bin``, ``home``,...

**remount**: Option ``remount`` will attempt to remount an already-mounted filesystem. This is commonly used to change the mount flags for a filesystem, especially to make a readonly filesystem writeable.
```sh
mount -o remount,rw / #This will make path / (as rootfs) to be writeable
```
# umount

``umount`` will detache/unmount a file system.

E.g: ``umount /mnt/tmp``

# Redirect

* ``>``: Redirect ouput to a file, this can be used to write data to a file, this will overwrite an existing file
* ``<``: Get data from a source (e.g files, folders,...) and redirect it as the argument of a command:
* ``>>``: Append the output to the file or creates the file if it doesn't exist.
* ``<<``: here document. The program will end when encountering the string value specified by the here document. Check [read -r](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Unix%20commands/File%20system/Read%20operations.md#read) for example
* ``<<<``: here-string. Send a string to a program
 
## Create a file with >

``> filename.txt``: Create ``filename.txt``

``ls -a > text.md``: list all file in current directory then output to a file (stream)

Write content to a file

``echo 8 > test.txt``: Write ``8`` to file ``test.txt``

``echo 8 >> test.txt``: Append ``test.txt`` with value ``8``.

``printf "test \n" >> data.csv``

## Here-string example

```
grep "b" <<< "abcd"
```

## <

``cat < README.md``: Get data from README.md and redirect it to ``cat``. This command will print out the content of file ``README.md`` like ``cat README.md``

``ls < Documents``: Get all data inside folder Documents and redirect it to ``ls``. This command will be like ``cat README.md``

The ouput from ``<`` can then be written to a file with ``>``: ``cat < README.md > test.md``

## Redirect to file description

* stdin: 0
* stdout: 1
* stderr: 2

**Note**: Must be ``0>``, ``1>`` and ``2>``

``2>&1``: Send standard error (``2``) to where ever standard output (``1``) is being redirected as well.

E.g: 

``curl http://www.google.com > /dev/null 2>&1``: This sends standard error and standard output to ``/dev/null``, which means it ignores any output at all.

``ls 1> test.txt``: Send result of ``ls`` to ``test.txt``

``fail_script 2> outputfile``: redirect an error compiled script to a file: 

Example: 

``echoa 2> text.md``: Write the result of an error command (``echoa``) to ``text.md``

# pipe

``|`` (pipe): send the output of the program on the left to the input of the program on the right, **not file**.

# sed

``sed``, which stands for stream editor, is a command for file editor.

``text.txt``

```
const 1 2 3 const 4
1 2 3 const 44
```

``sed "s/const/var/" test.txt`` will replace ``const`` by ``var`` in the first occurrence of ``const`` in each line, then print out the result in stream. File ``test.txt`` will not be changed.

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
