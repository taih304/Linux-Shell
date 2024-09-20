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
