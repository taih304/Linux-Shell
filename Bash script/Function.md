```sh
function_test(){
    echo "Hello, World!"
}

function_test
```

**Result**: ``Hello, World!``

### Function with parameters

**Example 1**

```sh
function_test(){
    echo "parameter 1 is $1 and parameter 2 is $2"
}

function_test para1 para2
```

**Result**: ``parameter 1 is para1 and parameter 2 is para2``

**Example 2**

Number variable as a function parameter

```sh
a=190

change_value(){
    echo "variable a is $1"
}

change_value $a
```
**Result**: ``variable a is 190``

String variable (even including spaces) as a function parameter

```c
a="Hello, World !"

change_value(){
    # $1="hello"
    echo "variable a is $1"
}

change_value "$a"
```
**Result**: ``variable a is Hello, World !``

### Function with return value

When a bash function completes, its return value is the status of the last statement executed in the function, ``0`` for success and non-zero decimal number in the ``1 - 255`` range for failure. You can't return a string in bash functions.

```sh
function_test(){
    return 10
}

function_test
echo $? #10
```

```sh
function_test(){
    return "02"$1
}

function_test 1
echo $? #21
```

## Value type and reference type.md

**Change value in normal way**

```sh
a=0

function_test(){
    a="hello"
}

function_test
echo $a #hello
```
