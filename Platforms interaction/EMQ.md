Publish data

```sh
mosquitto_pub -h broker.emqx.io -t "test/message" -m "Hello, world"
```

Subscribe to a topic

```sh
mosquitto_sub -h broker.emqx.io -t "test/message"
```