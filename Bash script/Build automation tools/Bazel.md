**Bazel** is an open-source build and test tool similar to Make, Maven, and Gradle. Bazel is multi-platform. It runs on Linux, macOS, and Windows. 

For Linux, Bazel can be installed easily from Bazel official webpage. After installing, bazel (e.g ``bazel-1.0.0``) will be located in ``usr/bin`` and command ``bazel`` will be available. If command ``bazel`` is not available, set up environment variable:

```sh
sudo ln -s /usr/bin/bazel-1.0.0 /usr/bin/bazel
```

### Build the first program

Organize a workspace folder for C source code with the following architecture:

```
|--main.c
|--WORKSPACE
|--BUILD
```

``main.c`` is the source code.

``WORKSPACE`` can be left empty when there is no specific requirement

``BUILD``:

```
cc_binary(
    name = "test_bazel",
    srcs = ["main.c"],
)
```

``cc_binary`` specifies for C/C++ source code. ``test_bazel`` is the build target.

To build: ``bazel build test_bazel``

If building successfully, the workspace architecture will be:

```
|--bazel-bin
|--bazel-C_workspace
|--bazel-out
|--bazel-testlogs
|--main.c
|--WORKSPACE
|--BUILD
```

To run the built program: ``bazel run test_bazel``

### Build specific component

This architecture will help a project to have multiple components, in this case the component is ``main``:

```
|--main
	|--main.c
	|--BUILD
|--WORKSPACE
```

``BUILD`` and ``main.c`` are kept like above.

Build component ``main``: ``bazel build //main:test_bazel``

Run component ``main``: ``bazel run //main:test_bazel``

### Build with header files/library files

```c
|--main.c
|--head.c
|--head.h
|--WORKSPACE
|--BUILD
```

Now change ``BUILD`` file to:

```
cc_library(
    name = "library_name",
    srcs = ["head.c"],
    hdrs = ["head.h"],
)

cc_binary(
    name = "test_bazel",
    srcs = ["main.c"],
    deps = [
        ":library_name",        
    ],
)
```

``main.c``, ``head.c`` and ``head.h`` are all defined in [GCC compiler: Build source file](https://github.com/TranPhucVinh/C/blob/master/Introduction/Environment/GCC%20compiler.md#build-source-file)

To build: ``bazel build test_bazel``

To run: ``bazel run test_bazel``

**Build with header files/library files inside specific folder**: Check [cJSON implementation in C](https://github.com/TranPhucVinh/C/blob/master/Introduction/Data%20structure/JSON/README.md) for that implementation.

``include`` keyword in ``BUILD`` file is used to include the general folder for ``include`` in C source code like ``#include "header.h``. With ``includes = ["cJSON-1.7.15"],`` in ``BUILD`` file, user can call ``#include "cJSON.h"`` instead of ``#include "cJSON-1.7.15/cJSON.h"``

### Read file when running bazel build

```
|--main.c
|--test.json
|--WORKSPACE
|--BUILD
```

In order to read file ``test.json`` in ``main.c`` when running bazel build source code, field ``data`` has to be added.

```
cc_binary(
    name = "test_bazel",
    srcs = ["main.c"],
    data = ["test.json"],
)
```

With file ``test.json`` inside folder ``file`` and ``BUILD`` file like this:

```
|--main.c
|--file
	|--test.json
|--WORKSPACE
|--BUILD
```

```
cc_binary(
    name = "test_bazel",
    srcs = ["main.c"],
    data = ["file/test.json"],
)
```

Running the bazel build file will result in error:

```
Unable to open file test.json
```

**Problem solved**:

``BUILD`` in ``file``:

```
exports_files(["test.json"])
```

``BUILD`` in main workspace:

```
cc_binary(
    name = "test_bazel",
    srcs = ["main.c"],
    data = ["//file:test.json"],
)
```

To read ``test.json`` inside folder ``file``, the source code now need to change to:

```c
printf("%s\n", read_file("file/test.json"));
```
