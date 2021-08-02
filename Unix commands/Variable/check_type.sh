check_type(){
    printf "Please enter the value "
    read enteredValue
    if [ $enteredValue == 0 ] 
    then 
        echo "$enteredValue is integer" 
        return
    fi

    declare -i parsedValue
    parsedValue=$enteredValue

    if [ $parsedValue == 0 ] 
    then
        echo "$enteredValue is string" 
    else 
        echo "$enteredValue is integer"     
    fi
}

check_type