### Feature

* NRF reader reads information from NFC tags and sends to MQTT broker
* Read UID

### Technical

* Core: Shell interaction with ``pcsc_tools`` package
* MQTT broker: mqtt.eclipse.org
* NFC reader: ACR122U

MQTT client listens for data: ``mosquitto_sub -h mqtt.eclipse.org -t "test/message"``

### Backlog

* Bug: No card is inserted
* Bug: Card has been removed
* Print out user unfriendly message