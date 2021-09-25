A string can be defined with both ``""`` and ``''``. However:

``''`` is used when we don't want to evaluate variables to the values.

``""`` is used when all variables need to be evaluated and values should be assigned.

Check ``String compare`` in ``Bash script/Conditional statement/If else.md`` for the usage of ``""`` instead of ``''``.

Index from a string

```sh
string="Hello, World !"
echo $string   # Hello, World !
echo ${string} # Hello, World !
echo ${string:1}  # ello, World !
echo ${string:1:0} # (empty)
echo ${string:1:1} # e
echo ${string:1:2} # el
```

String concatenate:

```sh
string1="String 1"
string2="String 2"
string3=$string1$string2
string4=string3"string4"
echo $string3 #String 1String 2
echo $string4 #String 1String 4
```

Size of a string:

```sh
string="Hello, World !"
echo ${#string}
```