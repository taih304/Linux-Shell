array=("Hello, World !" 1 2 3)

printf "Please enter the index value of array:"
read changedIndex
printf "Please enter the value to change in array[$changedIndex]:"
read changedValue

array[$changedIndex]=$changedValue

for value in "${array[@]}"
do
    echo $value
done