# cat

``cat [option] [file]``: display content of a file on terminal

``cat filename1.md filename2.md``: display the content of 2 files

**cat** is implemented by 3 [system calls/C functions](https://github.com/TranPhucVinh/C/tree/master/Physical%20layer/File%20IO/System%20call#fundamental-concepts): [open()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/File%20IO/System%20call/fcntl.md#open), [read()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/File%20IO/System%20call/unistd.md#read) and [close()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/File%20IO/System%20call/unistd.md#close).

Using **cat** to create a new file then enter the value for it: ``cat > filename1.md``.

After finishing, type **Ctrl+D** or **Ctrl+C**.

**Read file content into a variable**:
```sh
file_contents=$(cat "main.cpp")
echo "$file_contents"
```
# source and .

``source filename [arguments]``

``.``: ``. filename [arguments]``

``source`` and ``.`` execute commands from a file in the current shell. Read and execute commands from ``FILENAME`` in the current shell. 

E.g: File ``test.txt`` has content ``ls``

``source test.txt`` and ``. text.txt`` will run ``ls`` command

# cut
**cut** will cut out the specific pattern from its input.

Some common options for cut include:

* **-c**, **--characters=LIST**: Select only these characters.
* **-f**, **--fields=LIST**: Select only these fields. By default, **-f** takes tab (``\t``) as its delimiter.
* **-d**, **--delimiter=DELIM**: Use **DELIM** instead of **TAB** for field delimiter.
* **-s**, **--only-delimited**: Do not print lines not containing delimiters.
* **--output-delimiter=STRING**: Use STRING as the output delimiter.

## Extract specific characters from a line

```sh
echo "Hello, World!" | cut -c 1-5 # Hello
```
```sh
echo "Hello, World!" | cut -c 1,5 # Ho: Get the 1st and 5th characters
```
```sh
echo "Hello, World!" | cut -c 5- # o, World! # Cut from character 5 till the end
```
## Extract specific fields from a line using a delimiter
```sh
echo "John:Doe:30" | cut -d ':' -f 1,3
# Output: John:30
```
Or
```sh
echo "John:Doe:30" | cut -d ':' -f1,3
```
**cut can't take a string as its delimiter**, use [awk]() instead.
## Extract specific fields from a file
```sh
cat data.txt
# Alice,Smith,25
# Bob,Jones,30
# Charlie,Brown,35

cut -d ',' -f 2 data.txt
# Smith
# Jones
# Brown
```
with **echo**
```sh
echo "Alice,Smith,25" | cut -d ',' -f 2 # Smith
```

# Other commands

* ``gnome-open filename``: gnome to open a file
* ``less filename``: Read a file, the opened filename will be opened to cover the current terminal window.
* ``stat``: Display file or file system status. E.g: ``stat folder_1``, ``stat test.txt``
* ``readlink``: Get path of a file. User have to be inside the folder where that file is in then type ``readlink -f file.txt``
* ``realpath filename``: print out path of a file

## file
``file file_name``: determine file type of ``file_name``

**E.g**: ``file main.c`` will return ``main.c: C source, ASCII text, with CRLF line terminators``

## sort

``sort`` arrange contents inside a file into alphabetical order (arrange from number, i.e 0, 1,... to a, b, c,...) and print out (content inside that file won't change).

``sort test.c``

**Result**

```c
char *returned_string = (char*) malloc(str_len + 1);
char *returned_string = return_string("Displayed string", 5);
display_function("Hello, World !", 3);//Hel
free(returned_string);
//Other content follow the alphabetical order go here
```