### wildcard

``*`` : search for a particular character(s) for zero or more times.

``?`` : search for a fixed number of characters as every "?" stand for one character

### grep

``grep`` searches for PATTERN in each FILE.

```sh
grep [OPTIONS] PATTERN [FILE...]
```

``grep "i" test.sh``: find all character ``i`` in ``test.sh``

**Example**: Find a pattern include space in a file

```sh
grep "space value" README.md
```

```sh
space_value="space value"
grep "$space_value" README.md
```
Note: Must not use ``grep $space_value README.md`` (without "" is totally wrong).

``echo "test" | grep 't'``: print out where character ``t`` existed in ``test``.

``ls | grep "t"``: display all folder has "t" in its name

``dmesg | grep tty``: list the current connected devices

``du -h|grep 'G'``: list all files in GB size: 

**Note**: ``grep`` doesn't work properly with wildcard

### find

Find file ``README.md`` in the current directory

```sh
find $PWD -type f -name README.md
```

* ``type``: type of file, ``f`` for file, ``d`` for directory

### fzf

``fzf`` is a command line fuzzy finder for performing fuzzy search. ``fzf`` is not supported in Ubuntu 16.04 while Ubuntu 20.04 well supported fzf.

``sudo apt-get install fzf`` fails in Ubuntu 16.04.
