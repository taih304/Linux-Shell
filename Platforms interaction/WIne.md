Install Wine on Ubuntu 16.04

**Step 1**: ``wget -nc https://dl.winehq.org/wine-builds/winehq.key``

**Step 2**: ``sudo add-apt-repository ppa:wine/wine-builds``

**Step 3**: ``sudo apt-get update``

**Step 4**: ``sudo apt-get install --install-recommends winehq-devel``

**Step 5**: Run ``winecfg`` to set up configuration for Wine