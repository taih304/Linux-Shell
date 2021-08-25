``seq 1 10``: Print out from 1 to 10

### + operator

```shell
a=10
a=$((a+9))

echo $a #result: 19
```

Or it can be: ``a=$(( a + 9 ))``

```sh
a="hello"
a+=" world"
echo $a #hello world
```

### XOR operator

```sh
a=1
b=$((a^=1))
echo $b #0
echo $a #0
```

### expr

```sh
echo `expr 1 + 3` #4
```
```sh
a=10
b=`expr $a + 3`
echo $b  #13
```