# For loop
Print out from 1 to 10:

Using syntax like C:
```sh
for ((i=1; i <= 10; i++)) #Must be (()); () will give compilation error
do
    echo $i
done
```
Using ``{1..10}``:
```sh
for i in {1..10}
do
    echo $i
done
```
Using ``seq``:
```sh
for index in $(seq 0 10)
do
    echo $index
done
```
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
Add more string with ``{1..10}``

```sh
for i in "name "{1..10}
do
    echo $i
done
```
**Result**: ``name 1``, ``name 2``, ``name 3``,...

# While loop

Print out from 0 to 9

```sh
i=0
while [ $i -lt 10 ]
do
    echo $i
    i=`expr $i + 1`
done
```

For infinite loop

```sh
while true 
do
   echo "true hello"
   sleep 1
done
```

Or ``while [ true ]``

# Until condition

```sh
i=0
until [ $i -eq 10 ]
do
    echo $i
    i=`expr $i + 1`
done
```

# break

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
