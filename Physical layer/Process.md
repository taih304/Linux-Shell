## Process

Information of a process can be viewed in file ``/proc/PID/status``. E.g: 

View status of process ``16965``: ``cat /proc/16965/status``

``echo $$``: Print out the ``PID`` of the current running shell

``echo $PPID`` or ``ps -e | grep $PPID``: Print out the parent process of the current running shell

### ps

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

### pstree

``pstree`` will view the tree of running process

View process tree of a specific proccess, like ``2029``:  ``pstree -p 2029``

### pgrep and  pkill 

``pgrep``, ``pkill``: look  up  or signal processes based on name and other attributes
       
### kill

``kill``: send a signal to a process

``kill [options] <pid> [...]``

The  default  signal  for kill is ``TERM`` (terminate).

``kill 17375``: terminate process with PID ``17375``

``kill -12 12976`` or ``kill -USR2 12976``: Send USR2 signal to PID ``12976``

``kill -l``: display all the available signals

### netstat

``netstat -tulpn``: Find out which process is listening upon a port

## Job

In computing, a **job** is a unit of work or unit of execution. A component of a job (as a unit of work) is called a task or a step (if sequential, as in a job stream). As a unit of execution, a job may be concretely identified with a single process.

To run a job **in the background**, use [ampersand symbol (&)](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Unix%20commands/List%20of%20commands.md#-control-operator)

``jobs`` command will list the jobs that are currently running or suspended in the background.

E.g:

```
username$hostname:~/pwd$$ jobs
[1]-  Stopped                 ./a.out
[2]+  Stopped                 ./a.out
```

``fg`` brings a background job to the foreground.

E.g:

```sh
fg % 1 #job ID 1 from [1] of ./a.out
```

``Control+Z`` keys and ``bg`` command bring a job to the background.

E.g:

```sh
bg % 1
```
