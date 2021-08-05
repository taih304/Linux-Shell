Export JSON

```sh
a="{'field1': 10, 'field2': 'Hello, World'}"
b="{\"field1\": 10, \"field2\": \"Hello, World\"}"
echo $a
echo $b
```

## jq

``jq`` is a lightweight and flexible command-line JSON processor. Download ``jq`` from [stedolan/jq](https://github.com/stedolan/jq) or install using ``sudo apt-get install jq``.

**Example 1**: Parse field from a JSON string variable

```sh
a="{\"field1\": 10, \"field2\": \"Hello, World\"}"
b=$(echo $a|jq '.field1')
c=$(echo $a|jq '.field2')
echo $b #10
echo $c #Hello, World !
```
**Notice**: 

If declare ``a`` with ``'`` like this:

```sh
a="{'field1': 10, 'field2': 'Hello, World'}"
```

There will be error when parsing:

```
parse error: Invalid numeric literal at line 1, column 10
```

**Example 2**: Parse field from a JSON file

``jsonData.json``

```json
{
    "field1": 10,
    "field2": 20
}
```

Parse the JSON field then store the value in a variable:

```sh
a=$(cat jsonData.json|jq '.field1')
echo $a
```

**Result**: ``10``