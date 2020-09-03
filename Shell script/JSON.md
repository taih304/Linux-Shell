## JSON

Export JSON

```sh
a="{'field1': 10}"
echo $a
```

### Parse JSON with shell script

``jq`` is a command-line JSON processor.

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