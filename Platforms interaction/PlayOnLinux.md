Install PlayOnLinux on Ubuntu 16.04

**Step 1**: ``wget -q "http://deb.playonlinux.com/public.gpg" -O- | sudo apt-key add -``

**Step 2**: ``sudo wget http://deb.playonlinux.com/playonlinux_trusty.list -O /etc/apt/sources.list.d/playonlinux.list``

**Step 3**: ``sudo apt-get update``

**Step 4**: ``sudo apt-get install playonlinux``

After successfully installed, run ``playonlinux`` command

### Error

```
Fatal: Package installation will fail until you set /proc/sys/kernel/yama/ptrace_scope to 0
```

This error occur because some distro, including Ubuntu, use an extra and paranoïd kernel security that make some non-native games/softwares to not work

To get rid of the problem, you will have to use this root command in a terminal:

```sh
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
```

This solution is ok until reboot so not good for daily usage.

For a more permanent solution edit ``/etc/sysctl.d/10-ptrace.conf`` as root and set this option:

```sh
kernel.yama.ptrace_scope = 0
```