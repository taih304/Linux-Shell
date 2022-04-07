**Bazel** is an open-source build and test tool similar to Make, Maven, and Gradle. Bazel is multi-platform. It runs on Linux, macOS, and Windows. 

For Linux, Bazel can be installed easily from Bazel official webpage. After installing, command ``bazel`` will be available.

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

To run: ``bazel build test_bazel``
