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

### Semicolon ;

You can put two or more commands on the same line separated by the semicolon. All the arguments before (;) will be treated as a separate command from all the arguments after the (;). All the commands will be executed sequentially waiting for each command to finish before starting the new one.

```sh
command1 ; command2  
```