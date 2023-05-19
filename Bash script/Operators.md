``seq 1 10``: Print out from 1 to 10

# + operator

```shell
a=10
a=$((a+9))

echo $a #result: 19
```

Or it can be: ``a=$(( a + 9 ))``

```sh
a="hello"
a+=" world"
echo $a #hello world
```

# ^ operator (XOR operator)
```sh
hexVal0=$((0xb)) #  0b1011
hexVal1=4 # 0b0100
hexResult=$((hexVal0^hexVal1)) # Or: hexResult=$(($hexVal0^$hexVal1)) 
echo $hexResult # 15 as //0b1111
```
```sh
a=1
b=$((a^=1))
echo $b #0
echo $a #0
```

# &&

```sh
command1 && command2
```

``command2`` is executed if, and only if, command1 returns an exit status of ``0`` (success).

# ||

```sh
command1 || command2
```

``command2`` is executed if, and only if, ``command1`` returns a non-zero exit status.

E.g:

```sh
lsasdsada || cd Folder/
```

**Result**

```
bash: lsasdsada: command not found
(then change to folder Folder)
```

```sh
ls || cd Folder/
```

**Result**: Change to folder ``Folder``

**Example**: Short-hand if-else

```sh
username$hostname: [ "a" == "a" ] && echo "Strings are equal" || echo "Strings are not equal"
```

# ; (semicolon)

You can put two or more commands on the same line separated by the semicolon ``;``. All the arguments before ``;`` will be treated as a separate command from all the arguments after the ``;``. All the commands will be executed sequentially waiting for each command to finish before starting the new one.

```sh
command1 ; command2  
```

# : (colon)

The no-op command in shell is ``:`` (colon).

# & (control operator)

If a command is terminated by the control operator ``&``, the shell executes the command asynchronously in a subshell. This is known as executing the command in the background, and these are referred to as asynchronous commands.

**Example**: ``ls &``

**Result**

```
username@hostname: [1] 20014
username@hostname: folder_1 folder_2
```

# Performing a list of commands with operators

A list is a sequence of one or more pipelines separated by one of the operators ``;``, ``&``, ``&&``, or ``||``, and optionally terminated by one of ``;``, ``&``, or a newline.

Of these list operators, ``&&`` and ``||`` have equal precedence, followed by ``;`` and ``&``, which have equal precedence.
