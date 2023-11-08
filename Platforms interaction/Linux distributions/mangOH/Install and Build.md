# First time boot

## First time boot in Ubuntu

* Connect USB cable between the USB port of the mangOH Yellow to computer USB port
* Wait until the board finish booting
* Check ifconfig, if booting success, a network interface will appear like

```
enp0s20f0u2i19: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        ether ca:27:a9:b9:93:21  txqueuelen 1000  (Ethernet)
```

``enp0s20f0u2i19`` is the network interface of mangOH board.

The CF3 module will have the IP ``192.168.2.2``

For connection between mangOH and CF3 module, the mangOH has to be config to have the address 192.168.2.*

```shell
sudo ifconfig enp0s20f0u2i19 192.168.2.3
```

# Leaf install
In order to download to SetUp Dev Environment with Leaf, you have to sign in VPN

E.g: Connect to ``sslvpn.da.sierrawireless.com``, login with username, password

**Notice**: For proper later build Legato, the folder workspace should be name without space

E.g: ``Leaf`` is valid while ``Leaf workspace`` is invalid and will result in fail ``make`` to build Legato.

**Step 1**: Download and install latest debian package:

```
wget -O /tmp/leaf_latest.deb https://downloads.sierrawireless.com/tools/leaf/leaf_latest.deb
sudo apt install /tmp/leaf_latest.deb
```

**Step 2**: Add the Internal Legato Development Repo:

```
leaf remote add getlegato-all http://get.legato/leaf/index.json --insecure
```

**Step 3**: Disable the External Legato Repositories (all packages will be shown already with adding the internal repo).

```
leaf remote disable legato-stable
leaf remote disable legato-dev
```

**Step 4**: Before searching and installing your first SDK it is recommended to make a separate leaf workspace directory to store all of your custom Legato development.

Create a workspace folder then go to that folder

```sh
$ mkdir wp76xx_workspace
$ cd wp76xx_workspace
```

From folder ``wp76xx_workspace``, search for the module (wp76 = wp76xx, wp77= wp77xx, wp85 = wp85) with tags: the "latest" version of legato. 

``leaf search -t wp76xx -t latest``

If VPN is not signed-in, there will be an error:

```
ERROR:
  Can't fetch remote getlegato-all
CAUSED BY:
  HTTPConnectionPool(host='get.legato', port=80): Max retries exceeded with url: /leaf/index.json (Caused by NewConnectionError('<requests.packages.urllib3.connection.HTTPConnection object at 0x7febab866a90>: Failed to establish a new connection: [Errno -2] Name or service not known',))
HINTS:
  please check your network connection,
  or check the remote URL in leaf remote list,
  or you can disable the remote with leaf remote disable getlegato-all
```

**Step 5**: Setup profile name

E.g: ``leaf setup wp76_19.11.0.rc1-signed -p int-wp76_19.11.0.rc1-signed``

**Step 6**: ``leaf shell``

# Install Leaf and Build mangOH Software

``Sierra Wireless’ Leaf`` development workspace manager is designed to create and manage your mangOH development environment.

* **Step 1**: Create a mangOH workspace, e.g: ``mangOH_workspace``

* **Step 2**: Go to ``mangOH_workspace``, download ``leaf_latest.deb``

``wget https://downloads.sierrawireless.com/tools/leaf/leaf_latest.deb``

* **Step 3**: Install the downloaded package ``leaf_latest.deb``

``sudo dpkg -i leaf_latest.deb``

Notice, there might be a downloading error as Ubuntu might missed some packages: ``python3-argcomplete``, ``python3-colorama``, ``python3-gnupg``, ``python3-jsonschema``; installed all those packages to solve the problem.

* **Step 4**: Configure Leaf to add the mangOH Git remote, which enables Leaf to search for mangOH targets. (This only needs to be done once, the configuration is persistent)

```sh
$ leaf remote add mangOH https://downloads.sierrawireless.com/mangOH/leaf/mangOH-yellow.json --insecure 
```

* **Step 5**: Create a workspace (working directory) and then go to that directory.

```sh
$ mkdir ~/myWorkspace 
$ cd ~/myWorkspace 
```

* **Step 6**: Search the leaf remotes for packages with the "mangOH" tag using the following command:

```sh
$ leaf search -t mangOH 
```

Set up the current directory as a Leaf workspace and automatically create a profile for the target package, using the identifier from the previous step. This automatically downloads and installs the specified target package.

```sh
$ leaf setup -p mangOH-yellow-wp77xx_0.2.3 
```

Then  ``leaf-workspace.json`` will appear

* **Step 7**: Enter shell mode

Go to the workspace folder ``mangOH_workspace`` (haved installed the leaf setup before)

``leaf shell``

* **Step 7**: ``make yellow`` (in the workspace folder ``mangOH_workspace``)

* **Step 8**: update

``$ update mangOH/build/update_files/yellow.wp77xx.update 192.168.2.2``

# Build app

## Project architecture

```
test_mangoh_yellow/
├── test_component/
│   ├── Component.cdef
│   └── main.c
└── main.adef
```

**main.c**

```c
#include "legato.h"
#include "interfaces.h"
 
COMPONENT_INIT
{
    LE_INFO("Hello world!");
}
```

## Build and install app

Go to mangOH workspace folder, where leaf is installed

**Step 1**: Enter ``leaf shell``

Go to ``mangOH/apps/helloWorld``

**Step 2**: Build app ``mkapp -t wp77xx helloWorld.adef``

**Step 3**: Install app ``app install helloWorld.wp77xx.update 192.168.2.2``

# Reference

mangOH Yellow install document: ``mangOH Yellow Getting Started Guide [Rev3]``