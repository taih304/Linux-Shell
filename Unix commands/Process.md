### ps

``ps``: Report process status

Help with specific details: ``ps --help <simple|list|output|threads|misc|all>`` or ``ps --help <s|l|o|t|m|a>``

``ps ax | grep firefox``: Return nothing in Git Bash Windows

A C compile program (``a.out``) program will run as a process and can be listed in ``ps``

``pstree``: View the tree of running process

### kill

``kill``: send a signal to a process

``kill [options] <pid> [...]``

The  default  signal  for kill is ``TERM`` (terminate).

``kill 17375``: terminate process with PID ``17375``

``kill -l``: To display all the available signals

### netstat

``netstat -tulpn``: Find out which process is listening upon a port