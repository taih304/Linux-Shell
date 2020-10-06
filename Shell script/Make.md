``Make`` is a build automation tool. Its file format is ``Makefile``.

### Architecture

```
target: prerequisites
    <TAB> recipe
```    

* **target**: target name to run, e.g: ``make targetName``
* **prerequisites**: file names, seperated by spaces. These files need to exist before the commands for the target are run.

### Step by step

* **Step 1**: Go to the folder that you wanna create a ``Makefile`` then create a Makefile.
* **Step 2**: Run with command ``make``

**Example**: Run the very first makefile

```Makefile
main:
    echo "Hello"
```

**Output**: 

```
echo "Hello"
Hello
```

To avoid echoing (print out only ``Hello``) 

```Makefile
main:
    @echo "Hello"
```

Run a shell script and avoid echoing:

```Makefile
main: test
	@./test.sh
```

Run the a list of command in makefile

```Makefile
main:
	@ls #list all file
	@cat main.c #open a file
```

### Variable

Saving variable value inside a makefile target is not available

```Makefile
main:
	a=10
	echo $a
```

**Output** ``NULL`` (Expected ``10``)

**Problem solved**

```Makefile
a=10

main:
	@echo $a 
```    

**Output** ``10``

You can assign the variable value with space

```Makefile
a = 10 #space include

main:
	@echo $a 
```    

A variable in Makefile can store 2 value

```Makefile
a = 100 200

main:
	@echo $a
```

**Output** ``100 200``

### Example

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