## File descriptors

``/dev/fd``: for each process, the kernel provides the special virtual directory ``/dev/fd``. This directory contains filenames of the form ``/dev/fd/n``, where ``n`` is a number corresponding to one of the open file descriptors for the process. ``/dev/fd`` is actually a symbolic link to the Linux-specific ``/proc/self/fd`` directory.

``/dev/fd/0``, ``/dev/fd/1`` and ``/dev/fd/2`` are corresponded to ``stdin`` and ``stdout`` and ``stderr``. 

As a convenience, the names ``/dev/stdin``, ``/dev/stdout``, and ``/dev/stderr`` are provided as symbolic links to, respectively, ``/proc/self/fd/0``, ``/proc/self/fd/1``, and ``/proc/self/fd/2``.

By default, ``ls dev/fd`` will return ``0 1 2 3``. If there is a running program with an opened fd is ``4``, run ``ls dev/fd`` won't return that value

## Terminal

``/dev/tty`` is the current running terminal, which is character special.

``tty`` command will print out the file name of the terminal connected to standard input. E.g: ``tty`` returns ``/dev/pts/19``

``/dev/pts`` stores all number of the current opening terminal. Choosing the right terminal number will output data to the right terminal.

E.g:

If the current opening terminal has ``pts`` number is ``4`` then ``echo Hello, World ! > /dev/pts/4`` will print out ``Hello, World !`` to this terminal.

## Input

``/dev/input`` lists all built-in hardware devices of the computer like touch pad, Power Button, Video bus,... All those devices has ``id`` like ``event1``, ``event12``, ``event15``,... All are character special.

To view the corressponding ID of the those devices: ``xinput``

``id=2`` corrresponds to ``event2``.

To view all major and minor number of input: ``ls -l /dev/input``

```
crw-rw---- 1 root input 13, 64 Feb  5 10:15 event0
crw-rw---- 1 root input 13, 65 Feb  5 10:15 event1
```

Then ``13`` is major number, ``64`` and ``65`` are minor numbers.

## Memory

``/dev/mem`` is a character device file that is an image of the main memory of the computer.  It may be used, for example, to examine (and even patch) the system. Byte addresses in ``/dev/mem`` are interpreted as physical memory addresses.
