**Example 1**: Read value you enter and print out

**On terminal**

```bash
$ read enteredString
$ echo $enteredString
```

**Shell script**

```sh
printf "Enter a string"
read enteredString
echo "String is $enteredString"
```

**Example 2**: Excute a command

```sh
cd
cd Documents
ls -a
```

**Example 3**

``$?`` is used to find the return value of the last executed command. 

```sh
ls filename
echo $?
```

If filename exists (regardless whether it is a file or directory), you will get the return value thrown by the ls command, which should be 0 (default "success" return value).

**Example 4**

Print out ``Hello, World!`` after every 1 second with ``sleep``

```sh
while [ true ]
do
	echo "Hello, World!"
	sleep 1
done
```

**Example 5**

Execute a function after pressing exit with ``trap``

``trap handler_function condition_code``

``condition_code`` has value:

* ``0``: On exit from shell

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