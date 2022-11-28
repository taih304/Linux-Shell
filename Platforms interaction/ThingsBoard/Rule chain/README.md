# Filter

* [message type switch](#message-type-switch)
* [script](#script)

## message type switch

Message type switch will switch the message type for implementation in the next nodes.

Message type switch basic implementation can be found in the **Root Rule Chain**, where it switches the types like **Post attributes**, **Post telemetry**, etc to the corresponding blocks.

## script

Script filter returns a condition statement (with ``true``/``false`` value).

Its default implementation is:

```js
function Filter (msg, metadata, msgType){
    return msg.temperature > 20;
}
```

Please notes that the return of ``function Filter()`` must be a conditional statement and must not be any raw value like a single string or JSON object. If return the invalid value, there will be error when implement the nodes behind the script filter.

Be not to confuse script **in filter** with script **in transformation**.

**Example**: Check [alarm document](Alarm.md) as script filter is a part of its implementation.

# Enrichment

* [Originator attributes](Originator%20attributes.md)

# Transformation

## Script

Check [MQTT external](MQTT.md) for implementation with Script transformation.

# Action

## Alarm

Check [alarm document](Alarm.md) for implementation with **Create alarm** and **Clear alarm**.

## Generator

Check [generator document](Generator.md) for implementation with **Generator** block.

## Save attributes

Save attributes rule chain is used to save the attributes of a device (by 3 type Client attributes, Server attributes and Shared attributes).

Thanks to save attributes widget in root rule chain, client attributes of each device is updated by POST attributes, by default.

For any POST attribute from client (e.g MQTT client) to be server attributes instead of client attributes (as default), simple change **Entity attribute scope** from **client attributes** to **server attributes**.

# External

## MQTT

Check [MQTT document](MQTT.md) for implementation with **MQTT** block.

# Examples

* [Threshold setup for alarm of 1 device](Alarm%20and%20threshold.md)
* [Threshold setup for alarm of multiple devices](Alarm%20and%20threshold%20for%20multiple%20devices.md)
* [Detect online/offline status]()
