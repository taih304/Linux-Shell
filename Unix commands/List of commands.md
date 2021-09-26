A list is a sequence of one or more pipelines separated by one of the operators ``;``, ``&``, ``&&``, or ``||``, and optionally terminated by one of ``;``, ``&``, or a newline.

Of these list operators, ``&&`` and ``||`` have equal precedence, followed by ``;`` and ``&``, which have equal precedence.

### &&

```sh
command1 && command2
```

``command2`` is executed if, and only if, command1 returns an exit status of ``0`` (success).

### ||

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

### ;

You can put two or more commands on the same line separated by the semicolon ``;``. All the arguments before ``;`` will be treated as a separate command from all the arguments after the ``;``. All the commands will be executed sequentially waiting for each command to finish before starting the new one.

```sh
command1 ; command2  
```

### : (colon)

The no-op command in shell is ``:`` (colon).

### & (comtrol operator)

If a command is terminated by the control operator ``&``, the shell executes the command asynchronously in a subshell. This is known as executing the command in the background, and these are referred to as asynchronous commands.

**Example**: ``ls &``

**Result**

```
username@hostname: [1] 20014
username@hostname: folder_1 folder_2
```