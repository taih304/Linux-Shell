``seq 1 10``: Print out from 1 to 10

### Add operator

```shell
a=0
a=$((a+9))

echo $a #result: 9
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
