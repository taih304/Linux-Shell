## Connect existed device to dashboard

Create button widget to control device

### Step 1

Create a new dashboard, and a new widget

### Step 2

A new widget can be, e.g ``Timeseries Line Chart``. After creaing a new widget, there will be a tab 
``Add Widget: Timeseries Line Chart``. In that tab, there will be 4 small tabs: `` Data``, ``Settings``, ``Advanced``, ``Actions``.

In tab ``Data`` -> ``Datasources``, press ``+Add`` button:

* **Type**: Entity
* **Parameter**: There are **Entity aliases** and **Filter**. Create a new **Entity aliases** or choose the existed **Entity aliases**. 
If there is no filter condition, leave **Filter** empty.

**Create a new Entity aliases**

* **Alias name**: Add the alias name
* **Filter type**: Single entity
* **Type**: Device. Then choose the device from the existed devices that wished to control

After creating the new Entity aliases, choose then **entity timeseries** to visualize data.

## Map widget

**Step 1**: Create a map form map widget, then connect the device to that widget

**Step 2**: Choose the timeseries from that device with valid longitude and latitude to be displayed as the longitude and latitude on the map.

**Implementation**: Not yet implemented on ESP8266 Arduino framework, check [the corresponding implementation in Python](https://github.com/TranPhucVinh/Python/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#map-widget).

## GPIO widget

For GPIO controlling with RPC, check [RPC document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/Device%20API.md#rpc).

### GPIO control save previous setup status

In the **Advanced tab** of **Basic GPIO Control** item, we have the setting section called **GPIO status request**

![](../../Environment/Images/gpio_status_request.png)

When dashboard initializes, this item publishs a MQTT message to topic **v1/devices/me/rpc/request/+** with an ID, its content is a JSON object include 2 keys that you see in the above settings. Below is an example for that case

```js
topic:  v1/devices/me/rpc/request/1680
message:  {"method":"getGpioStatus","params":"1"}
```

By response to back to the topic **v1/devices/me/rpc/response/1680** with the status of gpio state, we can change its status on the dashboard, thus save previous setup status with the status on the physical device. Noted that this content should also be published to **device attribute** topic for sync up the value that the dashboard takes for reference