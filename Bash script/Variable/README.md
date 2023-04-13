There are 2 types of shell variables:
* [User defined variable](#user-define-variable)
* [Environment variable or system variable](#environment-variable)

# [User define variable](User%20define%20variable.md)

* [echo](User%20define%20variable.md#echo): [-e]()

# [Environment variable](Environment%20variable.md)

Environment variable include:

* [Local environment variable](Environment%20variable.md#local-environment-variable)
* [User environment variable](Environment%20variable.md#local-environment-variable)
* [System wide environment variable](Environment%20variable.md#system-wide-environment-variables)
* [Status value](#status-value): [$?](#exit-status-), [$!](#-for-pid-of-background-process)

Local environment variable can be implemented by [export](Environment%20variable.md#export-command), [set](Environment%20variable.md#set-command) and [PATH](Environment%20variable.md#path).

## Status value

### Exit status $?

``$?``, known as **exit status**, returns the exit status of the latest executed command

* ``0``: Run successfully
* ``1``: Miscellaneous errors: file not existed, divide by zero, impermissible operations,...
* ``25``:	Inappropriate ioctl for device
* ``127``: command not found
* ``255\*``: Exit status out of range

```sh
ls
echo $? #0
```

```sh
ls filename
echo $?
```

If filename exists (regardless whether it is a file or directory), you will get the return value thrown by the ls command, which should be 0 (default "success" return value).

**Check if the script has successfully executed**

```sh
script_result=$?
if [ !$script_result ] 
then
    echo "Script executes successfully"
else
    echo "Script doesn't execute successfully"
fi
```
### [$! for PID of background process](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Process/Process%20command.md#-for-pid-of-background-process)
``$!`` returns the PID of the latest program run in the background.
# Variable types

Bash doesn't have variable types, types of variable are handled by ``declare`` command.

``declare`` will declare variables and give them attributes

E.g: ``declare variable_name``

If no variable names are given, ``declare`` will display the attributes and values of all variables.

* ``-i``: Set integer attributes for variable
* ``-p``: Display the attributes and value the variable

E.g:

```sh
declare -i num
num=42
```

Or ``declare -i num=42``. Then run ``declare``, we will see ``num=190`` along with other variables inside the system.

Then ``declare -p num`` will give: ``declare -i num="42"``

If ``num="Hello, World !"`` (string), then ``declare -p num`` will give: ``declare -i num="0"``

[check_type.sh](check_type.sh): Check type of the entered string, whether it is integer or string.
