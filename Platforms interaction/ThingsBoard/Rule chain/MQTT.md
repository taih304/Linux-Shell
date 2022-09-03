## Features

Publisher: Publish a MQTT message to any device on telemetry topic ``v1/devices/me/telemetry`` to trigger Post telemetry message type.

Subscriber: Subsribe to the EMQ broker topic to receive the message returned from ``script transformation`` block

## Implementations

**Step 1**: Set message type switch to Post telemetry

**Step 2**: Use ``script transformation`` to redirect the received MQTT message to the MQTT external node

In this case, use the default script:

```js
function Transform(msg, metadata, msgType){
    return {msg: msg, metadata: metadata, msgType: msgType};
}
```

**Step 3**: In MQTT externel node, setup parameters:

* Name: (give any name)
* Topic pattern: ``mqtt_test_node_thingsboard`` (Give any name to this MQTT topic)
* Host: broker.emqx.io
* Port: 1883
* Credential: If choose Anonymous, give no username as there is no authentication. If choose Basic, provide username

Rule chain

![](../../../Environment/Images/mqtt_external_rule_chain.png)

Then add it to root rule chain

![](../../../Environment/Images/mqtt_external_root_rule_chain.png)

**Step 4**:

**Publisher**:

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/telemetry" -u "lWMLHJCyb9zPNMMpXQkI" -m "{'data': 'Hello, World'}"
```

With ``lWMLHJCyb9zPNMMpXQkI`` is the access token/MQTT username of a device to trigger the Post telemetry message type

**Subscriber**:

```sh
mosquitto_sub -h "broker.emqx.io" -t "mqtt_test_node_thingsboard"
```

With the ``script transformation`` setup like above, subscriber will receive ``{'data': 'Hello, World'}``.

To send a specific string to MQTT external node every time Post telemetry message type is triggered, change the ``script transformation`` like this:

```js
function Transform(msg, metadata, msgType){
    var data = {
        "field_1": "Field 1",
        "field_2": "Field 2"
    };
    return {msg: data, metadata: metadata, msgType: msgType};
}
```