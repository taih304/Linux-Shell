# == operator

```sh
a=10 
b=20 
  
# Check whether they are equal 
if [ $a == $b ] 
then 
    echo "a is equal to b"
fi 
  
# Check whether they are not equal 
if [ $a != $b ] 
then 
    echo "a is not equal to b"
fi 
```

```
a is not equal to b
```

Short form

```sh
a=10 
b=20 

[ $a == $b ] && echo "$a is equal to $b" || echo "$a is not equal to $b"
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

# ! operator

```sh
a=0

if [ !$a ] 
then 
    echo "a is 0"
fi 
```

With more than 1 condition, use ``[[]]``:

```sh
a=0
b=0

if [[ !$a && !$b ]] 
then 
    echo "a and b are both 0"
fi 
```

# String compare

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

``''`` can't be used in this case: 

```sh
if [ '$string1' == '$string2' ] #Wrong
```

# Flags

## -d

``-d``: Check if directory existed

```sh
if [ -d "folder_name" ]
then 
    echo "Directory exist"
else     
    echo "Directory not exist"
fi 
```

## -n

``-n``: Return true if value is not empty

```sh
if [ -n "" ]
then 
    echo "Value is not empty"
else     
    echo "Value is empty"
fi 

a=0

if [ -n $a ]
then 
    echo "a is not empty"
else     
    echo "a is empty"
fi 

b=1

if [ -n $b ]
then 
    echo  "b is not empty"
else     
    echo "b is empty"
fi 
```

```
Value is empty
a is not empty
b is not empty
```

## -z

``-z`` returns ``true`` if the string is empty. It only works for string, not number

```sh
if [ -z "" ]
then 
    echo "String is empty"
else     
    echo "String is not empty"
fi 

a=0

if [ -z $a ]
then 
    echo "a is empty"
else     
    echo "a is not empty"
fi 
```

```
String is empty
a is not empty
```
