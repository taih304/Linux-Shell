![image](https://github.com/TranPhucVinh/Linux-Shell/assets/30307543/7a0acce4-9e63-480c-b1a5-5042ce5262dc)**CMake** is an open-source, cross-platform family of tools designed to build, test and package software.

# Install

CMake can be installed with ``sudo apt install cmake`` or installed with the tar file.

For installing with tar file, install ``cmake-3.23.0.tar.gz`` file from CMake webpage then extract to folder ``cmake-3.23.0``.

Inside folder ``cmake-3.23.0``, run file ``./bootstrap`` to setup CMake.

After successfully setup CMake, command ``cmake`` will be available. Folder ``cmake-3.23.0`` can then be deleted.

# Build the first C program

Set up a working folder for CMake project like ``c_make_test``:

```
c_make_test
|--main.c
|--CMakeLists.txt
```

``CMakeLists.txt``

```CMake
# cmake_minimum_required(VERSION 3.10)

# set the project name
project(test_c_make)

# add the executable
add_executable(test_c_make main.c)
```

Project's name can be used with ``${PROJECT_NAME}``:

```CMake
# set the project name
project(CMake_for_C_src_code)

# add the executable
add_executable(${PROJECT_NAME} main.c) # ${PROJECT_NAME} will get the PROJECT_NAME setup previously from project()
```

Inside ``c_make_test``, run ``cmake .`` or in the same location with ``c_make_test``, run ``cmake c_make_test/``:

```sh
username@hostname:~/wip/c_make_test$ cmake .
```
If building inside ``c_make_test``, the folder now will include:

```
username@hostname:~/wip/c_make_test$ ls
|--CMakeFiles
|--c_make_test
|--CMakeCache.txt
|--cmake_install.cmake
|--Makefile
```

Still inside ``c_make_test``, run: ``make``, binary file ``test_c_make`` will be created. Then run ``test_c_make`` to run the C program.
```sh
username@hostname:~/wip/c_make_test$ make
# test_c_make is created
username@hostname:~/wip/c_make_test$ ./test_c_make
```
Specify the build output to ``c_workspace_cmake`` folder by ``-B`` flag: ``cmake c_make_test/ -B c_workspace_cmake/``

If there is error with the source file, running ``cmake c_make_test/`` will still be fine then run ``make`` will have error.

# Build the program with source files

```
|--main.c
|--header.c
|--header.h
|--CMakeLists.txt
```

```CMake
project(test_c_make)

# add the executable
add_executable(${PROJECT_NAME} main.c header.c)
```

``main.c`` then just simply includes ``header.h``:

```c
#include "header.h"
//Operations go here
```

**Creating library with add_library()**:

With files architecture like above:

```CMake
# set the project name
project(test_c_make)

# add the executable
add_executable(${PROJECT_NAME} main.c)

add_library(
    header
    header.h
    header.c)

target_link_libraries(${PROJECT_NAME} PRIVATE header)
```

``add_library()``: Default for ``add_library()`` is to build static library. So when running the ``CMakeLists.txt`` above, there will be:

```
[ 50%] Linking C static library libheader.a
```

Other library types can be specified like ``SHARED``, ``STATIC``, ``MODULE``.

# API

### register_component()

For each component, CMakeLists file calls ``register_component``, which calls the CMake ``add_library`` function to add a library and then adds source files, compile options, etc.

### set()

```c
set(<variable> <value>... [PARENT_SCOPE])
```

Set the given <variable> in the current function or directory scope.
