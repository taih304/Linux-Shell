**Example 1**: Read value you enter and print out

**On terminal**

```bash
$ read enteredString
$ echo $enteredString
```

**Shell script**

```sh
echo "Enter a string"
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