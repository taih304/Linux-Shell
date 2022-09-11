## Fundamental concepts

Docker is not meant to virtualize and run different OS and kernels on the same hardware. The main purpose of docker is to package and containerize applications to ship them.

An **image** is a package or a template, just like a VM template that work within the virtualization workd, used to create one or more containers.

**Container** is a running instance of images that is isolated and has their own environment and set of processes.

## Install

**Issue**

If your account are not added to ``docker`` group, running the program that related to docker will cause the issue like:

```
Could not run `docker` 
Error: exit status 1
Ensure you have the latest version of `docker-ce` installed 
See: https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-ce
```

To solve that problem: ``sudo usermod -aG docker ${USER}``