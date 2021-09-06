### cp

``cp``: Copy ``SOURCE`` to ``DEST``, or multiple ``SOURCE(s)`` to ``DIRECTORY``.

``cp test test_copy``: copy the file ``test`` to file/folder ``test_copy``. It will overwrite the content of file ``test_copy`` if existed or create ``test_copy`` if not exit. If folder ``test_copy`` exists, ``test`` will be copied inside.

Copy to folder can also end with ``/``: ``cp test test_copy/``

Copy a file to the current running terminal, i.e opening that file: ``cp test.c /dev/tty``

Copy input from the current running terminal to a file, i.e writing to that file: ``cp /dev/tty test.c``

### tee

Write content to a file

``tee filename``: Start writing the entered content from ``tty`` to ``filename``

``tee -a filename``: Appened the written content to ``filename``