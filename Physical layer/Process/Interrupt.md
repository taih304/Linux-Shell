Interrupt is a response by the processor to an event that needs attention from the software. That event can be GPIO voltage level rising or falling, timer overflow,...

An interrupt condition alerts the processor and serves as a request for the processor to interrupt the currently executing code when permitted, so that the event can be processed in a timely manner.

If the request is accepted, the processor responds by suspending its current activities, saving its state, and executing a function called an interrupt handler (or an interrupt service routine, ISR) to deal with the event

## ISR

An **ISR** (Interrupt Service Routine) is an interrupt handler, a callback subroutine (i.e a function) which is called when an interrupt is encountered. ISR does not return anything. An ISR returns nothing because there is no caller in the software to read the returned values.

We can use function inside ISR as long as that function is not invoked from other portion of the code.

**Interrupt latency** is the time required for an ISR responds to an interrupt.

Interrupt latency can be minimized by writing short ISR routine and by not delaying interrupts for more time.

For implementation of ISR, check the corresponding document in C and other MCU repositories, like AVR Arduino framework.
