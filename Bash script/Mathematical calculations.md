Unix operating system provides ``expr`` and ``bc`` commands for doing arithmetic calculations.

### expr

```sh
echo `expr 1 + 3` #4
```
```sh
a=10
b=`expr $a + 3`
echo $b  #13
```

### bc

Enter ``bc`` on Terminal: Enter ``bc`` live execution mode. To quit that mode, type ``quit``

Arithmetic Operators

``echo "12+5"|bc`` or ``echo 12+5|bc``: ``17``

``echo "10^2"|bc``: ``100``

Set value for variable

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

Arithmetic expressions in a file and then execute by ``bc``.

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