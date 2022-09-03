# Software development environment

## PlatformIO

To read serial data from Serial port:

```sh
pio device monitor --port /dev/ttyUSB0 --baud 115200 --echo
```

For hex data

```sh
pio device monitor --port /dev/ttyUSB0 --baud 38400 --echo --encoding hexlify
```

``--encoding``: Set the encoding for the serial port (e.g. hexlify, Latin1, UTF-8), default UTF-8.

## Docker 

**Issue**

If your account are not added to ``docker`` group, running the program that related to docker will cause the issue like:

```
Could not run `docker` 
Error: exit status 1
Ensure you have the latest version of `docker-ce` installed 
See: https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-ce
```

To solve that problem: ``sudo usermod -aG docker ${USER}``

# Github project environment

[Images used in that projects](Images)
