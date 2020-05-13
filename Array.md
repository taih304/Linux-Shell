### Array

```sh
array=("text" 1 2)
echo ${array[0]} #text
```

```sh
#Declare array value first
array[0]="hello"
array[1]=0

echo ${array[0]} #hello
echo ${array[1]} #0
```