### ps

``ps``: Report process status

``ps ax | grep firefox``: Return nothing in Git Bash Windows

A C compile program (``a.out``) program will run as a process and can be listed in ``ps``

``pstree``: View the tree of running process

### kill

``kill``: send a signal to a process

``kill [options] <pid> [...]``

The  default  signal  for kill is ``TERM`` (terminate).

``kill 17375``: terminate process with PID ``17375``

``kill -l`` or ``kill -L``: To display all the available signals you can use below command option

### netstat

``netstat -tulpn``: Find out which process is listening upon a port