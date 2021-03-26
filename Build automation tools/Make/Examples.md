**Example 1**: Run a makefile to echo a string and compile ``C`` source code.

```Makefile
test:
	@echo a
	
build_c: 
	@(gcc test.c)

main: a.out	
	@./a.out
```

``make test``: a

``make main``: Result of ``a.out``

**Example 2**: Compile a C program and list all files

```Makefile
GCC = gcc
file = test.c
LS = ls

compile:
	$(GCC) $(file)

list:
	$(LS)
```

**Example 3**: ``cd`` command in a makefile

``cd`` command is performed in a sub-process shell, and affects neither ``make`` nor the shell you're working from.

To work with other directory with ``cd``, take this example

```
all:
        cd Linux-Shell; echo "Linux Shell folder"; \
          gcc test test.c
```
