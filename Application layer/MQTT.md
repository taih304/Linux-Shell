## MQTT.js

If ``MQTT.js`` is install, command ``mqtt`` is available for Bash.

## Mosquitto

### MQTT client install

Mosquitto client: ``sudo apt install mosquitto-clients``

* ``-h``: host to connect to.
* ``-d``: enable debug message
* ``-t``: MQTT topic
* ``-u``: username
* ``-f``: file
* ``-m``: message
* ``-v``: print publish message verbosely
* ``-p``: port
* ``-P``: password

### Send data to a MQTT broker

MQTT cloud: ``broker.emqx.io``

```sh
mosquitto_pub -h broker.emqx.io -t "test/message" -m "Hello, World !"
```

```sh
mosquitto_sub -h broker.emqx.io -t "test/message"
```

As testing on April 26th 2020, MQTT cloud ``mqtt.eclipse.org`` and ``iot.eclipse.org`` no longer work.

As testing on April 15th 2021, MQTT cloud ``test.mosquitto.org`` no longer works.

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

### WebSocket is disabled

According to [Mosquitto broker conf docs](https://mosquitto.org/man/mosquitto-conf-5.html), Websockets support is currently disabled by default at compile time. So you will need to build a version of Mosquitto from source for websocket support.