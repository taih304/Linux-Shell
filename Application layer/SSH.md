# ssh
## -p
Specify SSH port with ``-p``: ``ssh guest@10.3.112.253 -p 2022``
## -i

``-i`` specifies key, i.e **.pem**

Connect to an AWS EC2 instance with its RSA key **Ubuntu_RSA_keys.pem**:
```sh
ssh -i "Ubuntu_RSA_keys.pem" ec2-user@ec2-44-212-53-1.compute-1.amazonaws.com
```
# OpenSSH

``OpenSSH`` is a suite of secure networking utilities based on the Secure Shell (SSH) protocol.

For Ubuntu desktop, SSH client is installed by default, which is part of ``OpenSSH``.

To install: ``sudo apt-get install openssh-client``.

# SSH key

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

## Add SSH key to known host

If a SSH key is not known to host, there will be error. To solve that isuse, add that SSH key to known host:

**Step 1**: Get the RSA key of your server, where ``server_ip`` is your server's IP address, such as ``192.168.1.1``: ``ssh-keyscan -t rsa server_ip``

E.g: ``ssh-keyscan -t rsa 192.168.1.1``

The result will be like:

```
192.168.1.1 ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAwH5EXZG...  
```

**Step 2**: Add that RSA key to ``~/.ssh/known_hosts`` file:

```
192.168.1.2  ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAqx9m529... (an existed SSH RSA key)
192.168.1.1  ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAwH5EXZG... (line you're adding, copied and pasted from above)
```

Be sure to delete the duplicate IP in ``known_hosts`` file.

Acccess to a host with password and bypass **StrictHostKeyChecking** and **UserKnownHostsFile**:
```sh
sshpass -p 'password' ssh -oStrictHostKeyChecking=no -oUserKnownHostsFile=/dev/null root@192.168.1.1
```
**Note**: ``sshpass`` is available only in Linux and isn't available in Windows

# SCP

SCP stands for Secure Copy. ``scp`` is a command for sending files over SSH

Copy file ``main.c`` from localhost to folder ``Documents`` of target Raspberry Pi (with username ``pi``): ``scp main.c pi@192.168.47.26:Documents/``

Copy file ``Makefile`` from target with username ``username`` to ``localhost`` (port 2022): ``scp -P 2022 username@192.168.137.239:/home/username/wip/Makefile .``

**Note**: Can't copy file like this: ``scp test.c pi@192.168.47.26``

Copy folder ``main``: ``scp -r main pi@192.168.47.26:Documents/``

Specify port with ``-P`` (uppercase P): ``scp -P 2022 test.c root@10.3.112.253:~``

Setup password for SCP with ``sshpass``: ``sshpass -p 'your_password' scp link_to_scp_file username@host:/path``

E.g: ``sshpass -p 'password' scp /home/usr/Documents/main.c root@192.168.1.1:/root``

SCP file to a host with password and bypass **StrictHostKeyChecking** and **UserKnownHostsFile**:
```sh
sshpass -p 'xmwfSMSCpBHVC0s+6vo1zFnze0dD+Ili' scp -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -r file_name.md root@192.168.1.1:/tmp
```
