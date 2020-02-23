```sh
function_test(){
    echo "Hello, World!"
}

function_test
```

**Result**: ``Hello, World!``

**Function with parameters**

```sh
function_test(){
    echo "parameter 1 is $1 and parameter 2 is $2"
}

function_test para1 para2
```

**Result**: ``parameter 1 is para1 and parameter 2 is para2``

**Function with return value**

```sh
function_test(){
    return 10
}

function_test
echo $? #10
```