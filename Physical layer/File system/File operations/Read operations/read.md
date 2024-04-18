# Read value you enter and print out

```bash
$ read enteredString
$ echo $enteredString
```

# Read a line from the standard input and split it into fields

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
# Read and print out every line of file

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

# Fail to read with echo and pipe

Attempt to ``read`` with ``echo`` and ``pipe`` fail in Bash

```sh
$ echo 1 2 3 4 5 | read a b dump
$ echo $b $a 
  
$
```

That happens as ``bash`` runs the right-hand side of a pipeline in a subshell context, so changes to variables (which is what read does) are not preserved — they die when the subshell does, at the end of the command.
