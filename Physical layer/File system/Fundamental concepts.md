A **filesystem** is the methods and data structures that an operating system uses to keep track of files, control how data is stored and retrieved on a disk or partition; that is, the way the files are organized on the disk. The word is also used to refer to a partition or disk that is used to store the files or the type of the filesystem. Thus, one might say **I have two filesystems** meaning one has two partitions on which one stores files, or that one is using the **extended filesystem**, meaning the type of the filesystem.

Without a file system, data placed in a storage medium would be one large body of data with no way to tell where one piece of data stops and the next begins.

File systems can be used on **numerous different types of local storage devices** that use different kinds of media, like **hard disk drives**. For example, the **ISO 9660** file system is designed specifically for **optical discs**. In some cases, such as with [tmpfs](File%20system%20types.md#tmpfs), RAM (random-access memory) is used to create a temporary file system for short-term use.

Some file systems also provide **file access via a network protocol** (for example, **NFS**, **SMB**, or **9P clients**). Some file systems are **virtual**, meaning that the supplied "files" (called virtual files) are computed on request (such as [procfs](File%20system%20types.md#procfs) and [sysfs](File%20system%20types.md#sysfs)) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files.

# Filesystem architecture

A file system consists of two or three layers. Sometimes the layers are explicitly separated, and sometimes the functions are combined.

The **logical file system** is responsible for interaction with the user application. It provides the application program interface (API) for file operations — OPEN, CLOSE, READ, etc., and passes the requested operation to the layer below it for processing. The logical file system manage open file table entries and per-process file descriptors". This layer provides "file access, directory operations, security and protection".

The second optional layer is the **virtual file system**. "This interface allows support for multiple concurrent instances of physical file systems, each of which is called a file system implementation".

The third layer is the **physical file system**. This layer is concerned with the physical operation of the storage device (e.g. disk). It processes physical blocks being read or written. It handles buffering and memory management and is responsible for the physical placement of blocks in specific locations on the storage medium. The physical file system interacts with the device drivers or with the channel to drive the storage device.

Take hard drive as a local storage devices file system, its architecture will be like this:

```
|--------|--------|----------------------|
^        ^        ^               
Super    Inode    Data  
block    table    block   
```

**Super block**: Super block contain information about the type of file system, its size and some information about the status of the file system.

# inode

Each file system has a table of **inode**, which is a **data structure**, for all files residing in the file system. The **inode** can be considered as the metadata of the file system (**Metadata** is **data that provides information about other data**. In other words, it is **data about data**).

The **inode** for each file includes the following information:
* file type (e.g., regular file, socket, or FIFO) and permissions;
* a pointer to a list of locks held on this file
* Various properties of the file: owner information, size, time stamp (creation and modification), data block (pointers to the actual data),...

# File permission

``r``,``w``: stand for read, write

Permission ``-rw-rw-r--`` means:

* The first character is ``-`` means it is a file
* The next 3 characters ``rw-`` represents the permissions for the file's owner: in this case, the owner may read from, write to, or execute the file.
* The next 3 characters ``rw-`` represent the permissions for members of the file group.
* The next 3 characters ``r--`` is the permission for "others" (everyone else) 

If a ``-`` means a permission (r,w,x) is denied.

**Example**:

```
-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md
```

This means it is a file, owner can both read and write the file, owner group can read and write, all user can read the file but can't execute the file.

First character acceptance value 
* ``t``: type
* ``-``: a file
* ``d``: directory
* ``l``: symbolic link

**Change permission**

* ``4``: for read
* ``2``: for write
* ``1``: execute

``mode = 4+2+1 = 7``: file can be read, write, execute

``4+2``: can be read and write
# chmod
``chmod``: change mode of folder or file

E.g ``chmod 775 name.sh``

``chmod +x``: Make file executable

The typical file permission is: ``trwxrwxrwx``

``chmod -R``: Change permission to all files inside the whole folder

## Example: Cannot open /dev/ttyUSB0: Permission denied

```bash
$ sudo chmod -R 777 /dev/ttyUSB0
```

File type + file permission can be view by ``stat`` command. File type + file permission are displayed under octal numeral system.

E.g: ``stat test.c`` gives ``Access: (0664/-rw-rw-r--)``
