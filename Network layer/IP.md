### Check IP of current Linux device

```
ip addr show
```
### nmap

``nmap`` has to be installed

``nmap -sP 192.168.1.*``: scan all IP connected to a network

### ping

You can only ``ping`` to a station that has opened a port for listening, like a HTTP server with port 80. If pinging to a station with no opened port like a device simply connect to WiFi, there will be error: ``Destination Host Unreachable``

**Example**: ESP8266 simply connects to WiFi and has IP ``192.168.0.100``. Then ``ping 192.168.0.100`` will have error ``Destination Host Unreachable``

If ESP8266 then starts a HTTP server, then you can ``ping 192.168.0.100`` normally.

``ping -i 3 google.com``: set an interval of 3 second

``ping -s 80 google.com``: set package size of 80

``ping -c 1 google.com``: ping for only 1 package
