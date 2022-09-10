**Bazel** is an open-source build and test tool similar to Make, Maven, and Gradle. Bazel is multi-platform. It runs on Linux, macOS, and Windows. 

For Linux, Bazel can be installed easily from Bazel official webpage. After installing, bazel (e.g ``bazel-1.0.0``) will be located in ``usr/bin`` and command ``bazel`` will be available. If command ``bazel`` is not available, set up environment variable:

```sh
sudo ln -s /usr/bin/bazel-1.0.0 /usr/bin/bazel
```

# C source files

Check [C source files document](C%20source%20files.md)

# CPP source files

```
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
)
```

Then ``build`` and ``run`` normally like with C source files.