### Basic shell script

```sh
#!/bin/sh
echo "hello world"
```

``#!/bin/sh``: will export which path of shell to compile, some compiler bypass this command.

Can be both ``#!bin/sh`` and ``#!bin/bash``

**Run shell script**

```cmd
chmod 775 hello.sh
./hello.sh
```

``chmod`` might not need if the file is readable

Run shell script from another place, example: ``. ./windows-batch/test.sh`` (run ``test.sh`` inside the subfolder ``windows-batch``)

### Multiple command with semicolon ``;``

You can put two or more commands on the same line separated by the semicolon ``;``. All the arguments before ``;`` will be treated as a separate command from all the arguments after the ``;``. All the commands will be executed sequentially waiting for each command to finish before starting the new one.

```sh
command1 ; command2  
```

### ``:`` (colon)

The no-op command in shell is ``:`` (colon).

### ``&``

The ``&`` makes the command run in the background.

**Example**: ``ls &``

**Result**

```
username@hostname: [1] 20014
username@hostname: folder_1 folder_2
```
