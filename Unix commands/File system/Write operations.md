### cp

``cp``: Copy ``SOURCE`` to ``DEST``, or multiple ``SOURCE(s)`` to ``DIRECTORY``.

``cp test test_copy``: copy the file ``test`` to file/folder ``test_copy``. It will overwrite the content of file ``test_copy`` if existed or create ``test_copy`` if not exit. If folder ``test_copy`` exists, ``test`` will be copied inside.

Copy to folder can also end with ``/``: ``cp test test_copy/``

Copy a file to the current running terminal, i.e opening that file: ``cp test.c /dev/tty``

Copy input from the current running terminal to a file, i.e writing to that file: ``cp /dev/tty test.c``

### tee

Write content to a file

``tee filename``: Start writing the entered content from ``tty`` to ``filename``

``tee -a filename``: Appened the written content to ``filename``

### printf

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

Represent pattern:

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


### mv

``mv``: move a file from a directory to other

``$ mv name_want_to_change name_wish_to_change``: rename

### mount

mount a filesystem

``mount source_block_device target_folder``: Mount ``source_block_device`` (the source block device like ``USB``, ``SD card``,...)  to ``target_folder`` (the target folder). Note that ``target_folder`` must exist before mounting.

E.g: 

``sudo mount /dev/sdc1 mount_folder``: Mount SD card ``sdc1`` to ``mount_folder`` 

``mount /dev/sdb1 /mnt``: Mount the USB ``sdb1``

### rm

``rm``: remove a file, not directory

``rm filename``

``rm *`` : to remove everything on the directory

``rmdir``: remove directory, You can only use this command to remove an empty directory

``rm -r``: remove a non-empty directory

``rm -rv`` (or ``rm -r -v``): remove a non-empty directory with detailed information like: remove ``filename``

To remove sudo file: ``sudo rm -rv filename``

### Redirect

* ``>``: Redirect ouput to a file, this can be used to write data to a file, this will overwrite an existing file
* ``<``: redirect input from a file
* ``>>``: Append the output to the file

**Example 1**

``> filename.txt``: Create ``filename.txt``

``ls -a > text.md``: list all file in current directory then output to a file (stream)

Write content to a file

``echo 8 > test.txt``: Write ``8`` to file ``test.txt``

``echo 8 >> test.txt``: Append ``test.txt`` with value ``8``.

``printf "test \n" >> data.csv``

**Example 2**: Read and print out every line of file

```sh
while read textLine; do    
    echo $textLine    
done < test.csv
```

### File description

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

### pipe

``|`` (pipe): send the output of one program to the input of another program, **not file**.