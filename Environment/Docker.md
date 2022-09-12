## Fundamental concepts

Docker is not meant to virtualize and run different OS and kernels on the same hardware. The main purpose of docker is to package and containerize applications to ship them.

An **image** is a package or a template, just like a VM template that work within the virtualization workd, used to create one or more containers.

**Container** is a running instance of images that is isolated and has their own environment and set of processes. Unlike a virtual machine, containers are meant to host an OS. Containers meant to run a specific task or process, e.g run a webserver, database,... Once the task is completed, the container exits. A container only lives as long as the process inside it is alive.

## Install

### Set up the repository

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

### Install Docker Engine

1. Update the ``apt`` package index, and install the latest version of Docker Engine, containerd, and Docker Compose, or go to the next step to install a specific version:

```sh
$ sudo apt-get update
$ sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

In Ubuntu 16.04, there is error when performing this step

```
E: Unable to locate package docker-compose-plugin
```

While those steps run smoothly on Ubuntu 20.04.

Once successfully installed, command ``docker`` is available.

### Issue

If your account are not added to ``docker`` group, running the program that related to docker will cause the issue like:

```
Could not run `docker` 
Error: exit status 1
Ensure you have the latest version of `docker-ce` installed 
See: https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-ce
```

To solve that problem: ``sudo usermod -aG docker ${USER}``

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

``sudo docker pull hello-world``: Only pull ``hello-world`` and not run it after successfully pulling

``sudo docker images``: List all avaialbe images and their information

E.g

```
username$hostname:~$ sudo docker images
REPOSITORY    TAG       IMAGE ID       CREATED         SIZE
hello-world   latest    feb5d9fea6a5   11 months ago   13.3kB
```

``sudo docker inspect ubuntu``: Provide docker information in JSON format

``sudo docker ps``: List all running container

``sudo docker ps -a``: List all running or exited containers
