In ``/dev``, SD card, SD card adapter or USB are detected as ``sdc`` like ``sdc``, ``sdc1``,... ``sdc`` which are block devices.

``lsblk``: list block devices

E.g:

```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop1    7:1    0  64.8M  1 loop /snap/gtk-common-themes/1514
sdd      8:48   1  14.9G  0 disk 
├─sdd2   8:50   1  14.6G  0 part /media/username/rootfs
└─sdd1   8:49   1   256M  0 part /media/username/rootfs
```

### Loop device

A loop device, ``vnd`` (vnode disk), or ``lofi`` (loop file interface) is a pseudo-device that makes a computer file accessible as a block device. Before use, a loop device must be connected to an existed file in the file system. 
