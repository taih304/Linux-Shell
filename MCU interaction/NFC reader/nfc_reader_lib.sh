. nfc_reader_predefined.sh

#Init hidden file .test.scriptor
nfc_reader_init(){
    echo -e $scriptor_file_content > ./.test.scriptor
    chmod 777 .test.scriptor
}    

#Execute .test.scriptor to read and save NFC tag value
nfc_start_reading(){
    ./.test.scriptor | grep "<" > .rawValue.csv
    awk -F'[<:]' '{print $2}' .rawValue.csv > .readUID.csv
}

publish_data(){
    while read textLine; do
    mosquitto_pub -d -h $1 -t $2 -m "$textLine"    
    done < .readUID.csv
}

cleanup_temp_file(){
    rm -rf .*
}