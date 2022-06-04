# Virtual memory

## Fundamental concepts

Virtual memory is a section of volatile memory created temporarily on the storage drive. It is created when a computer is running many processes at once and RAM is running low.

The OS’s process abstraction provides each process with a virtual memory space so address of a variable inside a process is virtual address.

Because processes operate within their own virtual address spaces, operating systems must make an important distinction between two types of memory addresses.
Virtual addresses refer to storage locations in a process’s virtual address space, and physical addresses refer to storage locations in physical memory (RAM).

Swapping is the process the OS uses to move data between RAM and virtual memory. The OS moves data from processes that are not immediately needed out of the RAM and stores them in virtual memory. It copies the data back into RAM when the process is needed again. Using virtual memory slows the computer down because copying to a hard disk takes much longer than reading and writing RAM.
