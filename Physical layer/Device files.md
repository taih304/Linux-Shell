``/dev`` is the location of special or device files.

``/dev/tty`` is the current running terminal.

All built-in hardware devices of the computer like touch pad, Power Button, Video bus,... are listed in ``/dev/input``. All those devices has ``id`` like ``event1``, ``event12``, ``event15``,...

To view the corressponding ID of the those devices: ``xinput``

``id=2`` corrresponds to ``event2``.