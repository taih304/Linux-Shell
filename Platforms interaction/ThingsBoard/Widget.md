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
