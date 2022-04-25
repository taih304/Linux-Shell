# Environment Variable

## Local Environment Variable

These environment variables last only till the current session.

To add or modify a local environment variable, use ``export``

``export a=4``

Check this environment variable: ``echo $a``

### set command

``set`` command is a built-in shell command that allows you to display or set both shell and environment variables.

Without any arguments, the ``set`` command lists all the shell variables, including their values.

With argument:

```sh
username@hostname:set a b c
username@hostname:echo $1 $2 $3
a b c
```

### PATH

``PATH`` is an environmental variable in Linux and other Unix-like operating systems that tells the shell which directories to search for executable files (i.e., ready-to-run programs) in response to commands issued by a user. Multiple values for an environment variable are seperated by a ``:``

## User Environment Variable

These are the variables which are defined for a particular user and are loaded every time a user logs in using a local terminal session. These variables are typically set in and loaded from following configuration files: ``.bashrc``, ``.bash_profile``, ``.bash_login``, ``.profile`` files which are present in user’s home directory.

**Configuration files**

``.bashrc``:  This file is user specific file that gets loaded each time user creates a new local session i.e. opens a new terminal. All environment variables created in this file would take effect every time a new local session is started. To activate the change after setting up the environment variable, reboot the system or run ``source ~/.bashrc``.

``.bash_profile``: This file is user specific remote login file. Environment variables listed in this file are invoked every time the user is logged in remotely i.e. using ssh session. 

## System wide Environment Variables

These are the environment variables which are available system-wide, i.e. for all the users present on that system. These variables are present in system-wide configuration files present in following directories and files: ``/etc/environment``, ``/etc/profile``, ``/etc/profile.d/``, ``/etc/bash.bashrc``. These variables are loaded every time system is powered on.

Update the ``PATH`` to the environment variable in file ``/etc/bash.bashrc``. For example:

```sh
export PATH=$HOME/ESP8266-Toolchain-217/compiler/crosstool-NG/builds/xtensa-lx106-elf/bin:$PATH
```

If setting the wrong ``PATH`` (as Local Environment Variable or System wide variables), like this:

```sh
#This is a wrong PATH
export PATH=~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/
```

(Must be this: ``export PATH=~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin:$PATH``)

Then this wrong PATH will effect all built-in commands like ``ls``, ``cd``, ``cat``,... 

Error: ``ls: command not found``

To view all environment variables, use ``export`` or ``env`` command.
