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

Set specific timestamp for a telemetry data, notice that the timestamp must be Unix timstamp in miliseconds:

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/telemetry" -u "rg6k7jyrX31SB36fgH9i" -m "{'ts':1451649600512, "values":{'number':1234}}"
```

Get timestamp by command and send:

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/telemetry" -u "rg6k7jyrX31SB36fgH9i" -m "{'ts':$(($(date +%s%N)/1000000)), 'values':{'value':'Hello, World !'}}"
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

Wildcard topic with ``+`` can be used, e.g ``v1/devices/+/telemetry``

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/abc/telemetry" -u "TTf3zmVacJI4dUQsYQwh" -m "{'number': 'abv'}"
```

However ``-t "v1/devices/+/telemetry"`` is not supported.

### Change MQTT Attributes topic filter of a MQTT device profile

**Step 1**:  Edit the **Attributes topic filter** to any value, e.g ``device_test_attributes``.

**Step 2**: In any implementation with attributes topic, like Basic GPIO panel, change the attribute topic to that newly changed value, e.g ``device_test_attributes``. All left operations then work as usual. 
