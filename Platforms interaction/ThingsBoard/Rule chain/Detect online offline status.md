# Features

Dashboard with GPIO panel widget to detect device online/offline status:

* If a TCP client sends any telemetry data to that ThingsBoard device, status is online
* If there isn't any TCP client sending telemetry data to that ThingsBoard device for an interval of time, status is offline

Inactive timeout for a device is set by default to 600 seconds (10 minutes). A user can overwrite this parameter for an individual device by setting the ``inactivityTimeout`` server-side attribute (value is set in milliseconds).

In this example, we will set ``inactivityTimeout`` to 6000 for 6 seconds as if there is no TCP client sending telemetry data in 6 seconds, the device will be offline.

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/detect_online_offline_status.png)

[Script filer](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Platforms%20interaction/ThingsBoard/Rule%20chain#script) **check device name** will filter the inactivity device to be the device that we wish to detect the online/offline status

```js
return metadata.deviceName == "Test device";
```

To turn on/off the GPIO on the Basic GPIO widget, we will set the attributes for it (normally like [the way GPIO panel widget work](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/Widget.md#gpio-panel-widget)) by using the [Save attributes rulechain](https://github.com/TranPhucVinh/Linux-Shell/tree/master/Platforms%20interaction/ThingsBoard/Rule%20chain#save-attributes). As Save attribute expects messages with ``POST_ATTRIBUTES_REQUEST`` message type, we will use [script transformation]() to setup ``msg`` and ``msgType``:

For online status:

```js
var online_status = {"1":true};

return {msg: online_status, metadata: metadata, msgType: "POST_ATTRIBUTES_REQUEST"};
```

For offline status:

```js
var offline_status = {"1":false};

return {msg: offline_status, metadata: metadata, msgType: "POST_ATTRIBUTES_REQUEST"};
```

Attachments:

* [Flowchart file](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Attachments/root_rule_chain_to_detect_online_offline_status.json)

# Testing

Send Telemetry data with both MQTT message publish or HTTP POST request will result in status online

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/telemetry" -u "TTf3zmVacJI4dUQsYQwh" -m "{'uid': 12}"
```

```sh
curl -v -X POST -d "{\"temperature\": 25}" "http://thingsboard.sysats.tech/api/v1/TTf3zmVacJI4dUQsYQwh/telemetry" --header "Content-Type:application/json"
```
