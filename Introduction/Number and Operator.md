``seq 1 10``: Print out from 1 to 10

### Add operator

```shell
a=10
a=$((a+9))

echo $a #result: 19
```

```sh
a="hello"
a+=" world"
echo $a #hello world
```

### expr

```sh
echo $a `expr 1 + 3` #4
```
```sh
arraySize=10
echo $a `expr $arraySize + 3` #13
```