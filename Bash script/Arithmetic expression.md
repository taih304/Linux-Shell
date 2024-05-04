Unix operating system provides ``(( ))``, ``expr`` and ``bc`` commands for doing arithmetic calculations.

# (( ))

**Variable assignments**

```sh
((a=1 + 2)) #((a=1+2)) is still fine as space has no effect
echo $a #3
```
**Perform operation**
```sh
a=1
b=2
echo $((a + b))
sum=$((a + b))
echo $sum
```
**Test condition**
```sh
if ((3 < 4))
then echo "smaller"
else echo "greater"
fi
```
# expr

```sh
echo `expr 1 + 3` #4
```
```sh
a=10
b=`expr $a + 3`
echo $b  #13
```
# Modulus operator %
Print out all odd number between {1..99}
```sh
for i in {1..99}
do
    if (( $i % 2 != 0 ))
    then 
        echo $i
    fi
done
```
# bc

Enter ``bc`` on Terminal: Enter ``bc`` live execution mode. To quit that mode, type ``quit``

Arithmetic Operators

``echo "12+5"|bc`` or ``echo 12+5|bc``: ``17``

``echo "10^2"|bc``: ``100``

Set value for a variable

```sh
a=`echo 10+2|bc`
echo $a
```

Assignment Operators

``echo "var=10;var"|bc``: ``10`` (Must have ``""`` during assigment)

``echo "var=10;var+=1;var"|bc``: ``11``

Comparison operators:

``echo "1>2"|bc``: 0

``echo "1<2"|bc``: 1

**Floating point operation**

```sh
a=10
b=3
result=$(echo "scale=3; $a/$b" | bc)
echo "a/b: $result"
```
**scale=3** sets the number of decimal places to three for the result of the division.

Arithmetic expressions in a file and then executed by ``bc``.

* Use ``#`` and ``/* */`` for comments
* Support ``echo``  and ``print`` command inside text file

E.g: file ``test.txt`` )

```
18+5;
var = 10*3
var
echo var
print var
quit
```
