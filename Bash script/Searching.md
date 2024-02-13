# wildcard

Wildcards are **special characters** that can **stand in for unknown characters in a text value** and are handy for locating multiple items with similar, but not identical data. Another common use of wildcard characters is to **create regular expressions**.

Wildcards has specific character definition/features on each fields, e.g Unix, Microsoft, other IoT platforms like ThingsBoard

Unix defines 3 wildcards ``*``, ``?`` and ``[]``.

``*`` : search for a particular character(s) for zero or more times.

E.g: ``wh*`` finds what, white, and why, but not awhile or watch.

E.g: ``ls /etc/*release*`` will result in ``/etc/lsb-release``  and ``/etc/os-release``

``?`` : search for a fixed number of characters as every "?" stand for one character

E.g: ``b?ll`` finds ball, bell, and bill.

``ls`` support wildcard
# Regular expression
A regular expression (**regex**) is **a sequence of characters that define a search pattern**.

**The asterisk symbol** ( * ) will match the preceding character (or set of characters) for 0 or more times (upto infinite).

E.g: **ab*c** will give ac, abc, abbc, abbbc,...

**The plus symbol** ( + ) will repeat the preceding character (or set of characters) at at least one or more times (up to infinite).

E.g: **ab+c** will give abc, abbc, abbc,...

**[first-last] character range**: Matches any single character in the range from first to last. E.g **[a-zA-z]** will match any character from a to z or A to Z.

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

**Note**: Must not use ``grep $space_value README.md`` (without ``""`` is totally wrong).

## -A and -B

To print the heading and trailing lines after the match:

* ``-A num``: print ``num`` lines of trailing context after each match.
* ``-B num``: print ``num`` lines of leading context before each match

```sh
grep "space value" README.md -A 10 -B 10
```

## -e and --regexp

``-e, --regexp=PATTERN``: use ``PATTERN`` for matching

E.g: ``grep -e "PATTERN" README.md`` will search for any string which include ``PATTERN`` in ``README.md``

## -i and --ignore-case

``-i, --ignore-case``: ignore case distinctions

E.g: ``grep -i "os" README.md`` will search for any string which include ``os``, ``oS``, ``Os`` and ``OS`` in ``README.md``

## -v and --invert-match

``grep -v "PATTERN" README.md``: Find all lines in file ``README.md`` that doesn't include ``PATTERN``.

## Examples with grep

``echo "test" | grep 't'``: print out where character ``t`` existed in ``test``.

``ls | grep "t"``: display all folder has "t" in its name

``dmesg | grep tty``: list the current connected devices

``du -h|grep 'G'``: list all files in GB size

# zgrep

The ``zgrep`` command is used to search out expressions from a given a file even if it is compressed.

``zgrep "Hello, World" test.zip``: Search for ``Hello, World`` inside ``test.zip``

Using ``zgrep`` to searching a zip file has two disadvantages:

1. It can only search the first file within the zip file.
2. It doesn’t list the file name.

E.g: ``zip test.zip main.c main.cpp``, then using ``zgrep`` can only search in ``main.c`` and can't search in ``main.cpp``

# zipgrep

``zipgrep`` works like ``zgrep``, except it can search in all files inside the compressed file and print out the named of the file where the search pattern is found.

``zipgrep "Hello, World" test.zip``: Search for ``Hello, World`` inside all compressed file of ``test.zip``

# find
Find file ``ubuntu_kernel_module.ko`` in a specific path
```c
find /lib/modules/* -name ubuntu_kernel_module.ko
```
/lib/modules/4.15.0-142-generic/kernel/ubuntu/ubuntu_kernel_module.ko

Find file ``README.md`` in the current directory

```sh
find $PWD -type f -name README.md
```

* ``type``: type of file, ``f`` for file, ``d`` for directory

# fzf

``fzf`` is a command line fuzzy finder for performing fuzzy search. ``fzf`` is not supported in Ubuntu 16.04 while Ubuntu 20.04 well supported fzf.

``sudo apt-get install fzf`` fails in Ubuntu 16.04.
