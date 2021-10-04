In Linux 2.4 and earlier, the process ID limit of ``32,767`` is defined by the kernel constant ``PID_MAX``. With Linux 2.6, things change. While the default upper limit for process IDs remains ``32,767``, this limit is adjustable via the value in the Linux-specific ``/proc/sys/kernel/pid_max`` file (which is one greater than the maximum process ID).

Information of a process can be viewed in file ``/proc/PID/status``. E.g: 

View status of process ``16965``: ``cat /proc/16965/status``
