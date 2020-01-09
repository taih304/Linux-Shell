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
