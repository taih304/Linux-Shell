# ps

``ps``: Report process status

``-e``: List all process on the system

``-f``: Full-format listing

E.g: ``ps -e | grep $PPID``: Find the parent process of the current running shell

``-o``: User-defined format.

E.g: ``ps -o ppid= -p 9801``: Find the parent process of process ``9801``

Running ``ps`` return:

```
  PID TTY          TIME CMD
16965 pts/19   00:00:00 bash
18739 pts/19   00:00:00 ps
```

``ps ax | grep firefox``: Return nothing in Git Bash Windows

# pstree

``pstree`` will view the tree of running process

View process tree of a specific proccess, like ``2029``:  ``pstree -p 2029``

# pgrep and pkill 

``pgrep``, ``pkill``: look  up  or signal processes based on name and other attributes

# netstat

``netstat -tulpn``: Find out which process is listening upon a port

# exec

``exec`` command executes a command from the bash itself. 

Whenever we run any command in a Bash shell, a subshell is created by default, and a new child process is spawned (forked) to execute the command. When using ``exec``, however, the command following exec replaces the current shell. This means no subshell is created and the current process is replaced with this new command.

E.g: When starting terminal 1, it will have a PID, e.g ``9001``. In terminal 2, that PID can be listed out with ``ps aux``

```
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
tranphu+  9001  0.0  0.0  24288  5256 pts/18   Ss   21:36   0:00 bash
```

With any command we do in terminal 1, like ``sleep 10``, its command ``bash`` is still unchanged.

However, if we use ``exec sleep 10`` in terminal 1, then in terminal 2 ``ps aux``, the result will be:

```
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
tranphu+  9001  0.0  0.0  24288  5256 pts/18   Ss   21:36   0:00 sleep 10
```

That happens as no subshell is created in terminal 1, it now is replaced by command ``sleep`` instead ``bash``.

With ``exec sleep 10``, after 10 seconds of sleep, the current shell will be closed as its execution has completed.

If ``exec`` is inside ``test.sh`` like this:

```sh
exec ls
```

Then running ``test.sh`` won't exit the current running shell. That happen as running ``test.sh`` will create a new shell in the current running terminal.

To stop quitting the current terminal when running ``exec ls``, add ``bash`` before it:

```sh
$ bash
$ exec ls
```

That happen as running ``bash``  will create a new shell in the current running terminal.

# $! for PID of background process

``$!`` returns the PID of the latest program run in the background

```
username@hostname:~$ ls&
[1] 466
username@hostname:~$ file_1.txt file_2.txt
^C
[1]+  Done                    ls --color=auto
username@hostname:~$ echo $!
466
```
