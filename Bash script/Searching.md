# wildcard

Wildcards are special characters that can stand in for unknown characters in a text value and are handy for locating multiple items with similar, but not identical data. Another common use of wildcard characters is to create regular expressions.

Wildcards has specific character definition/features on each fields, e.g Unix, Microsoft, other IoT platforms like ThingsBoard

Unix defines 3 wildcards ``*``, ``?`` and ``[]``.

``*`` : search for a particular character(s) for zero or more times.

E.g: ``wh*`` finds what, white, and why, but not awhile or watch.

E.g: ``ls /etc/*release*`` will result in ``/etc/lsb-release``  and ``/etc/os-release``

``?`` : search for a fixed number of characters as every "?" stand for one character

E.g: ``b?ll`` finds ball, bell, and bill.

``ls`` support wildcard

# grep

``grep`` searches for ``PATTERN`` in each ``FILE``:

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

To print the heading and trailing lines after the match:

* ``-A num``: print ``num`` lines of trailing context after each match.
* ``-B num``: print ``num`` lines of leading context before each match

```sh
grep "space value" README.md -A 10 -B 10
```

Note: Must not use ``grep $space_value README.md`` (without "" is totally wrong).

``echo "test" | grep 't'``: print out where character ``t`` existed in ``test``.

``ls | grep "t"``: display all folder has "t" in its name

``dmesg | grep tty``: list the current connected devices

``du -h|grep 'G'``: list all files in GB size: 

**Note**: ``grep`` doesn't work properly with wildcard

# find

Find file ``README.md`` in the current directory

```sh
find $PWD -type f -name README.md
```

* ``type``: type of file, ``f`` for file, ``d`` for directory

# fzf

``fzf`` is a command line fuzzy finder for performing fuzzy search. ``fzf`` is not supported in Ubuntu 16.04 while Ubuntu 20.04 well supported fzf.

``sudo apt-get install fzf`` fails in Ubuntu 16.04.
