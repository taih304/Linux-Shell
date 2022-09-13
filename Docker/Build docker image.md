## Build an Ubunu image from Ubuntu OS

Create ``build_docker``, a folder to include file ``Dockerfile``, the script file to build docker:

```
|--build_docker
	|--Dockerfile
```

``Dockerfile``

```sh
FROM ubuntu
```

(Simply call ``FROM ubuntu``)

Inside ``build_docker``, run: ``sudo docker build . -t "simple_ubuntu_docker"``

If successfully built, image ``simple_ubuntu_docker`` is available among the local docker images, which can be checked by ``sudo docker images`` command.

Image ``simple_ubuntu_docker`` has the same size as other image built from Ubuntu, like ``ubuntu``:

```sh
username$hostname:~$ sudo docker images
REPOSITORY             TAG       IMAGE ID       CREATED          SIZE
simple_ubuntu_docker   latest    a7c9647f4b21   3 minutes ago    77.8MB
ubuntu                 latest    2dc39ba059dc   10 days ago      77.8MB
```

Image ``simple_ubuntu_docker`` now support all features like [ubuntu docker](ubuntu%20docker.md), e.g support command like ``ls``, ``cd``,...

## Build an Ubuntu image that only print out a string

``Dockerfile``

```dockerfile
FROM ubuntu

CMD echo "Hello, World !"
```

Run ``simple_ubuntu_docker``: ``sudo docker run simple_ubuntu_docker``

Result: ``Hello, World !``

**Note**: Image ``simple_ubuntu_docker`` now just only print out ``Hello, World !`` string and doesn't support any other command like ``ls``, ``cd``,...

### CMD and ENTRYPOINT

**CMD**

``CMD command param``, e.g ``CMD echo "Hello, World !"``

``CMD ["command", "param"]``, e.g ``CMD ["echo", "Hello, World !"]``

**ENTRYPOINT**

```dockerfile
FROM ubuntu

ENTRYPOINT ["echo"]
```

Build and run ``simple_ubuntu_docker`` with argument: ``sudo docker run simple_ubuntu_docker "Hello, World !"``

Result: ``Hello, World !``

Add default value for ``ENTRYPOINT``:

```dockerfile
FROM ubuntu

ENTRYPOINT ["echo"]

CMD ["Default string"]
```

Then build and run ``simple_ubuntu_docker`` without argument: ``sudo docker run simple_ubuntu_docker``

Result: ``Default string``

Build and run ``simple_ubuntu_docker`` with argument: ``sudo docker run simple_ubuntu_docker "Hello, World !"``

Result: ``Hello, World !``
