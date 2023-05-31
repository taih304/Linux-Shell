# Create

```sh
#Declare array value first
array[0]="hello"
array[1]=0

echo ${array[0]} #hello
echo ${array[1]} #0
```

## Set value for all member inside array with index

```sh
arraySize=10
for index in $(seq 0 `expr $arraySize - 1`)
do
    # echo $index
    array[$index]=$index
done

for value in ${array[@]}
do
    echo $value
done
```
To store proper decimal or hex value inside array:
```sh
dec_array=($((24)) $((0x00)) $((11)) $((255)))
hex_array=($((0x24)) $((0x00)) $((0x1A)) $((0x10)))
```

## Ask user to enter value of array
```sh
arraySize=3
for index in $(seq 0 `expr $arraySize - 1`)
do
    printf "Please enter value for array[$index]:"
    read enteredValue
    array[$index]=$enteredValue
done

for value in ${array[@]}
do
    echo $value
done
```
# Read
Read value of a string as an array:
```sh
str_arr="Hello, World !"
for value in ${str_arr[@]}
do
    echo $value
done
```
```
Hello,
World
!
```
Read value of an existed array by index

```sh
array=("text" 1 2)
echo ${array[0]} #text
```

For array size: ``echo "${#array[@]}"``

Read all values of an array

```sh
array=("Hello, World !" 1 2 3)
printf '%s\n' "${array[@]}"
```
Or
```sh
array=("Hello, World !" 1 2 3)
for value in "${array[@]}"
do
    echo $value
done
```

If define ``for value in ${array[@]}``, the result will be:

```
Hello,
World
!
1
2
3
```
Read a file then store into an array then display it:

```sh
str_arr=($(cat text.md))
for value in ${str_arr[@]}
do
    echo $value
done
```
# Update

Simple change:

```sh
array=("Hello, World !" 1 2 3)

array[1]=2
```

* ``updateArrayWithIndex.sh``: Change value of a member isnide an array by the entered index.

# Remove

```sh
array=("Hello, World !" 1 2 3)

unset -v 'array[0]'

printf '%s\n' "${array[@]}"
```
