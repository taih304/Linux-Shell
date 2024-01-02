**Bazel** is an open-source build and test tool similar to Make, Maven, and Gradle. Bazel is multi-platform. It runs on Linux, macOS, and Windows. 

For Linux, Bazel can be installed easily from Bazel official webpage. After installing, bazel (e.g ``bazel-1.0.0``) will be located in ``usr/bin`` and command ``bazel`` will be available. If command ``bazel`` is not available, set up environment variable:

```sh
sudo ln -s /usr/bin/bazel-1.0.0 /usr/bin/bazel
```

Binary built output of Bazel always has suffix ***_binary**, e.g [cc_binary](https://github.com/TranPhucVinh/C/blob/master/Environment/Bazel.md) for C and CPP, [py_binary](https://github.com/TranPhucVinh/Python/tree/master/Introduction#bazel) for Python.

Bazel doesn't support build folder to have space like ``~/home/username/Work in progress$``

# [C source files](https://github.com/TranPhucVinh/C/blob/master/Environment/Bazel.md)
# CPP source files

```
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
)
```

Then ``build`` and ``run`` normally like with C source files.
# Keywords
* **deps**: deps is used for dependancies in libraries, components and header files. Refer to their implementation on [Bazel for library in C](https://github.com/TranPhucVinh/C/blob/master/Environment/Bazel%20for%20library.md).
