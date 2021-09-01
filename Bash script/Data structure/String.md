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
echo $string3 #String 1String 2
```

Size of a string:

```sh
string="Hello, World !"
echo ${#string}
```