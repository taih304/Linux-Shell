# echo

```shell
echo a #result a
```

**Error**

Note: if you type ``a = 9``, or you leave space between the ``=``, this will be an error.

```
error: command not found
```

Set value to variable by other variable

```sh
a=4
b=$a
echo $b
```

``-n``: Print a string to stream without a newline

E.g: ``echo -n 123``

Shell variables are stored as string variables. With ``a=10``, the ``10`` stored in ‘a’ is not treated as a number, but as a string of characters ``1`` and ``0``.

## -e

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

Notice that all implementation above print out the string, not number. To print out a number, use escape sequence ``\x`` for hex

```sh
echo -e '\x61' #For number 0x61
```

Character ``a`` which is corresponded to ASCII code ``0x61`` is print out on the terminal

**Application**: [Using ``-e`` will help sending a number to USB port instead of string](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/USB.md#send-characters-from-pc-to-mcu-to-control-its-gpio)

## Double quote vs single quote

Using double quote (``""``) will replace the variable value with ``$``

```shell
a=29
b="this is $a"
echo $b #this is 29
```

Using single quote (``''``) jsut simply print out ``$``:

```shell
a=29
b='this is $a'
echo $b #this is $a
```
## String that involve tab
For any variable string included tab, "" must be used so that tab is printed out
```sh
stdin="1	tab_value_1		2   tab value 2"
echo "$stdin"
```
## Command as variable

```sh
echo $(ls) #List out all file in current folder
```

Store command in a variable

```sh
a=$(ls)
echo $a
```

# unset

``unset`` is used to unset the value of a variable

```sh
a=10
echo $a #result: 9
unset a #unset value of a
echo $a #print out nothing
a="string"
echo $a #string
```

# readonly

``readonly`` variable make the variable become the constant.

```sh
name="User name"
readonly name
name="change name" #Error: ./test.sh: line 4: name: readonly variable
```
# let

```sh
let "a = 10"
echo $a
```

For hex number:

```sh
let "a = 0x10"
echo $a
```
