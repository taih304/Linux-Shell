## Action: Generator

Create a rule chain to generate dummy data and send those data to a device

### Instructions

**Step 1**: Create a new rule chain. After creating, **don't need to set Root priviledge**

**Step 2**: Click on the newly created rule chain and open it. In **Action** tab, choose **generator**.

**Step 3**: An example to set up for a **generator** action. To send data to a specific device, e.g ``Node device 1``, in ``Originator Type``, choose ``Device``, then in ``Device``, choose ``Node device 1``

![](../../Environment/Images/rule_chain_action_generator_setup.png)

**Step 4**: Link the newly created **generator** block rule chain to the **Root rule chain**. Choose link label **Success**. 

Choose **Root rule chain** from **Flow** -> **rule chain**.

![](../../Environment/Images/rule_chain_action_generator.png)

Then press tick to enable the new rule chain.

### Result

With the set up in step 3, with JavaScript code:

```js
var msg = { temp: 42, humidity: 77 };
var metadata = { data: 40 };
var msgType = "POST_TELEMETRY_REQUEST";

return { msg: msg, metadata: metadata, msgType: msgType };
```

Then ``temp = 42`` and ``humidity=77`` will be send to device ``Node device 1`` for 1000 times in every 1 second. Go to device ``Node device 1`` to check the data.

To send random number from ``0`` to ``1`` to a device, take this script:

```js
var msg = { value: Math.random().toFixed(1) }; //to fix to limit to 1 number after ,
var metadata = { data: 40 };
var msgType = "POST_TELEMETRY_REQUEST";

return { msg: msg, metadata: metadata, msgType: msgType };
```

## Setup and clear alarm base on telemetry and threshold value

Create a rule chain to trigger and clear alarm when aquired value reaches a specific threshold define as a shared attribute of a device

**Step 1**: Create new rule chain ``setup_threshold`` and add all the necessary components

Get the **Script** in **Filter** and name it Check_node, its main duty is checking to see if the message comes from the right node

![](../../Environment/Images/script_Check_node.png)

And for this case, the content is **Node device 1**

```js
return metadata.deviceName == "Node device 1";
```

Get the **originator attributes** in **Enrichment** and name it Get_threshold, it will add the value for a specific key in device attribute to the metadata object

![](../../Environment/Images/originator_attributes.png)

The configuration is pretty straight foward, we enter the target attribute key we want to get, here is the **humi_th** which already added in Shared attributes section of **Node device 1**

![](../../Environment/Images/originator_attributes_config.png)

Get the second **Script** in **Filter** and name it Check_threshold, at this node we will compare the monitor value with the threshold

![](../../Environment/Images/script_Check_threshold.png)

As previously mentioned, the threshold value we get from Shared attributes will be added to metadata object with a prefix "**shared_**". Other prefix for client or server attributes is mentiond in thingsboard documents

```js
return msg.humidity > metadata.shared_humi_th;
```

For the last two node, get the **create alarm** and **clear alarm** from **Action**. All the configuration in these node are default

**STEP 2**: Link all the components follow this order

![](../../Environment/Images/setup_threshold.png)

**STEP 3**: Link the design rule chain to root rule chain

![](../../Environment/Images/root_rule_chain_for_threshold_setup.png)

We link it with the **Post telemetry** message type because we're checking the value from the post telemetry event

For threshold setup, user can set it on the shared attributes of the device and use the ``Update shared double attribute`` widget in dashboard.
