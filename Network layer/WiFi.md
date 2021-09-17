### Set up WiFi

```
nmtui-connect
```

List the credentials of all the connected WiFi: ``ls /etc/NetworkManager/system-connections/``

For information of the specific SSID: ``cat /etc/NetworkManager/system-connections/SSID``

For the SSID with space, use ``\``: ``cat /etc/NetworkManager/system-connections/SSID\ space``

Connect with a SSID by ``nmcli``: ``nmcli dev wifi connect SSID password password``

For SSID with spaces: ``nmcli dev wifi connect SSID\ with\ space password password``
