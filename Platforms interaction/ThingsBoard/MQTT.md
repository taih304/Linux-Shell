### Send data

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -f "telemetry-data-as-object.json"
```

```sh
mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -m "{'uid': 12}"
```

### Control device with RPC

```sh
mosquitto_sub -d -h "10.1.0.160" -t "v1/devices/me/rpc/request/+" -u "zq487jvjoDkkXtkcna3A"
```