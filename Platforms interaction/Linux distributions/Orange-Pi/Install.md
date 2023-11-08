## First setup

Orange Pi's Armbian doesn't allow user for first ``ssh`` setup with ``ssh`` file like Raspbian. So user can set up first with UART connection or Ethernet connection.

### UART connection

UART connection can be used for first set up or connect to the board when ssh can't be accessed.

**Step 1**: Set up UART connection between the UART1 and CP2102, only use ``TX1``, ``RX1`` and ``GND``.

**Step 2**: After successfully booting, along with ``/dev/ttyUSB0`` there might appear ``/dev/ttyACM0`` if USB port is connected to the compuer.

Use Putty with Serial ``/dev/ttyACM0`` 115200

**Step 3**: In  ``/dev/ttyACM0`` 115200 , login with default username, password.

### Ethernet connection

**Step 1:** First boot Orange Pi zero is required to use Ethernet cable. Go to admin page of the router the check the address of Orange Pi. Then enter ``ssh root@192.168.1.*``with the IP address

**Step 2:** Set up password

After finishing the first setup, user has to setup WiFi with ``nmtui-connect``.

## VNC Server

```
sudo apt-get install tightvncserver
vncserver
```

**Issue**: Can't start server

```
Fatal server error:
could not open default font 'fixed' 
```

Install: ``sudo apt-get install -y xfonts-base``

Then go to VNC in computer: 

New connection: ``192.168.x.x:5901`` (vnc server start at 5901)

**Orange Pi Zero with GUI Desktop** 

Bug: unable to start x session orange pi

```
sudo apt-get install xorg lightdm xfce4 tango-icon-theme gnome-icon-theme
sudo apt-get install tightvncserver thunar-volman udisks2 gvfs
```
Then start ``tightvncserver``

Now you can remote desktop from VNC or remote desktop from Linux, in VNC server: ``192.168.1.x:5901``.
