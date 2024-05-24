Shell builtins commands include: [alias](#alias), [cd](#cd), [echo](#echo), [test](#test), [unset](#unset) and [wait](#wait).

# cd

``cd ../..``: change to previous folder

``cd`` to another folder can be perform with ``./folder_name``: ``cd ./folder_name``

# [echo](Variable/User%20define%20variable.md#echo)

# alias

To setup an alias:

```sh
alias list=ls
```

Then this alias ``list`` will only last for the life of the shell session.

To list all ``alias``, type ``alias`` on the terminal.

To setup the regular use alias, set up them in the shell ``rc file``, such as ``.bashrc`` file.

To add a new alias: ``sudo nano ~/.bashrc``

Then add, for example an alias name ``get_idf``:

```c
alias get_idf='. /esp/esp-idf/export.sh'
```

Notice that ``alias`` must be used for command and must not use for system wide environment variables.

E.g:

Add this wrong line in ``bashrc``

```eg
alias PATH='/home/user/'
```

Then run ``echo $PATH`` will return empty

To set system wide environment variables value, use ``export``.

# test

``test`` is used for testing conditions. ``1`` for false and ``0`` for true

```sh
test 9 == 0
echo $? #1
test 9 = 0
echo $? #1
test 9 == 9
echo $? #0
test 9 = 9
echo $? #0
test 9==0 #Wrong condition compare
echo $? #0
test 9=0 #Wrong condition compare
echo $? #0
```
