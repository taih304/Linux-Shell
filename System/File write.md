Keep on appending data to ``data.csv``

```sh
echo "test" >> data.csv
```

```sh
printf "test \n" >> data.csv
```

### awk

Print every line in the file

```sh
awk '{print}' filename
```

Field data ``data.md``

```
field1 field1Value
field2 field2Value
field3 field3Value
```

Read field1 ``awk '/field1/ {print}' data.csv``

**Result**: ``field1 field1Value``

For only argument 2 in field1: ``awk '/field1/ {print $2}' data.md``.

**Result**: ``field1Value``

### CSV data

``-F,``: ``,`` as seperator

**data.csv**

```
field1,field1Value
field2,field2Value
field3,field3Value
```

``awk -F, '{print $2}' data.csv``: Print argument 2 value of csv file.

Append parsed/read value to file ``result.csv``. ``awk`` can use regular expression to get data.

``[<:]`` will get all value between 2 character ``<`` and ``:``.

```sh
awk -F'[<:]' '{print $2}' test.csv >> result.csv
```
**Notice**:

* ``awk`` doesn't work with ``echo``.
* All variables inside ``awk`` only existed in its scope.