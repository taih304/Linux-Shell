Root folder ``/`` contains those folder:

* ``home``: User directories
* ``boot``: For booting system
* ``sbin``: System file
* [bin](#bin):  Commands and programs
* [usr](#usr): Application files
* [var](#var): Variable files
* [dev](dev.md)
* [etc](etc.md): Configuration files
* ``opt``: Optional
* [tmp](#tmp)

# bin

Directory ``bin`` stores all the command line used in Linux

Example: [Set up command from a C process by using the /bin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).

# var

``sudo cat /var/log/syslog``: View all system log, like ``crontab``, ``systemctl``

# usr

* ``/usr/local/bin`` and ``/usr/sbin``: [Set up command from a C process by using the /usr/local/bin or /usr/sbin directory](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#linux-environment).
* ``/usr/lib``: Store program libraries. Example: [Shared library (.so file)](https://github.com/TranPhucVinh/C/blob/master/Environment/Shared%20library.md)

# tmp

In Unix and Linux, the global temporary directories are ``/tmp`` and ``/var/tmp`` where temporary files of the running program are stored here. However, files created by user in those locations are not temporary as they are still in there and can still keep the value after the OS is powered off.

The [tmpfs]() filesystem is used for managing the ``/tmp`` directory.

# ~/.local

Trash folder are located under ``~/.local/share/Trash``
