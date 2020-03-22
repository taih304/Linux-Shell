. nfc_reader_lib.sh

mqtt_broker="mqtt.eclipse.org"
mqtt_topic="test/message"

#Clean up temp/hidden file when exit
trap cleanup_temp_file 0

while [ true ]
do
    nfc_reader_init
    nfc_start_reading
    publish_data $mqtt_broker $mqtt_topic
done