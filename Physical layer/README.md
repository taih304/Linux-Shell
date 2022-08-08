# OS overview

A 32 bit computer is the computer with totally 2^32 registers. 32-bit register doesn't mean it must have 32-bit register.

An OS in general does 3 main work:

* Process management
* Memory management
* Scheduling

**Scheduling**: The scheduler determines which task to execute. There are few mechanisms controlling access to CPU for tasks (timeslice, preemption, idle)

## RTOS

RTOS is an OS for realtime application as well as it gives realtime response to its related events. That happens as scheduler inside the RTOS takes a very short time when switching between the tasks/context switching which makes us feel like the RTOS has realtime response to the events.

The RTOS also has short latency when handling with interrupt, as well as having reliable and timebound when doing inter-task communication.

**Schedule**

RTOS uses pre-emptive scheduling. In pre-emptive scheduling, the higher priority task can interrupt a running process and the interrupted process will be resumed later.

**Inter-task Communication**

* Signal Events: Synchronize between tasks
* Message queue: Exchange message between tasks, acting like FIFO
* Mail queue: Exchange data between tasks, using queue

**Resource Sharing**:

* Semaphores: Accessing resource continuously from multiple tasks
* Mutex: Synchronize resource accessing using Mutual Exclusion

# Linux overview

## Linux booting process

Linux booting process will follow those steps:

* BIOS: System startup/Hardware init
* Bootloader stage 1: Master Boot Record (MSB) executes GRUB
* Bootloader stage 2: GRUB executes Kernel
* Kernel will executes process init located in ``/sbin/init``
* Execute ``init`` process
* Run level: Start userspace for command line

## Shell

In computing, a **shell** is a computer program which exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

Whenever we run any command in a Bash shell, a **subshell** is created by default, and a new child process is spawned (forked) to execute the command. 

## GUI setup

```bash
username$hostname #One host name can include many user_name
```

``Ctrl+Alt+F1`` to ``Ctrl+Alt+F6``: enter terminal from ``tty1`` to ``tty6``, which is also known as text terminal.

``Ctrl+Alt+F7``: switch back to desktop and terminal ``tty``.

### screen

The ``screen`` package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

To end ``screen``: ``Ctr+A+D``.

### Other commands

``xrandr --size 1366x768``: Change size of current screen to ``1366x768``

``\033[8;h;wt`` can be used to change the size of the current running terminal. ``\033`` is the ASCII control character ``ESC``, and ``h`` and ``w`` are height and width in decimal.

```sh
printf '\033[8;64;240t' #must have ''
```

## System handler

``less /proc/cpuinfo``: View CPU info

The ``/sys/class/`` directory offers a view of the device drivers grouped by classes.

``cat /sys/class/thermal/thermal_zone0/temp``: read temperature on Linux


* ``shutdown``
* ``reboot``
* ``cat /etc/os-release``: View OS information

Name of OS:

* ``uname``: Name of OS
* ``uname -v``: Name of Kernel version. E.g: ``#82-Ubuntu SMP Fri Sep 4 12:23:10 UTC 2020``

* ``sudo lshw``: list system hardware information

### Program run at specific time

To let a program run in a specific time or when just start up: ``sudo crontab -e``

**Example**

```shell
		#                    m     h     dom    mon     dow     command
(every 5 minutes)       */5					                      /bin/bash  /home/....(path to shell program)									
(every 10 minutes)      */10
run when start up	       @reboot
```

**Example**

Make program ``blink.sh`` run when computer reboot

```
# For example, you can run a backup of all your user accounts
# at 5 a.m every week with:
# 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
#
# For more information see the manual pages of crontab(5) and cron(8)
#
# m h  dom mon dow   command
@reboot /bin/bash /home/pi/test/blink.sh  #1 space after /bin/bash
```

``/bin/bash`` is for bash shell

* ``m``: minute
* ``h``: hour
* ``dom``: day of month
* ``dow``: day of week

## Error IUSE 100% in CentOS

If error happen, CentOS will not allow user to ``yum install`` more file.

Problem solved: ``sudo rm -rf /var/cache/*``
