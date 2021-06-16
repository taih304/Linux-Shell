```shell
echo a #result a
```

**Error**

Note: if you type ``a = 9``, or you leave space between the ``=``, this will be an error.

error: command not found

Set value to variable by other variable

```sh
a=4
b=$a
echo $b
```

``-n``: Print a string to stream without a newline

E.g: ``echo -n 123 > /dev/ttyUSB0``

### ``-e``

``echo -e``: enable interpretation of backslash escapes:

```sh
a="hello \n"
a+="world"
echo -e $a
```
```
hello
world
```

### Variable declare

``unset`` variable

```sh
a=10
echo $a #result: 9
unset a #unset value of a
echo $a #print out nothing
a="string"
echo $a #string
```

``readonly`` variable

```sh
name="User name"
readonly name
name="change name" #Error: ./test.sh: line 4: name: readonly variable
```

### Represent pattern

```shell
a=29
b="this is $a"
echo $b #this is 29
```

### Command as variable

```sh
echo $(ls) #List out all file in current folder
```

Store command in a variable

```sh
a=$(ls)
echo $a
```

### Exit status

``$?``: Return the exit status of the latest executed command

* ``0``: Run successfully
* ``1``: Miscellaneous errors: file not existed, divide by zero, impermissible operations,...
* ``25``:	Inappropriate ioctl for device
* ``127``: command not found
* ``255\*``: Exit status out of range

```sh
ls
echo $? #0
```

### Command line argument

```sh
echo "First argument $0"
echo "Second argument $1"
echo "Third argument $2"
echo "All argument $@"
echo "total number of parameter: $#"
```

**Run**: ``./test.sh 2nd 3rd all``

**Result**

```
First argument ./test.sh
Second argument 2nd
Third argument 3rd
All argument 2nd 3rd all
total number of parameter: 3 (argument ./test.sh is not count)
```

### Import file

``file.sh``

```sh
string="Hello, World!"
```

To import file ``file.sh``, use: ``. file.sh`` or ``source file.sh``

```sh
# . file.sh
source file.sh
echo $string #Hello, World!
```

### Export file

```sh
echo "$(<jsonData.json)"
```

```sh
echo "$(cat jsonData.json)"
```

### Variable types

Bash doesn't have variable types, types of variable are handled by ``declare`` command.

```sh
declare -i num
num=42
```

Then ``declare -p num`` will give: ``declare -i num="42"``

If ``num="Hello, World !"`` (string), then ``declare -p num`` will give: ``declare -i num="0"``

``check_type.sh``: Check type of the entered string, whether it is integer or string.
