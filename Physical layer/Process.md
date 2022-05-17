## Fundamental concepts

A process is an instance of a program in execution. We called this an ‘instance of a program’, because if the same program is run lets say 10 times then there will be 10 corresponding processes. A process execution includes one or many threads. It contains the program code and its activity. Depending on the operating system (OS), a process may be made up of multiple threads of execution that execute instructions concurrently.

A C compile program (``a.out``) program will run as a process and can be listed in ``ps`` and has the ``PPID`` (parent process ID) of that terminal.

Each process has a parent - the process that created it. The parent of each process has its own parent, and so on, going all the way back to process 1, ``init``, the ancestor of all processes. This “family tree” can be viewed using the ``pstree()`` command.

### Process ID

In Linux 2.4 and earlier, the Linux kernel limits process IDs to being less than or equal to ``32,767``. the process ID limit of ``32,767`` is defined by the kernel constant ``PID_MAX``. With Linux 2.6, things change. While the default upper limit for process IDs remains ``32,767``, this limit is adjustable via the value in the Linux-specific ``/proc/sys/kernel/pid_max`` file (which is one greater than the maximum process ID).

When a new process is created, it is assigned the next sequentially available process ID. Each time the limit of ``32,767`` is reached, the kernel resets its process ID counter so that process IDs are assigned starting from low integer values. 

Once it has reached ``32,767``, the process ID counter is reset to 300, rather than 1. This is done because many low-numbered process IDs are in permanent use by system processes and daemons, and thus time would be wasted searching for an unused process ID in this range.

### Stages of a Linux process

* Waiting: Process wait for resource
* Running: Process is currently being executed
* Stopped: Process is stopped after successful execution
* Zombie: Process has stopped but still active in the process table

### View process information

Information of a process can be viewed in file ``/proc/PID/status``. E.g: 

View status of process ``16965``: ``cat /proc/16965/status``

``echo $$``: Print out the ``PID`` of the current running shell

``echo $PPID`` or ``ps -e | grep $PPID``: Print out the parent process of the current running shell

## Process commands

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

### exec

Whenever we run any command in a Bash shell, a subshell is created by default, and a new child process is spawned (forked) to execute the command. When using ``exec``, however, the command following exec replaces the current shell. This means no subshell is created and the current process is replaced with this new command.

E.g: When starting terminal 1, it will have a PID, e.g ``1234``. In terminal 2, that PID can be listed out with ``ps aux``

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

Then running ``test.sh`` won't exit the current running shell.

## Jobs

A job is a process that the shell manages. Each job is assigned a sequential job ID. Because a job is a process, each job has an associated PID. There are three types of job statuses:

1. **Foreground**: When you enter a command in a terminal window, the command occupies that terminal window until it completes. This is a foreground job.
2. **Background**: When you enter use [ampersand symbol (&)](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Unix%20commands/List%20of%20commands.md#-control-operator) at the end of a command line, the command runs without occupying the terminal window.
3. **Stopped**: If you press Control + Z for a foreground job, or enter the stop command for a background job, the job stops. 

To run a job **in the background**, 
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
