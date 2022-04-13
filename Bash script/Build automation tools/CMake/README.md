# Fundamental concepts

CMake is an open-source, cross-platform family of tools designed to build, test and package software.

### Install

CMake can be installed with ``sudo apt install cmake`` or installed with the tar file.

For installing with tar file, install ``cmake-3.23.0.tar.gz`` file from CMake webpage then extract to folder ``cmake-3.23.0``.

Inside folder ``cmake-3.23.0``, run file ``./bootstrap`` to setup CMake. Also read file ``README.rst`` for any further information.

After successfully setup CMake, command ``cmake`` will be available. Folder ``cmake-3.23.0`` can then be deleted.

### Build the first C program

Set up a working folder for CMake project like ``c_make_test``:

```
|--main.c
|--CMakeLists.txt
```

``CMakeLists.txt``

```
# cmake_minimum_required(VERSION 3.10)

# set the project name
project(test_c_make)

# add the executable
add_executable(test_c_make main.c)
```

In the same location with ``c_make_test``, run ``cmake c_make_test/``

The folder architecture where ``c_make_test`` is in now will be:

```
|--CMakeFiles
|--c_make_test
|--CMakeCache.txt
|--cmake_install.cmake
|--Makefile
```

Then run: ``make``, binary file ``test_c_make`` will be created. Then run ``test_c_make`` to run the C program.

If there is error with the source file, running ``cmake c_make_test/`` will be file then run ``make`` will have error.

Project name can be used with ``${PROJECT_NAME}``:

```CMake
add_executable(${PROJECT_NAME} main.c)
```

### Build the program with source files

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
