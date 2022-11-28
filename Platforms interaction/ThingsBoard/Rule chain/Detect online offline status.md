# Features

Dashboard with basic GPIO widget to detect device online/offline status:

* If a TCP client sends any telemetry data to that ThingsBoard device, status is online
* If there isn't any TCP client sending telemetry data to that ThingsBoard device for an interval of time, status is offline

Handle this by rule chain.

# Testing

Send Telemetry data with both MQTT message publish or HTTP POST request will result in status online

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/telemetry" -u "TTf3zmVacJI4dUQsYQwh" -m "{'uid': 12}"
```

```sh
curl -v -X POST -d "{\"temperature\": 25}" "http://thingsboard.sysats.tech/api/v1/TTf3zmVacJI4dUQsYQwh/telemetry" --header "Content-Type:application/json"
```
