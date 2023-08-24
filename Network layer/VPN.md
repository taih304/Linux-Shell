# Fundamental concepts
A **virtual private network** is a mechanism for creating a secure connection between a computing device and a computer network, or between two networks, using an insecure communication medium such as the public Internet.

For normal access without VPN, your internet connection will be routed through your ISP servers. It means that your ISP can see and log all of your Internet activity.

When using VPN, your internet connection will bypass the ISP server and will be redirected to the VPN server so that your ISP can't see your activity, the website you visit can't see your real IP but they see the VPN server IP instead.
# Cloudflare WARP
Cloudflare WARP is a VPN client which connects to the Cloudflar VPN server at address 1.1.1.1

## Install
```sh
# Add cloudflare gpg key
curl https://pkg.cloudflareclient.com/pubkey.gpg | sudo gpg --yes --dearmor --output /usr/share/keyrings/cloudflare-warp-archive-keyring.gpg

# Add this repo to your apt repositories
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/cloudflare-warp-archive-keyring.gpg] https://pkg.cloudflareclient.com/ $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/cloudflare-client.list

# Must run those 2 steps before installing cloudflare-warp by sudo apt-get
sudo apt-get update && sudo apt-get install cloudflare-warp

# Then install the cloudflare-warp package
sudo apt install cloudflare-warp
```

## Initial Connection
To connect for the very first time you must call register first:

1. Register the client ``warp-cli register``.
2. Then connect ``warp-cli connect``.
3. Run ``curl https://www.cloudflare.com/cdn-cgi/trace/`` and verify that ``warp=on``. The whole result can be like:

```
fl=23f498
h=www.cloudflare.com
ip=2a09:bac1:7ac0:10::17:1f2
ts=1692888576.619
visit_scheme=https
uag=curl/7.58.0
colo=HKG
sliver=010-tier1
http=http/2
loc=VN
tls=TLSv1.3
sni=plaintext
warp=on
gateway=off
rbi=off
kex=X25519
```
And now, your PC has the WARP Cloudflare VPN client successfully setup which allows you to connect to other blocked website.

To disconnect WARP Cloudflare: ``warp-cli disconnect``
# Cisco AnyConnect client

## Install Cisco AnyConnect client

First, make sure you have the necessary Debian/Ubuntu support packages installed:

```sh
$ sudo apt-get update
$ sudo apt-get install lib32z1 lib32ncurses5
```

[Download the Anyconnect VPN client](https://sites.socsci.uci.edu/~jstern/uci_vpn_ubuntu/ubuntu-openconnect-uci-instructions.html).

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

# VPN for Google Chrome

There are various Google extensions to support running VPN on Google Chrome, like Betternet.
