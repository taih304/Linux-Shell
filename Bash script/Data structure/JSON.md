# Define array like a JSON/Hashmap

```sh
declare -A json_array

json_array["key_1"]="key 1"
json_array[1]=0

echo ${json_array["key_1"]} # key 1
echo ${json_array[1]} # 0
```
## Traverse to get all members of a map
```sh
declare -A Map
Map["key1"]="value1"
Map["key2"]="value2"
Map["key3"]="value3"

# Print all key-value pairs
for key in "${!Map[@]}"; do
    echo "Key: $key, Value: ${Map[$key]}"
done
```
## Count total duplicate elements inside an array
```sh
array=(5 7 9 9 10 11 13 13 13 16 1 5 -2 -2 -4 0)

declare -A Map

for value in ${array[@]}
do
    ((Map[$value]++))
done

for key in "${!Map[@]}"
do
    echo "Key: $key, Value: ${Map[$key]}"
done
```
# jq

``jq`` is a lightweight and flexible command-line JSON processor. Download ``jq`` from [stedolan/jq](https://github.com/stedolan/jq) or install using ``sudo apt-get install jq``.

## Parse field from a JSON string variable

```sh
a="{\"field1\": 10, \"field2\": \"Hello, World\"}"
b=$(echo $a|jq '.field1')
c=$(echo $a|jq '.field2')
echo $b #10
echo $c #Hello, World !
```
**Notice**: 

If define ``a`` with ``'`` like this:

```sh
a="{'field1': 10, 'field2': 'Hello, World'}"
```

There will be error when parsing:

```
parse error: Invalid numeric literal at line 1, column 10
```

## Parse field from a JSON file

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

## Change value of a field of a JSON variable

```sh
a="{\"field1\": 10, \"field2\": \"Hello, World\"}"
echo $a
b=`expr $(echo $a|jq '.field1') + 20`
a="{\"field1\": $b, \"field2\": \"Hello, World\"}"
echo $a
```
