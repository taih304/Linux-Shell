### If else

```sh
a=9
b=10
if [ $a -gt $b ] 
then 
	echo "A is greater than B" 
else 
	echo "A is less than B" 
fi
```

```
A is less than B
```

```sh
string1=""
string2="hello world 1"
if [ $a -ne $b ] 
then 
	echo "A and B is not equal" 
fi
```
```
A and B is not equal
```
### For loop

Print out all argument name

```sh
for value in $@
do
    echo $value
done
```

```sh
string="hello world"
for value in $string
do
    echo $value
done
```
**Result**:

```
hello
world
```

Print out from 1 to 10 with ``{1..10}``

```sh
for i in {1..10}
do
    echo $i
done
```

Add more string with ``{1..10}``

```sh
for i in "name "{1..10}
do
    echo $i
done
```
**Result**: ``name 1``, ``name 2``, ``name 3``,...

### While loop

Print out from 0 to 9

```sh
i=0
while [ $i -lt 10 ]
do
    echo $i
    i=`expr $i + 1`
done
```

### Until condition

```sh
i=0
until [ $i -eq 10 ]
do
    echo $i
    i=`expr $i + 1`
done
```

### break

Print out from 0 to 9, break the loop if variable i is equal to 6.

```sh
i=0
while [ $i -lt 10 ]
do
    echo $i

    if [ $i -eq 6 ]
    then
        break
    fi
    i=`expr $i + 1`    
done
```
