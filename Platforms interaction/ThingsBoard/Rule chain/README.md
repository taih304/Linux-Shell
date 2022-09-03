# Filter

## Message type switch

Message type switch will switch the message type for implementation in the next nodes.

Message type switch basic implementation can be found in the **Root Rule Chain**, where it switchs the types like **Post attributes**, **Post telemetry**, etc to the corresponding blocks.

## Script filter

Script filter returns a condition statement (with ``true``/``false`` value).

Its default implementation is:

```js
function Filter (msg, metadata, msgType){
    return msg.temperature > 20;
}
```

Please notes that the return of ``function Filter()`` must be a conditional statement and must not be any raw value like a single string or JSON object. If return the invalid value, there will be error when implement the nodes behind the script filter.

Be not to confuse **Script filter** to **Script transformation**.

# Action

## Action alarm

Check [alarm document](Alarm.md) for implementation with **Create alarm** and **Clear alarm**.

## Action generator

* [Action generator](Generator.md)

# Examples

* [Threshold setup for alarm](Alarm%20and%20threshold.md)
