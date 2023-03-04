# Architecture

```
target: prerequisites
    <TAB> recipe
```    

* **target**: target name to run, e.g: ``make targetName``
* **prerequisites**: can be ``file names`` or ``targets``, and can seperated by spaces. If they are files, they need to exist before the commands for the target are run.
* **recipe**: recipe to perform when calling **target**. There must be a tab before recipe inside target.

# Run the very first makefile

```Makefile
target1:
	echo "target 1"
target2:
	echo "target 2"
```
If running ``make`` (with no specific target), the first target in the Makefile will be executed.

``make target1`` will output:

```
echo "target 1"
Hello
```

To avoid echoing (print out only ``Hello``) 

```Makefile
target1:
    @echo "target1"
```

Run a shell script and avoid echoing:

```Makefile
main: test
	@./test.sh
```

Work with command:

```Makefile
shell:
	@ls #list all file
	@cat main.c #open a file
```

``cd`` command is performed in a sub-process shell, and affects neither ``make`` nor the shell you're working from. This Makefile gives no effect and the folder doesn't change

```Makefile
shell:
	@(cd ..)
```

To work with other directory with ``cd``, take this example

```Makefile
all:
        cd Linux-Shell; echo "Linux Shell folder"; \
          gcc test test.c
```

To get the result of a shell command, add ``shell`` keyword:

```Makefile
shell:
	@echo $(shell ls -l)
```

Send argument to Makefile while running ``make``

```sh
target1:
	@echo $(target_1)
```

Run ``make``: ``make target_1="Hello 1"``

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

### Up to date error

If there is a file name ``test`` in the folder, running ``make test`` will result in error as

``make: 'test' is up to date.``

To avoid this problem you can explicitly declare the target to be phony by making it a prerequisite of the special target ``.PHONY``

```Makefile
.PHONY: test
test:
        @echo "Hello"
```	
### Operator

``?=``: This is called a conditional variable assignment operator, because it only has an effect if the variable is not yet defined

``:=``: Assignment operator like ``=``.

```Makefile
a:=10

main:
	@echo $a #10
```
