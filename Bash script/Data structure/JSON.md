## JSON

Export JSON

```sh
a="{'field1': 10}"
echo $a
```

### jq

``jq`` is a lightweight and flexible command-line JSON processor. Download ``jq`` from [stedolan/jq](https://github.com/stedolan/jq)

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