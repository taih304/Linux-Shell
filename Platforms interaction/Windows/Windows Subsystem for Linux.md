**Windows Subsystem for Linux (WSL)** lets developers run a GNU/Linux environment, including most command-line tools, utilities, and applications, directly on Windows, unmodified, without the overhead of a traditional virtual machine or dual-boot setup.

**Windows Subsystem for Linux version 2 (WSL2)** runs a Linux kernel inside a light-weight (Hyper-V) VM providing a Linux user-space environment in which regular Linux distributions such as Ubuntu can be installed. WSL2 provides seamless integration between Windows and Linux, fast boot times, a small resource footprint, and requires no VM configuration or management.

After installing WSL, all WSL command must be run on the Windows CLI like command prompt, Git Bash,... as those command will give direct effect to the Linux environment host on that Windows OS PC.

E.g:  Set WSL2 as default: Launch a command prompt and run ``wsl --set-default-version 2``.
