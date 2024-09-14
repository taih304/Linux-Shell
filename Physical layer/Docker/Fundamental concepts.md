# Docker overview

Docker is not meant to virtualize and run different OS and kernels on the same hardware. The main purpose of docker is to package and containerize applications to ship them.

An **image** is a **package** or a **template**, just like a VM template that work within the virtualization world, **used to create one or more containers**.

**Container** is a **running instance of images** that is isolated and has their own environment and set of processes. Unlike a virtual machine, containers aren't meant to host an OS. **Containers only recreate, or virtualize, the operating systems**. Containers meant to run a specific task or process, e.g run a webserver, database,... Once the task is completed, the container exits. A container only lives as long as the process inside it is alive. This means **all the processes running progress, packages installed,... in the current docker container will be deleted/removed after quitting this docker container**.
# Docker registry
A Docker registry is a centralized platform for storing and distributing Docker images. It allows users to upload, download, and manage container images. Docker registries can be either public or private, with **Docker Hub** being the most well-known default public registry where users can pull or push Docker images. 

For **private registry**, users can host their own private registry or use cloud-based services to store images, which can be set up using the **Docker Registry image**.

# Docker Hub
**Docker Hub** is a repository of Docker Images, which is quite similar to Github, where you can create, manage, and deliver containers.
**Implementation**: Push local docker [esp8266_rtos_sdk_docker](https://github.com/TranPhucVinh/ESP8266-RTOS-SDK/tree/main/Environment/esp8266_rtos_sdk_docker) to docker hub ``tranphucvinh96/esp8266_rtos_sdk_docker``

After creating a docker on Docker Hub, e.g ``tranphucvinh96/esp8266_rtos_sdk_docker``, it's empty so you can't pull it. This empty docker repository must be pushed from a local docker first

**Step 1**: Login docker

```sh
docker login
```

**Step 2**:                 

Then tag the local docker to its name on docker hub:

```sh
docker tag esp8266_rtos_sdk_docker:latest tranphucvinh96/esp8266_rtos_sdk_docker
```
Now both ``esp8266_rtos_sdk_docker`` and ``tranphucvinh96/esp8266_rtos_sdk_docker`` are the same docker, which can be both listed by **docker images**. Deleting ``tranphucvinh96/esp8266_rtos_sdk_docker`` will also delete ``esp8266_rtos_sdk_docker``.

**Step 3**: Push the docker
```sh
docker push tranphucvinh96/esp8266_rtos_sdk_docker
```
# Docker Engine

**Docker Engine** is an application that supports launching Docker daemon process
