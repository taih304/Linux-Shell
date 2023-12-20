# Develop and test a component locally with C source code

With main.c inside ``artifacts/gg_core_device_component/0.0.1/main.c``, change ``Lifecycle`` of ``gg_core_device_component.json`` of ``recipes`` to:

```json
"Lifecycle": {
    "run": "gcc {artifacts:path}/main.c && ./a.out"
}
```
**Note**: In ``run``, after ``gcc {artifacts:path}/main.c``, the working directory of this subshell is ``/greengrass/v2/work/gg_core_device_component/`` (not ``{artifacts:path}``) and the built file ``a.out`` is also located inside that location.
# Avoid building source code in recipes script

In this component hierarchy

```sh
c_src_component
├── artifacts
│    └── c_src_component
│           └── 0.1.0
│               ├── main.c
│               └── Makefile
└── recipes
    └── c_src_component.json
```
``Makefile``
```make
build:
    gcc main.c // Must have sudo as the src code in artifacts is copied into /greengrass/v2/packages/artifacts/
```

``c_src_component.json``

```json
"Manifests": [
        {
            "Platform": {
                "os": "linux"
            },
            "Lifecycle": {
              "run": "sudo make -C {artifacts:path} build && ./a.out"
            }
        }
    ]
```

Then when deploying the component:

```sh
sudo /greengrass/v2/bin/greengrass-cli deployment create --recipeDir $(pwd)/recipes --artifactDir $(pwd)/artifacts --merge "c_src_component=0.1.0"
```
There will be error:
```sh
2023-12-20T03:49:35.035Z [WARN] (Copier) c_src_component: stderr. sudo: a terminal is required to read the password; either use the -S option to read from standard input or configure an askpass helper. {scriptName=services.c_src_component.lifecycle.run, serviceName=c_src_component, currentState=RUNNING}
```
Running sudo inside ``Makefile`` like this request entering password.

The only way to deal with this error is to **build the source code into excutable file**, e.g a.out, at first then simply run them in ``Lifecycle``. Must not build source code inside ``Lifecycle``.
