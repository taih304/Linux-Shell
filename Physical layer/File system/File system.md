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

### stat

``stat``: Display file or file system status.

E.g: ``stat folder_1``, ``stat test.txt``

## File archive

### zip and unzip

Zip several files: ``zip test.zip README.md document.md``

### unzip

Command ``unzip`` for ``unzipping`` files

### ar

``ar [OPTIONS] archive_name member_files``

**Options**:

* r: create

``ar r testFile.zip test1.c test2.c``: Zip two files ``test1.c``, ``test2.c`` into ``testFile.zip``

### tar

``tar``: saves many files together into a single tape or disk archive. ``tar`` is also a file extension.

``-c``: create a new archive

``-f``: use archive file or device ARCHIVE

Archive files to ``.tar`` file: ``tar -cf test.tar file1.md file2.md``

Extract files from a ``.tar`` file: ``tar -xf test.tar``

You can't archive or unarchive other types of file like ``.zip``, ``rar`` with ``tar``, ``tar`` can just arhive to ``.tar`` file.
