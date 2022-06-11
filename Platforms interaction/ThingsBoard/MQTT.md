## Telemetry

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

## RPC

Print out the MQTT response message when changing state in Switch control widget:

```sh
mosquitto_sub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/rpc/request/+" -u "TTf3zmVacJI4dUQsYQwh"
```

MQTT RPC with **Basic GPIO panel** is not yet implemented. Check [the corresponded example in ESP-IDF](https://github.com/TranPhucVinh/ESP-IDF/blob/master/Platforms%20interaction/ThingsBoard/MQTT/rpc_gpio_control.c) for its implementation or [the corresponded example in Python](https://github.com/TranPhucVinh/Python/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#rpc) for easier implementation with JSON.

## MQTT device profile

### Change MQTT Telemetry topic filter of a MQTT device profile

**Step 1**:  Edit the **Telemetry topic filter** to any value, e.g ``mqtt_device_profile``.

**Step 2**: Add the newly created device profile to an existed device. User can then send MQTT telemetry to that device with the new MQTT topic, e.g ``mqtt_device_profile``:

```
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "mqtt_device_profile" -u "TTf3zmVacJI4dUQsYQwh" -m "{'number': 12}"
```
