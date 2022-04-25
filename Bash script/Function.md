```sh
function_test(){
    echo "Hello, World!"
}

function_test
```

**Result**: ``Hello, World!``

Or function can define as:

```sh
function function_test(){
    echo "Hello, World!"
}

function_test
```
**Local variable**

```sh
a=190

change_value(){
    echo $a #190
    local a=23
    echo $a #23
}

change_value
```
**Global variable**: A global variable can be define inside a function

```sh
define_variable_b(){
    b=123
}

change_variable_b(){
    b=0
}

define_variable_b
echo $b #123
change_variable_b
echo $b #0
```

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
**Pass by value**: Can't implement
```sh
a=0

function_test(){
    $1="hello" #this is totally wrong
}

function_test $a
echo $a
```
**Result**
```
./test.sh: line 4: 0=hello: command not found
0
```
**Pass by reference**

Change value of a number variable by function

```sh
a=123

function_test(){
    local -n ref_var=$1
    ref_var=0
}

echo $a
function_test a #Must be function_test a, notfunction_test $a
echo $a
```
Change value of a string variable by function
```sh
a="Displayed string"

function_test(){
    local -n ref_var=$1
    ref_var="Hello, World !"
}

echo $a
function_test a
echo $a
```
