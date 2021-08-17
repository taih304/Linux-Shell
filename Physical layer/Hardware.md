* ``sudo lshw``: list system hardware information

All built-in hardware devices of the computer like touch pad, Power Button, Video bus,... are listed in ``/dev/input``. All those devices has ``id`` like ``event1``, ``event12``, ``event15``,...

To video the corressponding ID of the those devices: ``xinput``

``id=2`` corrresponds to ``event2``.