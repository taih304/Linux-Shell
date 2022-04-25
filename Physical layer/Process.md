## Process

Information of a process can be viewed in file ``/proc/PID/status``. E.g: 

View status of process ``16965``: ``cat /proc/16965/status``

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
