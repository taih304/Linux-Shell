# Build an Ubuntu image from Ubuntu OS

Create ``build_docker``, a folder to include file ``Dockerfile``, the script file to build docker:

```
|--build_docker
	|--Dockerfile
```

``Dockerfile``

```dockerfile
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
## FROM

A Dockerfile must begin with a **FROM** instruction. The **FROM** instruction specifies the Parent Image from which you are building.

# Run-time instructions
Run-time instructions are instruction which run/execute when the docker is running.
## CMD

**CMD** is executing at run time.

``CMD command param``, e.g ``CMD echo "Hello, World !"``

``CMD ["command", "param"]``, e.g ``CMD ["echo", "Hello, World !"]``

```dockerfile
FROM ubuntu

CMD echo "Hello, World !"
```

Along with supporting all ubuntu docker features, running ``simple_ubuntu_docker`` (``sudo docker run simple_ubuntu_docker``) will result in ``Hello, World !``.

## ENTRYPOINT

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

When using ``ENTRYPOINT`` with ``echo`` like this, user are no longer able to execute command when running ``run``.

E.g: ``sudo docker run simple_ubuntu_docker ls`` will print out ``ls`` instead of executing ``ls`` command.
## ENV
```Dockerfile
FROM ubuntu
ENV string="Hello, World !"
CMD echo $string
```
Build and run ``simple_ubuntu_docker``: ``sudo docker run simple_ubuntu_docker`` will print out ``Hello, World !``
# Build-time instructions
Build-time instructions are instructions which run/execute while the docker is compiling/building. Build-time instructions won't run when the docker is running.
## RUN

**RUN** inside Dockerfile only runs during the docker build process:

### Add a specific package to the built docker with RUN

```dockerfile
FROM ubuntu

RUN apt-get update

RUN apt-get install net-tools
```

``ifconfig`` from ``net-tools`` now is supported: ``sudo docker run simple_ubuntu_docker ifconfig``

### Display debug message during docker build

Adding **RUN** with **echo** will print out a message during the docker build process:

```dockerfile
FROM ubuntu

RUN echo "Docker is being built"
```
Then the message **Docker is being built** will be printed out during the docker build process. Must not be confused [CMD](#build-an-ubuntu-image-that-only-prints-out-a-string) and **RUN** for echo as **CMD echo** will print out the message when running that docker.

## COPY
**Add files to a directory in the built docker**:

```dockerfile
FROM ubuntu

#Copy file test.sh in build_docker to / in simple_ubuntu_docker
COPY test.sh .
```

After successfully built, ``sudo docker run simple_ubuntu_docker ls`` will print out ``test.sh`` along with files in the ``/`` directory.
## ARG

```sh
ARG <name>[=<default value>]
```

The ARG instruction defines a variable that users can pass at build-time to the builder with the docker build command using the ``--build-arg <varname>=<value>`` flag. If a user specifies a build argument that was not defined in the Dockerfile, the build outputs a warning.

# Export
Export the current working docker container so that the newly exported container contains all the installed packages, and work progress from the origin one.

```sh
sudo docker export <IMAGE_ID > exported_docker_name.tar
```
E.g:
```sh
sudo docker export d99f7b921eb1 > exported_docker_container.tar
```
Then import the newly exported docker tar file
```sh
sudo docker import exported_docker_container.tar new_docker_name
```
E.g: 
```sh
sudo docker import esp8266_rtos_sdk_docker.tar esp8266_rtos_sdk_docker_modified
```
Now ``esp8266_rtos_sdk_docker_modified`` docker contains all the installed packages, and work progress from the origin docker which has IMAGE ID ``d99f7b921eb1``

Enter the terminal mode of this docker (must have **sh** argument):
```sh
sudo docker run -it esp8266_rtos_sdk_docker_modified sh
```
