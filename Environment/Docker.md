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