# wc

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

# head

Output the first part of files

``head text.txt``: Read the first 10 lines of file ``text.txt``

``head -n`` with ``n`` is the specific number of first lines that wish to read

``head -2 text.txt``: Read the last 2 lines of file ``text.txt``

# tail

Output the last part of files

``tail text.txt``: Read the last 10 lines of file ``text.txt``

``tail -n`` with ``n`` is the specific number of last lines that wish to read

``tail -2 text.txt``: Read the last 2 lines of file ``text.txt``

# tac

``tac`` read a file from its last line to its first line

E.g: ``test.txt`` has content

```
1
2
3
4
```

Then ``tac test.txt`` will be:

```
4
3
2
1
```
# AWK

``Gawk``  is  the GNU Project's implementation of the ``AWK`` programming language, and is implemented with command ``awk``.

``awk -f filename.txt``: Read content of file ``filename.txt``

## Print every line in the file

```sh
awk '{print}' filename
```

Field data ``data.md``

```
field1 field1Value
field2 field2Value
field3 field3Value
```

Read field1 ``awk '/field1/ {print}' data.md``

**Result**: ``field1 field1Value``

For only argument 2 in ``field1``: ``awk '/field1/ {print $2}' data.md``.

**Result**: ``field1Value``

Store the result of ``awk`` as a variable:

```sh
string=$(awk '/field1/ {print $2}' data.md)
echo "string is $string"
``` 
## Working with CSV data

``-F,`` or ``-F","`` will treat ``,`` as separator

**data.csv**

```
field1,field1Value
field2,field2Value
field3,field3Value
```

``awk -F, '{print $2}' data.csv`` and ``awk -F"," '{print $2}' data.csv``: Print argument 2 value of csv file.

```sh
echo "field1,field1Value"| awk -F ',' '{print $2}' # field1Value
```
awk takes a string as a delimiter:
```sh
echo "field1,field1Value"| awk -F ",f" '{print $2}' # ield1Value
```
Append parsed/read value to file ``result.csv``. ``awk`` can use regular expression to get data.

``[<:]`` will get all value between 2 character ``<`` and ``:``.

```sh
awk -F'[<:]' '{print $2}' test.csv >> result.csv
```
**Notice**:

* ``awk`` doesn't work with ``echo``.
* All variables inside ``awk`` only existed in its scope.
