### OpenSSH

``OpenSSH`` is a suite of secure networking utilities based on the Secure Shell (SSH) protocol.

For Ubuntu desktop, SSH client is installed by default, which is part of ``OpenSSH``.

To install: ``sudo apt-get install openssh-client``.

### SSH key

For SSH client to access to SSH server, it also neccessary to use ``SSH key``.

For example. to clone a repository from Github or Gitlab (as a SSH server) in an Ubuntu computer (SSH client). It needs ``SSH key``.

To create SSH key in Ubuntu: ``ssh-keygen -t rsa``

Then copy SSH key to clipboard:

```shell
$ sudo apt-get install xclip
# Downloads and installs xclip. If you don't have `apt-get`, you might need to use another installer (like `yum`)

$ xclip -sel clip < ~/.ssh/id_rsa.pub
# Copies the contents of the id_rsa.pub file to your clipboard
```

Then go to Github or Gitlab and add this key.

### SCP

SCP stands for Secure Copy. ``scp`` is a command for sending files over SSH

Copy file ``main.c`` to folder ``Documents`` of Raspberry Pi: ``scp main.c pi@192.168.47.26:Documents/``

**Note**: Can't copy file like this: ``scp test.c pi@192.168.47.26``
