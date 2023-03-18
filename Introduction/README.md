# OS overview

A 32-bit computer is the computer with totally 2^32 registers. 32-bit computer doesn't mean all of its registers are 32-bit.

An OS in general does 3 main work:

* Process management
* Memory management
* Scheduling

**Scheduling**: The scheduler determines which task to execute. There are few mechanisms controlling access to CPU for tasks (timeslice, preemption, idle)

In computing, a **system image** is a serialized copy of the entire state of a computer system stored in some non-volatile form such as a file. This can be an OS image, disk image and process image.

# RTOS

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

## Embedded Linux

Embedded Linux is the usage of the Linux kernel and various open-source components in embedded systems.

**Embedded Linux vs Desktop Linux**

Desktop Linux are Ubuntu, Gentoo, Debian,... But these Dekstop Linux are not well suited for embedded system.

EMAC OE linux is an Embedded Linux. EMAC OE is EMAC's standard Linux distribution, based on the OpenEmbedded build framework for embedded Linux systems.

**Main components of a Linux embedded system**

* **Bootloader**
* **Kernel**
* **System call interface**
* **C-Runtime library**
* **System shared libraries** 
* **Root filesystem**