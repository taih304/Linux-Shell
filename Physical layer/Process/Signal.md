A signal is a notification to a process that an event has occurred. Signals are sometimes described as **software interrupts**. Signals are analogous to hardware interrupts in that they interrupt the normal flow of execution of a program; in most cases, it is not possible to predict exactly when a signal will arrive.
       
# kill

``kill``: send a signal to a process

``kill [options] <pid> [...]``

The  default  signal  for kill is ``TERM`` (terminate).

``kill 17375``: terminate process with PID ``17375``

``kill -12 12976`` or ``kill -USR2 12976``: Send USR2 signal to PID ``12976``

``kill -l``: display all the available signals
# trap as signal handler function
[trap](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Bash%20script/Conditional%20statement#trap) can be used to add signal function handler to any signal. This is corresponded to [signal()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Signal/API.md#signal) with ``signal_handler()`` function in C:
```sh
trap  "echo 'SIGINT is caught'" SIGINT
while ((1))
do
    sleep 1
done
exit 0
```
