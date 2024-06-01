``sudo fdisk -l``: List all disks/partitions information

# All fdisk commands
```sh
username@hostname:~$ sudo fdisk /dev/sdc # Pass any device name as the argument to check for the command
Command (m for help): m

Help:

  DOS (MBR)
   a   toggle a bootable flag
   b   edit nested BSD disklabel
   c   toggle the dos compatibility flag

  Generic
   d   delete a partition
   F   list free unpartitioned space
   l   list known partition types
   n   add a new partition
   p   print the partition table
   t   change a partition type
   v   verify the partition table
   i   print information about a partition

  Misc
   m   print this menu
   u   change display/entry units
   x   extra functionality (experts only)

  Script
   I   load disk layout from sfdisk script file
   O   dump disk layout to sfdisk script file

  Save & Exit
   w   write table to disk and exit
   q   quit without saving changes

  Create a new label
   g   create a new empty GPT partition table
   G   create a new empty SGI (IRIX) partition table
   o   create a new empty DOS partition table
   s   create a new empty Sun partition table

Command (m for help): p #Check p: print the partition table 
Disk /dev/sdc: 14.9 GiB, 15931539456 bytes, 31116288 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x30c19d12
```
# Format partitions inside an SD card

Formating SD card ``/dev/sdc`` into 2 partitions ``/dev/sdc1`` (**bootfs partition**) in FAT32 format with 100 MiB and ``/dev/sdc2`` (**rootfs partition**) in ext4 format which takes size of the leftover of the SD card. This example will help formating bootfs and rootfs partition for an ARM Linux single board computer like Raspbian.

**Step 1**: Create the FAT32 and ext4 partitions on /dev/sdc by fdisk command
```sh
username@hostname:~$ sudo fdisk /dev/sdc
[Omitting fdisk introduction line]
Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): 

Using default response p.
Partition number (1-4, default 1): 
First sector (2048-31116287, default 2048): 
Last sector, +sectors or +size{K,M,G,T,P} (2048-31116287, default 31116287): +100M

Created a new partition 1 of type 'Linux' and of size 100 MiB.

Command (m for help): n
Partition type
   p   primary (1 primary, 0 extended, 3 free)
   e   extended (container for logical partitions)
Select (default p): 

Using default response p.
Partition number (2-4, default 2): 
First sector (206848-31116287, default 206848): 
Last sector, +sectors or +size{K,M,G,T,P} (206848-31116287, default 31116287): 

Created a new partition 2 of type 'Linux' and of size 14.8 GiB.

Command (m for help): t
Partition number (1,2, default 2): 1
Partition type (type L to list all types): L

[List out all partition type with 0xb is W95 FAT32]
Partition type (type L to list all types): b

Changed type of partition 'Linux' to 'W95 FAT32'.

Command (m for help): p
Disk /dev/sdc: 14.9 GiB, 15931539456 bytes, 31116288 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x30c19d12

Device     Boot  Start      End  Sectors  Size Id Type
/dev/sdc1         2048   206847   204800  100M  b W95 FAT32
/dev/sdc2       206848 31116287 30909440 14.8G 83 Linux

Command (m for help): w
The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.
```

**Step 2**: Format the partitions
```sh
# FAT32 for boot partition
$ sudo mkfs.vfat -F 32 -n boot /dev/sdc1

# ext4 for root partition
$ sudo mkfs.ext4 -L root /dev/sdc2
```
``mkfs.vfat``: Create an [MS-DOS FAT file system](https://github.com/TranPhucVinh/Windows-Batch/blob/master/Physical%20layer/File%20system.md#windows-file-system) under Linux.
* ``-F FAT-size``: Specifies the type of file allocation tables used (12, 16 or 32 bit)
* ``-n volume-name``
``mkfs.ext4``: Create an [ext4 filesystem](https://github.com/TranPhucVinh/Windows-Batch/blob/master/Physical%20layer/File%20system.md#windows-file-system)
* ``-L``: Set the volume label for the filesystem
# Delete existing partitions

Delete 2 existed partitions (``/dev/sdc1`` and ``/dev/sdc2``) of SD card /dev/sdc

```sh
username@hostname:~$ sudo fdisk /dev/sdc
[Omitting fdisk introduction line]
Command (m for help): d
Partition number (1,2, default 2): 1

Partition 1 has been deleted.

Command (m for help): d
Selected partition 2
Partition 2 has been deleted.

Command (m for help): w #w will write the delete operation for 2 partitions /dev/sdc1 and /dev/sdc2 setting above
The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.
```
