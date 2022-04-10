### register_component()

For each component, CMakeLists file calls ``register_component``, which calls the CMake ``add_library`` function to add a library and then adds source files, compile options, etc.

### set()

```c
set(<variable> <value>... [PARENT_SCOPE])
```

Set the given <variable> in the current function or directory scope.