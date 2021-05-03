### MQTT client install

Mosquitto client: ``sudo apt install mosquitto-clients``

* ``-h``: host to connect to.
* ``-d``: enable debug message
* ``-t``: MQTT topic
* ``-u``: username
* ``-f``: file
* ``-m``: message
* ``-v``: print publish message verbosely
* ``-P``: password

### Send data to a MQTT broker

MQTT cloud: ``mqtt.eclipse.org``

```sh
mosquitto_pub -h mqtt.eclipse.org -t "test/message" -m "Hello, world"
```

```sh
mosquitto_sub -h mqtt.eclipse.org -t "test/message"
```

MQTT cloud ``test.mosquitto.org`` no longer works.

As testing on April 26th 2020, MQTT cloud ``mqtt.eclipse.org`` and ``iot.eclipse.org`` no longer work.

### Build MQTT broker with Mosquitto

Install: ``sudo apt install mosquitto``. Default port is ``1883``.

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

Or pub/sub to the IP of the MQTT broker: ``mosquitto_sub -h 192.168.0.103 -t "test/message"``

**Note**: If attached the port like ``mosquitto_sub -h 192.168.0.103:1883 -t "test/message"`` or ``mosquitto_sub -h localhost:1883 -t "test/message"``, there will be error: ``Unable to connect (Lookup error.).``
