. nfc_reader_lib.sh

mqtt_broker="mqtt.eclipse.org"
mqtt_topic="test/message"

nfc_reader_init
nfc_start_reading
publish_data $mqtt_broker $mqtt_topic

cleanup_temp_file