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

``ls 1> test.txt``: Send result of ``ls`` to ``test.txt``

``fail_script 2> outputfile``: redirect an error compiled script to a file: 

Example: 

``echoa 2> text.md``: Write the result of an error command (``echoa``) to ``text.md``

### pipe

``|`` (pipe): send the output of one program to the input of another program, **not file**.