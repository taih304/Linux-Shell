### Set up WiFi

```
nmtui-connect
```

List the credentials of all the connected WiFi: ``ls /etc/NetworkManager/system-connections/``

For information of the specific SSID: ``cat /etc/NetworkManager/system-connections/SSID``

For the SSID with space, use ``\``: ``cat /etc/NetworkManager/system-connections/SSID\ space``

### Check IP of current Linux device

```
ip addr show
```

### change DNS

```shell
sudo nano /etc/resolv.conf
```

### Install other package on Linux or Linux Docker

For example, Install ``Node.js`` on Debian docker container

```
E: Failed to fetch http://deb.debian.org/debian/pool/main/n/nodejs/nodejs_4.8.2~dfsg-1_amd64.deb
Hash Sum mismatch
```

This might be a proxy error

To set up proxy from terminal

```shell
export http_proxy=http://10.10.10.10:8080
```

To unset proxy: ``unset http_proxy`` (follow the command above)

### nmap

``nmap`` has to be installed

``nmap -sP 192.168.1.*``: scan all IP connected to a network

### ping

``ping -i 3 google.com``: set an interval of 3 second

``ping -s 80 google.com``: set package size of 80

``ping -c 1 google.com``: ping for only 1 package
