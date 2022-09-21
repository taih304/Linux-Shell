## Fundamental concepts

**Shell** is a command interpreter, which interprets the command which the user gives to the kernel. It can also be defined as an interface between a user and operating system. A separate compiler is not required to execute a shell program. The shell itself interprets the command in the shell program and executes them.

Linux based operating system uses **Bash shell**, the shell environment used for several purposes like storing data, storing software configuration, locating terminal settings and changing shell environments.

### Basic shell script

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

Run a ``sh`` file: ``./test.sh``, ``. test.sh``, ``sh test.sh`` and ``source test.sh``.

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

### When should shell programming/scripting not be used ?

When the task is very much complex like writing the entire payroll processing system.

Where there is a high degree if productivity required.

When it needs or involves different software tools.

## Unix commands

* [Operators](Operators.md)
* [Shell builtins commands](Shell%20builtins.md)
* [Install package](Install%20package.md)

### --help

```shell
$ ls --help
```

```shell
$ man ls
```

### Miscellaneous commands

``Ctrl+D`` logs out of the interface (quite similar to Ctr+C to exit)

``which``: locate where a command is stored. 

**E.g**: ``which ls``: ``/bin/ls``

``exit``: Exit the current running terminal 

**When working with space**

To work with a file containing space, like ``"Folder 1"``:

* Add ``" "`` in the command: E.g ``cd "Folder 1"``
* Add ``\`` in the command: E.g ``cd Folder\ 1/"``
