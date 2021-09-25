### wildcard

``*`` : alias

``?`` : every "?" stand for one character

### wc

``wc``: word count, used to count words in a file

```shell
$ wc -w filename #print total word in filename
```

**Result**: ``10 filename``

(``filename`` has 10 words)

```shell
$ wc -w test.sh
```
**Result**: ``10``

* ``wc -l``: print newline count

### head

Output the first part of files

``head text.txt``: Read the first 10 lines of file ``text.txt``

``head -n`` with ``n`` is the specific number of first lines that wish to read

``head -2 text.txt``: Read the last 2 lines of file ``text.txt``

### tail

Output the last part of files

``tail text.txt``: Read the last 10 lines of file ``text.txt``

``tail -n`` with ``n`` is the specific number of last lines that wish to read

``tail -2 text.txt``: Read the last 2 lines of file ``text.txt``