A list is a sequence of one or more pipelines separated by one of the operators ``;``, ``&``, ``&&``, or ``||``, and optionally terminated by one of ``;``, ``&``, or a newline.

Of these list operators, ``&&`` and ``||`` have equal precedence, followed by ``;`` and ``&``, which have equal precedence.

### Multiple command with semicolon ``;``

You can put two or more commands on the same line separated by the semicolon ``;``. All the arguments before ``;`` will be treated as a separate command from all the arguments after the ``;``. All the commands will be executed sequentially waiting for each command to finish before starting the new one.

```sh
command1 ; command2  
```

### ``:`` (colon)

The no-op command in shell is ``:`` (colon).

### ``&`` (comtrol operator)

If a command is terminated by the control operator ``&``, the shell executes the command asynchronously in a subshell. This is known as executing the command in the background, and these are referred to as asynchronous commands.

**Example**: ``ls &``

**Result**

```
username@hostname: [1] 20014
username@hostname: folder_1 folder_2
```