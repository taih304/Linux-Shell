# ipcs

``ipcs``: Show information on System V IPC. Those info include:

* ``-m``: Shared memory segments
* ``-q``: Queues
* ``-s``: Semaphores

By default, with no message queues, shared memory segments and semaphore arrays created, ``ipcs`` will be like this:

```
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages            

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 425984     tranphucvi 600        524288     2          dest         
0x00000000 720897     tranphucvi 600        16777216   2                       
0x00000000 884738     tranphucvi 600        524288     2          dest         
0x00000000 1409027    tranphucvi 600        524288     2          dest         
0x00000000 688132     tranphucvi 600        524288     2          dest         
0x00000000 1114117    tranphucvi 600        134217728  2          dest         
0x00000000 1015814    tranphucvi 600        524288     2          dest         
0x00000000 1212423    tranphucvi 600        524288     2          dest         
0x00000000 1310728    tranphucvi 600        524288     2          dest         
0x00000000 1638409    tranphucvi 600        524288     2          dest         
0x00000000 1671178    tranphucvi 600        4194304    2          dest         
0x00000000 1703947    tranphucvi 600        33554432   2          dest         
0x00000000 1933324    tranphucvi 600        524288     2          dest         
0x00000000 1966093    tranphucvi 600        67108864   2          dest         
0x00000000 4751374    tranphucvi 600        524288     2          dest         
0x00000000 4784143    tranphucvi 600        4194304    2          dest         

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
```

# ipcrm

``ipcrm -q id``: Delete an existed message queue with ``id``, check [message queue example for that implementation](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Process/Message%20queue/Implementations.md#remove-a-message-queue)
