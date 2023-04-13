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

Local environment variable can be implemented by [export](Environment%20variable.md#export-command), [set](Environment%20variable.md#set-command) and [PATH](Environment%20variable.md#path).

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
