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
