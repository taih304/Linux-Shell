If ``MQTT.js`` is install, command ``mqtt`` is available for Bash.

### Send data to a MQTT broker

MQTT cloud: ``broker.emqx.io``

```sh
mqtt pub -t "topic_name" -h "broker.emqx.io" -m "Hello, World !"
```

```sh
mqtt sub -t "topic_name" -h "broker.emqx.io" -v
```