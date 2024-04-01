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
# read
## Read value you enter and print out

```bash
$ read enteredString
$ echo $enteredString
```

## Read a line from the standard input and split it into fields

Read the entered string into variable ``var_1`` and ``var_2``:

```sh
username$hostname: read var_1 var_2
Hello, World ! String
username$hostname: echo $var_1
Hello,
username$hostname: echo $var_2
World ! String
```

By default, unless the ``-r`` option is specified, backslash ('\') shall act as an escape character. Use ``-r`` and ``<<`` to handle with backslash, space reading.

```sh
username$hostname: read -r var_1 << "end_string"
> hello, world !
> end_string
username$hostname: echo $var_1
hello, world !
```

``-a``: array

``read -a store_array``: Read enterd string in the current running terminal and store to ``store_array``. The stored string will be broken if **encountering space**.

``read -a store_array -N 14``: Read 14 entered characters from the current running terminal (including space), it will break if having enough character.

**Separated string by space**:
```sh
input_string="Hello World"

read -ra words <<< "$input_string" # Here-string to send a string to the program

for word in "${words[@]}"; do
    echo "$word"
done
```
## Read and print out every line of file

```sh
while read textLine
do    
    echo $textLine    
done < test.c
```
**Notice**: If the file has no new line at the end, the software above is unable to read the last line

**To print out a specific line**
```sh
line=1
while read textLine
do 
    echo $line
    if [ $line == 3 ] 
        then echo $textLine 
    fi
    line=`expr $line + 1`
done < tmp.md
```
To read the whole file when that file has no new line at the end:

```sh
textLine=""
while read textLine
do   
    echo $textLine    
done < test.csv
echo $textLine
```

Attempt to ``read`` with ``echo`` and ``pipe`` fail in Bash

```sh
$ echo 1 2 3 4 5 | read a b dump
$ echo $b $a 
  
$
```

That happens as ``bash`` runs the right-hand side of a pipeline in a subshell context, so changes to variables (which is what read does) are not preserved — they die when the subshell does, at the end of the command.

# source and .

``source filename [arguments]``

``.``: ``. filename [arguments]``

``source`` and ``.`` execute commands from a file in the current shell. Read and execute commands from ``FILENAME`` in the current shell. 

E.g: File ``test.txt`` has content ``ls``

``source test.txt`` and ``. text.txt`` will run ``ls`` command

# tree

``tree`` command is used to display the tree of all files inside a directory

tree command install

```sh
sudo apt install tree
```

``tree directory_name``: Display the the tree of all files inside ``directory_name``

# sort

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

# df

``df [OPTION] [FILE]``: Show information about the file system on which each FILE resides, or all file systems by default.

* ``df -h``: list size of hardware, and usage of percentage
* ``df -i``: list all inode

# du

`` du [OPTION] [FILE]``: Summarize disk usage of the set of FILEs, recursively for directories.

* ``du -h``: list out disk usage in MB
* ``sudo du -h --max-depth=1``: list the size of all file and folder in current directory

# Other commands

``gnome-open filename``: gnome to open a file

``less filename``: Read a file, the opened filename will be opened to cover the current terminal window.

``stat``: Display file or file system status. E.g: ``stat folder_1``, ``stat test.txt``