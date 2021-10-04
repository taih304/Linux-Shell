``echo $$``: Print out the ``PID`` of the current running shell

``echo $PPID`` or ``ps -e | grep $PPID``: Print out the parent process of the current running shell

### ps

``ps``: Report process status

``-e``: See every process on the system

E.g: ``ps -e | grep $PPID``: Find the parent process of the current running shell

``-o``: User-defined format.

E.g: ``ps -o ppid= -p 9801``: Find the parent process of process ``9801``

Running ``ps`` return:

```
  PID TTY          TIME CMD
16965 pts/19   00:00:00 bash
18739 pts/19   00:00:00 ps
```

Help with specific details: ``ps --help <simple|list|output|threads|misc|all>`` or ``ps --help <s|l|o|t|m|a>``

``ps ax | grep firefox``: Return nothing in Git Bash Windows

A C compile program (``a.out``) program will run as a process and can be listed in ``ps``

``pstree``: View the tree of running process

### kill

``kill``: send a signal to a process

``kill [options] <pid> [...]``

The  default  signal  for kill is ``TERM`` (terminate).

``kill 17375``: terminate process with PID ``17375``

``kill -l``: display all the available signals

### netstat

``netstat -tulpn``: Find out which process is listening upon a port
