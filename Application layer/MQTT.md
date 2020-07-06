### MQTT client install

Mosquitto client: ``sudo apt install mosquitto-clients``

* ``-h``: host to connect to.
* ``-d``: enable debug message
* ``-t``: MQTT topic
* ``-u``: username
* ``-f``: file
* ``-m``: message
* ``-v``: print publish message verbosely

### Send data to a MQTT broker

Send raw message to **ThingsBoard**

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -f "telemetry-data-as-object.json"
```

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -m "{'uid': 12}"
```

MQTT cloud: ``mqtt.eclipse.org``

```sh
mosquitto_pub -h mqtt.eclipse.org -t "test/message" -m "Hello, world"
```

```sh
mosquitto_sub -h mqtt.eclipse.org -t "test/message"
```

MQTT cloud ``test.mosquitto.org`` no longer works.

### Build MQTT broker with Mosquitto

Install: ``sudo apt install mosquitto``

Check mosquitto service status: ``sudo systemctl status mosquitto`` or ``sudo systemctl status mosquitto.service``

The MQTT broker now has already start, you can test by publish and subscribe:

Subscribe to topic ``test/message`` on ``localhost``:

```shell
$ mosquitto_sub -h localhost -t "test/message"
```

Publish a message to topic ``test/message`` on ``localhost``:

```shell
$ mosquitto_pub -h localhost -t "test/message" -m "Hello, world"
```
