# Operator

``?=``: This is called a conditional variable assignment operator, because it only has an effect if the variable is not yet defined

``:=``: Assignment operator like ``=``.

```Makefile
a:=10

main:
	@echo $a #10
```
# -C option

``-C DIRECTORY`` will change to DIRECTORY before doing anything. It will help running ``make`` inside a directory where  there is no **Makefile**.
```
work_directory
	|── Linux-Shell
		├── Makefile
		└── main.c
```
There is only **Makefile** inside **Linux-Shell** folder: 
```Makefile
all:
	gcc main.c
```
``-C DIRECTORY`` will allow running ``make`` command inside **work_directory** where there is no **Makefile**:

```sh
username@hostname:~/work_directory$ make -C "Linux-Shell"
make: Entering directory '/home/vinhtran/sm_git/sm-work-in-progress/Linux-Shell'
gcc main.c
make: Leaving directory '/home/vinhtran/sm_git/sm-work-in-progress/Linux-Shell'
```
Then ``a.out`` will be outputed inside **Linux-Shell**.

# Up to date error with ``.PHONY``

If there is a file name ``test`` in the folder, running ``make test`` will result in error as

``make: 'test' is up to date.``

To avoid this problem you can explicitly declare the target to be phony by making it a prerequisite of the special target ``.PHONY``

```Makefile
.PHONY: test
test:
        @echo "Hello"
```	
# lastword
``$(lastword name)``:  With ``name`` is a string separated by whitespace, ``lastword`` will return its lastword.

```Makefile
main:
	@(echo $(lastword Hello, World!))
```
**Result**: ``World!``

# dir

``dir`` returns the relative path of the directory of the file passed to it

```Makefile
target:
	@echo $(dir MAKEFILE_LIST)
```

``dir MAKEFILE_LIST`` will return the relative path of the directory of the ``$(MAKEFILE_LIST)``. If it is in the same folder location, the path will be ``./``
# abspath

``abspath`` returns the absolute path of the file passed to it

```Makefile
target:
	@echo $(abspath MAKEFILE_LIST)
```

``abspath MAKEFILE_LIST`` will return the absolute path of ``Makefile``.

# wildcard

```
work_directory
	├── Makefile
	└── main.c
```
This Makefile will build any .c file inside ``work_directory``
```Makefile
src := $(wildcard *.c)

default: $(src)
	@($(CC) $(src))
	@(./a.out)
```