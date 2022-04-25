**Shell** is a command interpreter, which interprets the command which the user gives to the kernel. It can also be defined as an interface between a user and operating system. A separate compiler is not required to execute a shell program. The shell itself interprets the command in the shell program and executes them.

Linux based operating system uses **Bash shell**, the shell environment used for several purposes like storing data, storing software configuration, locating terminal settings and changing shell environments.

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
