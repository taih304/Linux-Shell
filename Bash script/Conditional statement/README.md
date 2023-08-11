# [If else](If%20else.md)
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

Using syntax like C:
```sh
i=0
while (($i < 10)) #Must be (()); () will give compilation error
do
    echo $i
    i=`expr $i + 1`
done
```
Using ``[]`` and ``-lt``:
```sh
i=0
while [ $i -lt 10 ]
do
    echo $i
    i=`expr $i + 1`
done
```
``while true``:
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
# trap

``trap handler_function condition_code``

``condition_code`` has value:

* ``0``: On exit from shell
**Example**: Execute a function after pressing exit with trap command
```sh
exit_function(){
	echo "exit function"
}

trap exit_function 0

while [ true ]
do
	echo "1"
done	
```

**Result**: Print ``exit function`` when pressing exit in shell
