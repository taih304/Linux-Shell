## Basic operations

Install ``ubuntu`` docker: ``sudo docker pull ubuntu``

In ``ubuntu`` docker ``~`` is ``/root``.

Run any command like ``echo``: 

```sh
sudo docker run ubuntu echo "Hello, World !"
```

## Working mode

``-i``: Enter interactive mode

```sh
username$hostname:~$ sudo docker run -i ubuntu
invalid_command
bash: line 1: invalid_command: command not found
echo "Hello, World !"
Hello, World !
exit #Use exit command to exit from -i mode
```

``-t``: Enter terminal mode

```sh
username$hostname:~$ sudo docker run -t ubuntu
root@80c4aa6c319e:/# (CLI will then switch to terminal root@80c4aa6c319e)
```

However, if using only ``-t``, we are unable to exit terminal mode by ``exit`` command.

In this case, we have to exit this mode by stopping the ``ubuntu`` container:

**Step 1**: In other terminal, use ``sudo docker ps`` to check the container ID of the ``ubuntu`` container

E.g

```
username$hostname:~$ sudo docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED         STATUS         PORTS     NAMES
80c4aa6c319e   ubuntu    "bash"    5 minutes ago   Up 5 minutes             youthful_burnell
```

**Step 2**: (Still in that terminal) Stop ``ubuntu`` container: ``sudo docker stop 80c``

To exit terminal mode easily, use ``-it`` flag which include ``-i`` for interactive mode.

## Handle input

Error with input command like ``read``:

```sh
username$hostname:~$ sudo docker run ubuntu read
docker: Error response from daemon: failed to create shim task: OCI runtime create failed: runc create failed: unable to start container process: exec: "read": executable file not found in $PATH: unknown.
ERRO[0000] error waiting for container: context canceled
```

Using ``-i`` or ``-t`` to handle input ``read`` command:

```sh
username$hostname:~$ sudo docker run -i ubuntu
read var_1 var_2
Hello, World
echo $var_1
Hello,
echo $var_2
World
exit
```

## Volume mapping

Volume mapping is a technique to map a folder in the OS hosting the docker container and the folder in that docker container. Its application is to:

1. Maintain data persistent in the mapped container folder
2. Act as a bridge to share data between the existed mapped folder in the hosting OS and the docker container folder

### Maintain data persistent in the mapped container folder

**Non-persistent feature**: Base on the definition of docker container, the data created while running the container will be losted when the container ends its life.

E.g: Create a file ``test.txt`` in ``home`` directory of ``ubuntu`` docker. It will then be lost when the container stopped running.

**Data persistent**: Map folder ``docker_dir`` in the OS hosting the docker container to folder ``/home`` in that docker container by ``-v``. Note that the mapping process require absolute path (``/home/hostname/docker_dir``):

```sh
sudo docker run -v /home/hostname/docker_dir:/home -i ubuntu #then perform operation with interactive mode
```

When ``ubuntu`` docker container is turned off, **all of its data while the container working is lost**. However, as previously performed mapping, all those data in its ``home`` directory is stored in ``/home/hostname/docker_dir``

### Act as a bridge

Map ``existed_dir``, an existed directory with existed data to ``home`` of docker container

```sh
sudo docker run -v /home/hostname/existed_dir:/home -i ubuntu #then perform operation with interactive mode
```

Then all file operation inside ``home`` directory in the ``ubuntu`` docker container will be mapped to ``/home/hostname/existed_dir`` to the hosting OS, and also in reverse, as all operation in ``/home/hostname/existed_dir`` will effect ``home`` of ``ubuntu`` docker container.

## Run a specific process on docker

### Run a simple process

Run a process ``test.sh`` inside folder ``docker_dir`` in the hosting OS (as this directory is mapped to the container):

```sh
sudo docker run -v /home/hostname/docker_dir:/home ubuntu home/test.sh
```

``test.sh``

```sh
#!/bin/bash
echo "Hello for docker"
```

**Note**: Must have the Shebang line ``#!/bin/bash`` so that the docker container knows the bash shell is chosen to compile.

### Set environment variable

``test.sh``

```sh
#!/bin/bash
echo "$DOCKER_ENV"
```

Use ``-e`` flag:

```sh
sudo docker run -v /home/dekvn/VinhTran/docker_dir:/home -e DOCKER_ENV="Docker environment" ubuntu home/test.sh
```