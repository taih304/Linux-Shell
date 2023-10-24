# Fundamental concepts

Docker is not meant to virtualize and run different OS and kernels on the same hardware. The main purpose of docker is to package and containerize applications to ship them.

An **image** is a package or a template, just like a VM template that work within the virtualization world, used to create one or more containers.

**Container** is a running instance of images that is isolated and has their own environment and set of processes. Unlike a virtual machine, containers aren't meant to host an OS. **Containers only recreate, or virtualize, the operating systems**. Containers meant to run a specific task or process, e.g run a webserver, database,... Once the task is completed, the container exits. A container only lives as long as the process inside it is alive. This means **all the processes running progress, packages installed,... in the current docker container will be deleted/removed after quitting this docker container**.

# Install

## Set up the repository

1. Update the ``apt`` package index and install packages to allow ``apt`` to use a repository over HTTPS:

```sh
$ sudo apt-get update
$ sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
```

2. Add Docker’s official GPG key:

```sh
$ sudo mkdir -p /etc/apt/keyrings
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```

3. Use the following command to set up the repository:

```sh
$ echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

## Install Docker Engine

1. Update the ``apt`` package index, and install the latest version of Docker Engine, containerd, and Docker Compose, or go to the next step to install a specific version:

```sh
$ sudo apt-get update
$ sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

In Ubuntu 16.04, there is error when performing this step:

```
E: Unable to locate package docker-compose-plugin
```

While those steps run smoothly on Ubuntu 20.04.

However, this error doesn't effect the docker operation in Ubuntu 16.04.

Once successfully installed, command ``docker`` is available.

## Issue

If your account is not added to ``docker`` group, running the program that related to docker will cause the issue like:

```
Could not run `docker` 
Error: exit status 1
Ensure you have the latest version of `docker-ce` installed 
See: https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-ce
```

To solve that problem: ``sudo usermod -aG docker ${USER}``. If setting successfully, ``docker`` will be listed out by ``groups`` command as it has been added to user.

# Implementations

## Command

``sudo service docker start``: Start docker service

``sudo docker run hello-world``: Run docker image ``hello-world``. If running it for the first time after installed, it will be pulled from the docker hub

Its log message while pulling:

```
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
2db29710123e: Pull complete
Digest: sha256:7d246653d0511db2a6b2e0436cfd0e52ac8c066000264b3ce63331ac66dca625
Status: Downloaded newer image for hello-world:latest
```

(Then the log message will print out the content of ``hello-world`` image)

``docker run --rm``: With ``--rm`` flag, Docker also removes the anonymous volumes associated with the container when the container is removed.

``sudo docker pull hello-world``: Only pull ``hello-world`` and not run it after successfully pulling

``sudo docker images``: List all available images and their information

E.g

```
username$hostname:~$ sudo docker images
REPOSITORY    TAG       IMAGE ID       CREATED         SIZE
hello-world   latest    feb5d9fea6a5   11 months ago   13.3kB
```

``sudo docker image rm image_id``: Remove a docker with ID ``image_id``. ``sudo docker image rm -f image_id``: Force to remove docker

``sudo docker inspect ubuntu``: Provide docker named ``ubuntu``'s information in JSON format

``sudo docker ps``: List all running container

``sudo docker ps -a``: List all running or exited containers

## [ubuntu docker](ubuntu%20docker.md)

Table of contents for ``ubuntu docker`` implementations:

* [Basic operations](ubuntu%20docker.md#basic-operations)
* Working mode
* Handle input
* Volume mapping
* Run docker's specific process

## [Build a docker image](Build%20docker%20image.md)
* [Build an Ubuntu image from Ubuntu OS](Build%20docker%20image.md#build-an-ubuntu-image-from-ubuntu-os)
* [Build an Ubuntu image that only prints out a string](Build%20docker%20image.md#build-an-ubuntu-image-that-only-prints-out-a-string): [CMD and ENTRYPOINT](Build%20docker%20image.md#cmd-and-entrypoint)
* [Build a docker with included files and installed library](Build%20docker%20image.md#build-a-docker-with-included-files-and-installed-library)

