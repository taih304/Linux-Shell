### If else

With ``==`` operator

```sh
a=10 
b=20 
  
#Check whether they are equal 
if [ $a == $b ] 
then 
    echo "a is equal to b"
fi 
  
#Check whether they are not equal 
if [ $a != $b ] 
then 
    echo "a is not equal to b"
fi 
```

```
a is not equal to b
```

With ``-gt``

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

``elif``:

```sh
if TEST-COMMAND1
then
  STATEMENTS1
elif TEST-COMMAND2
then
  STATEMENTS2
else
  STATEMENTS3
fi
```

**String compare**

```sh
string1="hello world"
string2="hello world 1"
if [ "$string1" == "$string2" ]
then 
	echo "A and B is equal"
else	
	echo "A and B is not equal"
fi
```

**Error/Warning**

If using ``if [ $string1 == $string2 ]``, there will be a warning:

```
./test.sh: line 5: [: too many arguments
```

This happens because ``$string`` is a string containing spaces or other special characters, and single square brackets are used (which is a shortcut for the test command), then the string may be **split out into multiple words**. Each of these is treated as a separate argument.
