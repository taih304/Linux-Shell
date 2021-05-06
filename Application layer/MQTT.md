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

### Send data to a MQTT broker

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

### WebSocket is disabled

According to [Mosquitto broker conf docs](https://mosquitto.org/man/mosquitto-conf-5.html), Websockets support is currently disabled by default at compile time. So you will need to build a version of Mosquitto from source for websocket support.