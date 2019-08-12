**variable**

to create a new variable

```shell
a=8
```

Note: if you type a = 9, or you leave space between the "=",this will be an error

error: command not found

**display**

```shell
echo a
```

```
result: a
```

```shell
echo $a
```

```
result: <value of a>
```

**string**

```shell
a = "string";
```

**()**

```shell
a=0
a=$((a+9))

echo $a
```

result: 9

REMEMBER: there is no () => WRONG

**Display problem**

```shell
a=29
b="this is $a"
echo $b
```

**Result**:

```
this is 29
```

```shell
c='this is $a'
```

**Result**: 

```
this is $a
```

**Display with echo**

```shell
echo "hello world"
```

**Result**:

```
hello world
```
