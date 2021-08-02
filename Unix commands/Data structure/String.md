Index from a string

```sh
string="Hello, World !"
echo ${string:1}  # ello, World !
echo ${string:1:0}# (empty)
echo ${string:1:1}# e
```

Size of a string:

```sh
string="Hello, World !"
echo ${#string}
```