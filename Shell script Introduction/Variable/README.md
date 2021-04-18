## Environment Variable

``set``: List all environment variables stored in the shell

``PATH`` is an environmental variable in Linux and other Unix-like operating systems that tells the shell which directories to search for executable files (i.e., ready-to-run programs) in response to commands issued by a user. Multiple values for an environment variable are seperated by a ``:``

### Local Environment Variable

To add or modify a local environment variable, use ``export``

``export a=4``

Check this environment variable: ``echo $a``

### User wide variables

To activate the change after setting up the environment variable, reboot the system or run ``source ~/.bashrc``

### System wide variables

Update the ``PATH`` to the environment variable in file ``/etc/bash.bashrc``. For example:

```sh
export PATH=$HOME/ESP8266-Toolchain-217/compiler/crosstool-NG/builds/xtensa-lx106-elf/bin:$PATH
```