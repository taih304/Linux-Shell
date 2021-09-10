## Commands

Detecting USB Drive: ``sudo fdisk -l``

Mount the USB: ``mount /dev/sdb1 /mnt``

List USB devices: ``lsusb``

### screen

The ``screen`` package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

To end ``screen``: ``Ctr+A+D``.

### Cannot open /dev/ttyUSB0: Permission denied

This error happen as your user account is not added to ``dialout`` or ``tty`` group.

To view the available group in your account, use command: ``groups``

To see all available groups type: ``compgen -g``

Add your account to ``dialout`` or ``tty`` groups:

```sh
sudo usermod -a -G tty yourname
sudo usermod -a -G dialout yourname
```

After this, logout your account to see the effect (Press Log out button in Settings)