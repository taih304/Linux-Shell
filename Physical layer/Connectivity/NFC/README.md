# Device

* NFC reader: ACR122U
* Document: ACR122U USB NFC Reader, Application Programming Interface V2.04

# Appendix

* PICC: proximity integrated circuit card
* ATR: Answer to reset

# Install ACR122U NFC USB reader on Linux 

**Install driver**: ACR122U USB NFC Reader

Then extract the driver with the correct Linux release version

Then``lsusb`` to check the USB

**Result**: ``Bus 001 Device 031: ID 072f:2200 Advanced Card Systems, Ltd ACR122U``

**Install PCSC-TOOLS**

First of all, update your system’s package lists as usual: ``sudo apt-get update``

After that, download and install pcsc-tools: ``sudo apt-get install pcscd pcsc-tools``

Then you need to blacklist the pre-installed drivers. You can do so by opening ``blacklist.conf``:

``sudo nano /etc/modprobe.d/blacklist.conf``

Add these two lines to the end of the file:

```
install nfc /bin/false
install pn533 /bin/false
```

Then reboot the system.

Start reading: ``pcsc_scan``

``sudo service pcscd start``: start pcscd service

``sudo service pcscd restart``: restart pcscd service