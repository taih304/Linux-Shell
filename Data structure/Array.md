### Create

```sh
#Declare array value first
array[0]="hello"
array[1]=0

echo ${array[0]} #hello
echo ${array[1]} #0
```

Set value for all member inside array with index
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
### Read

Read value of an existed array by index

```sh
array=("text" 1 2)
echo ${array[0]} #text
```
Read all values of an array
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
