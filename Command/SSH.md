### OpenSSH

``OpenSSH`` is a suite of secure networking utilities based on the Secure Shell (SSH) protocol.

For Ubuntu desktop, SSH client is installed by default, which is part of ``OpenSSH``.

To install: ``sudo apt-get install openssh-client``.

### SSH key

For SSH client to access to SSH server, it also neccessary to use ``SSH key``.

For example. to clone a repository from Github (as a SSH server) in an Ubuntu computer (SSH client). It needs ``SSH key``.

To create SSH key in Ubuntu: ``ssh-keygen -t rsa``

Then copy SSH key to clipboard:

```shell
$ sudo apt-get install xclip
# Downloads and installs xclip. If you don't have `apt-get`, you might need to use another installer (like `yum`)

$ xclip -sel clip < ~/.ssh/id_rsa.pub
# Copies the contents of the id_rsa.pub file to your clipboard
```

Then go to Github and adds this key.