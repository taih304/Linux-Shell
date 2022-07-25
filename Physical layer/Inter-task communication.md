### Race condition

A race condition is a situation where the result produced by two processes (or threads) operating on shared resources depends in an unexpected way on the relative order in which the processes gain access to the CPU(s).

### Semaphore fundamental concepts

Semaphore is a technique to manage concurrent threads by using an integer value, which is known as a semaphore. The semaphore number is shared between thread to achieve synchronization in the multithread environment.

The semaphore number can be accessed only through â standard atomic operations ``wait()`` and ``signal()``.

For ``wait()``,  it is used **to test**:

```c
wait() (semphamore_variable S){
	while (S)
	; //No operation
	S--;
}
```

For ``signal()``, it is used **to increment**:

```c
signal(semphamore_variable S){
	S++;
}
```

Types of semaphore:

1. Binary semaphore: Semaphore with value can range only ``0`` and ``1``. In some systems, binary semaphores are known as mutex locks, as they are locks that provide mutual exclusions.
2. Counting semaphore: Semaphore with value can range over an unrestricted domain. Counting semaphores that are used to manage resources are created so that their initial count value equals the number of resources that are available. To obtain control of a resource, a task must first obtain a semaphore—decrementing the semaphore’s count value. When the count value reaches zero, there are no free resources. When a task finishes with the resource, it ‘gives’ the semaphore back incrementing the semaphore’s count value. 