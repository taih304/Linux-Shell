### Feature

* ACR122U reads UID from NFC tags and sends to MQTT broker
* RFID card/NFC tag: 13.56 MHz

### Technical

* Core: Shell interaction with ``pcsc_tools`` package
* MQTT broker: mqtt.eclipse.org

MQTT client listens for data: ``mosquitto_sub -h mqtt.eclipse.org -t "test/message"``

### Backlog

* Bug: No card is inserted
* Bug: Card has been removed
* Print out user unfriendly message