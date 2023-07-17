# Makefile with $(CC)

Makefile supports ``$(CC)``, which by default is ``gcc`` and ``cc`` command:
```Makefile
build_gcc:
	@($(CC) main.c)
```
Or:
```Makefile
build_gcc:
	@(cc main.c)
```
Target ``build_gcc`` will run ``gcc main.c``.
# Makefile without $(CC)

**Run a makefile to echo a string and compile C source code**

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

**Compile a C program and list all files**

```Makefile
GCC = gcc
file = test.c
LS = ls

compile:
	$(GCC) $(file)

list:
	$(LS)
```

**Working with header files**

Compile source code ``main.c`` with header files ``header.h`` and source ``head.c`` to executable file ``main``

```Makefile
GCC = gcc
main = main.c
head = head.c 

.PHONY: main

main:
	@($(GCC) $(main) $(head) -o main)

clean:
	@(rm main)
```

Target ``main`` will compile ``main.c``. Target ``clean`` will remove ``main`` (executable file)
