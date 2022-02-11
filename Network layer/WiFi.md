## nmtui

``nmtui``: Text user interface for controlling NetworkManager

Install: ``sudo apt-get install network-manager``

### Set up WiFi

```
nmtui-connect
```

List the credentials of all the connected WiFi: ``ls /etc/NetworkManager/system-connections/``

For information of the specific SSID: ``cat /etc/NetworkManager/system-connections/SSID``

For the SSID with space, use ``\``: ``cat /etc/NetworkManager/system-connections/SSID\ space``

Connect with a SSID by ``nmcli``: ``nmcli dev wifi connect SSID password password``

For SSID with spaces: ``nmcli dev wifi connect SSID\ with\ space password password``

## iwconfig

### Configuration

``iwconfig``: configure a wireless network interface

E.g: ``iwconfig`` returns:

```
lo        no wireless extensions.

eno1      no wireless extensions.

wlo1      IEEE 802.11  ESSID:"WiFi SSID"
          Mode:Managed  Frequency:2.457 GHz  Access Point: D8:07:B6:C0:5F:EE   
          Bit Rate=135 Mb/s   Tx-Power=22 dBm   
          Retry short limit:7   RTS thr:off   Fragment thr:off
          Power Management:on
          Link Quality=67/70  Signal level=-43 dBm  
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:8  Invalid misc:7832   Missed beacon:0
```
