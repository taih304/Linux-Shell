# Archive vs compression

**Compression** will reduce the file size.

**Archive** just simply packing all the files into an archive object like ``tar``. The newly archived file will have its size less than the total size of all packed files by just a few memory.

A GZ file (``.gz``) is an archive file compressed by the standard GNU zip (``gzip`` command) compression algorithm. ``gzip`` is primarily used on Unix operating systems for file compression.

# Commands

## zip

Zip several files: ``zip test.zip README.md document.md``

## unzip

Command ``unzip`` for ``unzipping`` files

## unrar

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

## ar

``ar`` - create, modify, and extract from archives

``ar [OPTIONS] archive_name member_files``

**Options**:

* ``r``: Insert several file members into the zipped file

``ar r archive_file test1.c test2.c``: ``Archive`` two files ``test1.c``, ``test2.c`` into ``archive_file``. ``archive_file`` will be automatically created if not existed.

* ``x``: Extract file

``ar x archive_test``

## tar

``tar``: saves many files together into a single tape or disk archive. ``tar`` is also a file extension. The tar archived file is called a **tarball**.

``-c``: create a new archive

``-f``: use archive file or device ARCHIVE

Archive multiple files to a ``.tar`` file: ``tar -cf test.tar file1.md file2.md``

Extract files from a ``.tar`` file: ``tar -xf test.tar``

``tar`` can be used to extract ``tgz`` file: E.g: ``tar -xf p4v.tgz``

For ``.gz`` file: ``tar -xzvf gz_file.tar.gz``. If not using ``-xzvf``, ``.gz`` file can't be extracted.

You can't archive or unarchive other types of file like ``.zip``, ``rar`` with ``tar``, ``tar`` can just archive to ``.tar`` file.

## gzip and gunzip

``gzip`` will compress the files "in place", i.e, the original file will be replaced by the compressed file.

``gzip main.c main.cpp`` will result in ``main.c.gz`` and ``main.cpp.gz``.

``gunzip``: ``gunzip main.cpp.gz`` will result in ``main.cpp``

## Searching the compressed file

[zgrep](../../Bash%20script/Searching.md#zgrep) and [zipgrep](../../Bash%20script/Searching.md#zipgrep) are used for searching inside the compressed files, check their implementation in [Bash search]().

## zcat

``zcat`` is used view the content inside a compressed file.

```sh
zcat test.zip
```
If you run ``zcat`` to view the compressed file that contains the multiple files, it will only show one file ignoring the rest of the files, and also displays this notice:

```
gzip: test.zip has more than one entry--rest ignored
```
