# Fundamental concepts

**Shell** is a command interpreter, which interprets the command which the user gives to the kernel. It can also be defined as an interface between a user and operating system. A separate compiler is not required to execute a shell program. The shell itself interprets the command in the shell program and executes them.

Linux based operating system uses **Bash shell**, the shell environment used for several purposes like storing data, storing software configuration, locating terminal settings and changing shell environments.

**Subshell**: A child process created by a shell, check [exec command](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Process/Process%20command.md#exec) to clarify this operation.

**Structure of a Unix command**:
```sh
command <mandatory_arg> [optional_arg]
```
* ``<mandatory_arg>``: The mandatory arguments required for the command
* ``[optional_arg]``: The optional arguments required for the command
  
# Shell script overview

The Shebang line is present at the top of the script, e.g:

```sh
#!/bin/bash
```

```sh
#!/bin/sh
echo "hello world"
```

``#!/bin/sh``: will export which path of shell to compile, some compiler bypass this command.

Can be both ``#!bin/sh`` and ``#!bin/bash``

Run a ``sh`` file: ``./test.sh``, ``/bin/bash test.sh``, ``. test.sh``, ``sh test.sh`` and ``source test.sh``.

A file with no ``sh`` extension but include Bash script file can be run normally.

If the shell script file is unable to run due to permission, use ``chmod``:

```cmd
chmod 775 hello.sh
./hello.sh
```

**Error**

Error when running ``test.sh``:

```
syntax error near unexpected token `$'{\r''
```

That error happen as there are mismatch when using new line

Fix: ``sed -i 's/\r//' test.sh``

## Positional parameters

Positional parameters is the way to handle with command line argument when running a bash script

```sh
echo "First argument $0"
echo "Second argument $1"
echo "Third argument $2"
echo "All argument $@"
echo "total number of parameter: $#"
```

**Run**: ``./test.sh 2nd 3rd all``

**Result**

```sh
First argument ./test.sh
Second argument 2nd
Third argument 3rd
All argument 2nd 3rd all //An array: {"2nd", "3rd", "all"}
total number of parameter: 3 //argument ./test.sh is not count
```

* ``$*``: Stores all the arguments that were entered on the command line (``$1``, ``$2``,...).
* ``$@``: Stores all the arguments that were entered on the command line, individually quoted ("$1" "$2" ...) as an array.

## Import file

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

## Export file

```sh
echo "$(<jsonData.json)"
```

```sh
echo "$(cat jsonData.json)"
```

## When should shell programming/scripting not be used ?

When the task is very much complex like writing the entire payroll processing system.

Where there is a high degree if productivity required.

When it needs or involves different software tools.

# Unix commands

## Bash script programming

* [Variable](Variable)
* [Function](Function.md)
* [Conditional statement](Conditional%20statement)
* [Operators](Operators.md)
* [Arithmetic expression]()
* [Data type]() and [Data structure]()
* [Searching]()
* [Text processing]()

## System operations

* [Build automation tools]()
* [Shell builtins commands](Shell%20builtins.md)
* [Install package](Install%20package.md)

## --help and man

```shell
$ ls --help
```

```shell
$ man ls
```

## bash command

``bash`` command will create a new shell, as the **subshell**, in the current running terminal.

Before running ``bash`` command, current terminal is already inside a shell, as the **parent shell**. After running ``bash``, a new subshell is created. The terminal now will enter that subshell. Calling ``exit`` command will exit the current terminal from that subshell and get back to the parent shell.

Variable scope with ``bash`` and shell:

```sh
username@hostname:~/$ a=4
username@hostname:~/$ echo $a #Variable a is in parent shell
4
username@hostname:~/$ bash
username@hostname:~/$ echo $a #Variable a is in subshell and has NULL value

username@hostname:~/$ exit #exit subshell
exit
username@hostname:~/$ echo $a #Back to parent shell, and variable a has its old value
4
```

## Miscellaneous commands

``Ctrl+D`` logs out of the interface (quite similar to Ctr+C to exit)

``which``: locate where a command is stored. 

**E.g**: ``which ls``: ``/bin/ls``

``exit``: Exit the current running terminal 

``type command_name``: information of that command. E.g ``type cd``: information of ``cd`` command

### Working with space

To work with a file containing space, like ``"Folder 1"``:

* Add ``" "`` in the command: E.g ``cd "Folder 1"``
* Add ``\`` in the command: E.g ``cd Folder\ 1/"``
