### cd

``cd ../..``: change to previous folder

``cd`` to another folder can be perform with ``./folder_name``: ``cd ./folder_name``

### echo

Check ``Introduction.md`` in ``Bash script/Variable`` for ``echo`` document.

### alias

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