### df

``df [OPTION] [FILE]``: Show information about the file system on which each FILE resides, or all file systems by default.

* ``df -h``: list size of hardware, and usage of percentage
* ``df -i``: list all inode

### du

`` du [OPTION] [FILE]``: Summarize disk usage of the set of FILEs, recursively for directories.

* ``du -h``: list out disk usage in MB
* ``sudo du -h --max-depth=1``: list the size of all file and folder in current directory

### printenv

``printenv``: Print out all environment variable

## File archive

### zip and unzip

Command: ``unzip``, ``zip`` for ``zipping`` and ``unzipping`` files

### ar

``ar [OPTIONS] archive_name member_files``

**Options**:

* r: create

``ar r testFile.zip test1.c test2.c``: Zip two files ``test1.c``, ``test2.c`` into ``testFile.zip``
