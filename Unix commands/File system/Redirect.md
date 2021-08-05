### Redirect

* ``>``: Write data to a file, this will overwrite an existing file
* ``>>``: Append the output to the file

``> filename.txt``: Create ``filename.txt``

* ``>``: redirect ouput to a file
* ``<``: redirect input from a file

**Example**

``ls -a > text.md``: list all file in current directory then output to a file (stream)

Write content to a file

``echo 8 > test.txt``: Write ``8`` to file ``test.txt``

``echo 8 >> test.txt``: Append ``test.txt`` with value ``8``.

``printf "test \n" >> data.csv``

**Example**: Read and print out every line of file

```sh
while read textLine; do    
    echo $textLine    
done < test.csv
```

### File description

* stdin: 0
* stdout: 1
* stderr: 2

To redirect an error compiled script to a file: ``fail_script 2> outputfile``

Example: 

``echoa 2> text.md``: Write the result of an error command (``echoa``) to ``text.md``

### pipe

``|`` (pipe): send the output of one program to the input of another program, **not file**.

### grep

``grep`` searches for PATTERN in each FILE.

```sh
grep [OPTIONS] PATTERN [FILE...]
```

``grep "i" test.sh``: find all character ``i`` in ``test.sh``

``echo "test" | grep 't'``: print out where character ``t`` existed in ``test``.

``ls | grep "t"``: display all folder has "t" in its name

``dmesg | grep tty``: list the current connected devices

``du -h|grep 'G'``: list all files in GB size: 

**Example**: Find a pattern include space in a file

```sh
grep  "No smartcard" README.md
```

```sh
error_no_card_inserted="No smartcard"
grep  "$error_no_card_inserted" README.md
```
