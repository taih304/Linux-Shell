### Telemetry

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -f "telemetry-data-as-object.json"
```

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -m "{'uid': 12}"
```

On local server with specific port:

```shell
mosquitto_pub -h 172.16.8.58 -p 1884 -t "v1/devices/me/telemetry" -u "qdpLoC8hu4Y6CgsXhaY9" -m "{\"mqtt-number\": 0}" -d
```

### RPC

MQTT RPC is not yet implemented. Check [the corresponded example in ESP-IDF](https://github.com/TranPhucVinh/ESP-IDF/blob/master/Platforms%20interaction/ThingsBoard/MQTT/rpc_gpio_control.c) for its implementation or [the corresponded example in Python](https://github.com/TranPhucVinh/Python/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#rpc) for easier implementation with JSON.
