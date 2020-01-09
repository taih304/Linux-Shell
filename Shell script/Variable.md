```shell
echo a #result a
```

**Error**

Note: if you type ``a = 9``, or you leave space between the "=",this will be an error

error: command not found

### Variable declare

```sh
a=10
echo $a #result: 9
unset a #unset value of a
echo $a #print out nothing
a="string"
echo $a #string
```

### Add operator

```shell
a=0
a=$((a+9))

echo $a #result: 9
```

### Represent pattern

```shell
a=29
b="this is $a"
echo $b #this is 29
```

### Command as variable

```sh
echo $(ls) #List out all file in current folder
```
