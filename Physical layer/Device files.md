``/dev`` is the location of special or device files.

``/dev/tty`` is the current running terminal.

``/dev/pts`` stores all number of the current opening terminal. Choosing the right terminal number will output data to the right terminal.

E.g:

If the current opening terminal has ``pts`` number is ``4`` then ``echo Hello, World ! > /dev/pts/4`` will print out ``Hello, World !`` to this terminal.

``/dev/input`` lists all built-in hardware devices of the computer like touch pad, Power Button, Video bus,... All those devices has ``id`` like ``event1``, ``event12``, ``event15``,...

To view the corressponding ID of the those devices: ``xinput``

``id=2`` corrresponds to ``event2``.