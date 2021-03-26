### Architecture

```
target: prerequisites
    <TAB> recipe
```    

* **target**: target name to run, e.g: ``make targetName``
* **prerequisites**: can be ``file names`` or ``targets``, and can seperated by spaces. If they are files, they need to exist before the commands for the target are run.

### Example

Run the very first makefile

```Makefile
main:
    echo "Hello"
```

**Output**

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

If running ``make`` (with no specific target), the first target in the Makefile will be executed.

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

### Make target

If there is a file name ``test`` in the folder, running ``make test`` will result in error as

``make: 'test' is up to date.``

To avoid this problem you can explicitly declare the target to be phony by making it a prerequisite of the special target ``.PHONY``

```Makefile
.PHONY: test
test:
        rm *.o temp
```	
### Operator

``?=``: This is called a conditional variable assignment operator, because it only has an effect if the variable is not yet defined
