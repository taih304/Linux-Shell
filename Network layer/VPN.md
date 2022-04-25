## Cisco AnyConnect client

### Install Cisco AnyConnect client

First, make sure you have the necessary Debian/Ubuntu support packages installed:

```sh
$ sudo apt-get update
$ sudo apt-get install lib32z1 lib32ncurses5
```

Go to [UCI OIT Cisco Anyconnect/Linux instruction page](https://uci.service-now.com/kb_view.do?sysparm_article=KB0010201) and download the ``Anyconnect VPN client``.

Then extract this file:  ``tar -xzvf anyconnect-predeploy-linux-64-4.3.05017-k9.tar\ 6.59.23\ AM.gz``

A folder ``anyconnect-linux64-4.6.02074`` will appear 

``cd anyconnect-linux64-4.6.02074/vpn``

``sudo ./vpn_install.sh``

Now reload systemd, scanning for new or changed units: ``sudo systemctl daemon-reload``

The vpn client should now have been installed on your system and the vpnagentd process started. You can verify this by looking at the active processes:

```sh
$ ps auxw | grep vpnagentd | grep -v grep
```

Make command aliases to point to the vpn and vpnui commands:

```sh
$ alias vpn='/opt/cisco/anyconnect/bin/vpn'
$ alias vpnui='/opt/cisco/anyconnect/bin/vpnui'
```

Also add these aliases to the end of your ``~/.bashrc`` or ``~/.bash_aliases`` file:

```sh
$ cat >> ~/.bash_aliases
alias vpn='/opt/cisco/anyconnect/bin/vpn'
alias vpnui='/opt/cisco/anyconnect/bin/vpnui'
```
Then ``Ctr+C`` to save.

After successfully installed, folder ``anyconnect-linux64-4.6.02074`` can be deleted.

### CLI vs UI

Type ``vpn`` for CLI or ``vpnui`` for UI

In CLI:

``connect sslvpn.da.sierrawireless.com``: to connect to a URL, then type in username, password

It works similar in GUI to set up connection

**Notice**: Login with two account on Linux (E.g user account and guess account) will result in fail VPN start.

### Reference:

* [Anyconnect VPN client](https://www.socsci.uci.edu/~jstern/uci_vpn_ubuntu/)

## VPN for Google Chrome

There are various Google extensions to support running VPN on Google Chrome, like Betternet.
