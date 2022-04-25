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