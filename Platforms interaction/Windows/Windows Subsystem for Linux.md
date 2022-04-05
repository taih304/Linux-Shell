## Fundamental concepts

**Windows Subsystem for Linux (WSL)** lets developers run a GNU/Linux environment, including most command-line tools, utilities, and applications, directly on Windows, unmodified, without the overhead of a traditional virtual machine or dual-boot setup.

**Windows Subsystem for Linux version 2 (WSL2)** runs a Linux kernel inside a light-weight (Hyper-V) VM providing a Linux user-space environment in which regular Linux distributions such as Ubuntu can be installed. WSL2 provides seamless integration between Windows and Linux, fast boot times, a small resource footprint, and requires no VM configuration or management.

Installing WSL will then allow Ubuntu as a Microsoft app to run normally on Windows OS PC. Ubuntu like Ubuntu 20.04 can be installed to run as an app on Windows OS PC from Microsoft Store. After installing, drive C of the Windows OS PC is mounted on: ``/mnt/C``. Get to this location to perform file operations between the Ubuntu App and the Windows OS.

### Command

After installing WSL, all WSL command must be run on the Windows CLI like command prompt, Git Bash,... as those command will give direct effect to the Linux environment host on that Windows OS PC.

E.g:  ``wsl`` command will enter the current installed Linux OS app (like Ubuntu) on the current Window OS PC to CLI. To run ``wsl``, Launch a command prompt and run ``wsl``.

To log out from that Linux OS app to get back to the Windows CLI, run ``exit``.

**Other commands**

* Set WSL2 as default: ``wsl --set-default-version 2``
* List all installed Linux OS app: ``wsl -l`` and ``wsl -l -v``

### Running GUI

To run a program with GUI on Linux OS app, like gedit, xeyes,... X11 XLaunch has to be installed then run that program on MobaXterm.

After intalling XLaunch successfully, go to MobaXterm then connect to the Linux OS appp then run the GUI app like ``gedit``.

If running the command for those GUI program on the Linux OS app, like ``xeyes``, there will be error: ``Error: Can't open display:``

**Issue**: GUI can't be displayed on MobaXterm with error like below

This issue might happen when first time install WSL and the Linux OS app. To solve, run ``wsl --update``
