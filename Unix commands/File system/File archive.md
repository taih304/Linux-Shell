# Archive vs compression

**Compression** will reduce the file size.

**Archive** just simply packing all the files into an archive object luke tar, zip. The newly archived file will have its size less than the total size of all packed file by just a few memory.

# Commands

### zip

Zip several files: ``zip test.zip README.md document.md``

### unzip

Command ``unzip`` for ``unzipping`` files

### unrar

**Error**``unrar`` or ``Extract here`` give empty folder

That happens as Ubutnu is using ``unrar-free``.

Check: ``dpkg --list | grep unrar``

Give:

```
ii  unrar-free                                  1:0.0.1+cvs20140707-4~build0.16.04.1            amd64        Unarchiver for .rar files
```

**Problem solve**: Uninstall ``unrar-free`` and install ``unrar`` 

```sh
sudo apt-get remove unrar-free -y && sudo apt-get install unrar -y
```
Check: ``dpkg --list | grep unrar``

Give:

```
ii  unrar                                       1:5.3.2-1+deb9u1build0.16.04.1                  amd64        Unarchiver for .rar files (non-free version)
```

The ``Extract here`` for ``rar`` files will be available, extracted folder will not be empty. 

### ar

``ar [OPTIONS] archive_name member_files``

**Options**:

* r: create

``ar r testFile.zip test1.c test2.c``: Zip two files ``test1.c``, ``test2.c`` into ``testFile.zip``

### tar

``tar``: saves many files together into a single tape or disk archive. ``tar`` is also a file extension.

``-c``: create a new archive

``-f``: use archive file or device ARCHIVE

Archive multiple files to a ``.tar`` file: ``tar -cf test.tar file1.md file2.md``

Extract files from a ``.tar`` file: ``tar -xf test.tar``

``tar`` can be used to extract ``tgz`` file: E.g: ``tar -xf p4v.tgz``

For ``.gz`` file: ``tar -xzvf fovio_client.tar.gz``. If not using ``-xzvf``, ``.gz`` file can't be extracted.

You can't archive or unarchive other types of file like ``.zip``, ``rar`` with ``tar``, ``tar`` can just archive to ``.tar`` file.
