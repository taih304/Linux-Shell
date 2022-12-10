# ThingsBoard API reference

ThingsBoard API consists of two main parts: [device API](https://github.com/TranPhucVinh/ESP8266-Arduino-framework/blob/master/Platforms%20interaction/ThingsBoard/Device%20API.md) and server-side API.

Server-side API is available as REST API.

ThingsBoard support Swagger, a webpage to test its API. To access the Swagger webpage, add ``/swagger-ui`` after the ThingsBoard host. E.g ``demo.thingsboard.io/swagger-ui/``

## Server-side API

### JWT Tokens

ThingsBoard uses JWT tokens for representing claims securely between the API client (browser, scripts, etc) and the platform. When you login to the platform, your username and password is exchanged to the pair of tokens. 

The main token is short-lived token you should use to perform the API calls. The refresh token is used to get new main token once it is expired. The expiration time of main and refresh tokens is configurable in system settings via JWT_TOKEN_EXPIRATION_TIME and JWT_REFRESH_TOKEN_EXPIRATION_TIME parameters. Default expiration time values are 2.5 hours and 1 week respectively.

Script to get a JWT

```sh
curl -X POST --header 'Content-Type: application/json' --header 'Accept: application/json' -d '{"username":"tranphucvinh96@gmail.com", "password":"iotdev_admin"}' 'http://THINGSBOARD_URL/api/auth/login'
```

## Examples

**Precondition**: All examples below are performed on Swagger webpage (``/swagger-ui``).

### Get all devices of a customer

**Step 1**: Login with customer account, then get customerID by ``/api/auth/user``

**Step 2**: In ``Device Controller``, get all devices information with ``/api/customer/{customerId}/deviceInfos{?deviceProfileId,page,pageSize,sortOrder,sortProperty,textSearch,type}``

* ``customerId``: customerId of the currently signed in customer
* ``pageSize``: Maximum amount of entities in a one page. E.g ``0``
* ``page``: Page to view in ``pageSize``. View page from ``0`` to ``pageSize-1``. E.g: ``page = 0`` to view all existed devices of a customer in the first page.

### Get all devices token of a customer

**Step 1**: Get ``deviceID`` by parsing the JSON returned from get all devices information API (Example **Get all devices of a customer**)

**Step 2**: Use ``deviceID`` to get access token from API ``/api/device/{deviceId}/credentials`` (Get Device Credentials: ``getDeviceCredentialsByDeviceId``)

# Application layer protocols

* HTTP
* MQTT
* [FOTA operations implmented by HTTP and MQTT](#FOTA)

## FOTA

**OTA update** tab in ThingsBoard allow user to upload a ``.bin`` firmware from PC to it for the later OTA process.

After assigning the OTA firmware (``.bin`` file) to a device, that OTA firmware will later have an URL assigned to it.

For example, the ``.bin`` file is uploaded and then named as ``test_device_firmware_v1`` with ``version=0.1.0``, it will then have the URL: ``http://thingsboard.sysats.tech/api/v1/TTf3zmVacJI4dUQsYQwh/firmware?title=test_device_firmware_v1&version=0.1.0``. Pasting this link on web browser will then download that firmware to PC.

# Attributres

ThingsBoard has attributes value for all of its entity like device, customer, assets,...

### Server attributes

**Server attributes** allow CRUD operation on admin webpage and by API.

### Client attributes

**Client attributes** is only available on device. Client attributes are not allowed user to CRUD on the admin webpage but those operation can be performed by API on 
Device API Controller

**Example 1**: Work with device attributes (client attributes)

Create a new client attributes or update value for an existed attribute ``/api/v1/{deviceToken}/attributes`` with POST method (Perform on Swagger UI)

Request body:

```json
{
 "test_field":"test_field"
}
```

Then a new client attributes is created ``test_field`` or the existed ``test_field`` attribute is updated.

Get all attributes of an existed device: ``/api/v1/{deviceToken}/attributes{?clientKeys,sharedKeys}`` with GET method

* ``deviceToken``: access token of a device
* ``clientKeys``: Client key that wished to query, e.g ``test_field``
* ``sharedKeys``: Give it any random value if there is no shared key, e.g ``0``

**Example 2**: Client attribute can be created and update by [MQTT API](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#attributes) ``v1/devices/me/attributes``.

```sh
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/attributes" -u "TTf3zmVacJI4dUQsYQwh" -m "{\"1\":\"123\"}"
```

**Note**: By default setup of [Save attributes widget](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/Rule%20chain/README.md#save-attributes) in root rule chain, this MQTT publish message will be updated to client attributes. Update the Save attributes widget in root rule chain for Server attributes or Shared attributes updated.

### Share attributes

**Share attributes** are attributes with value that can be shared to the shared value input widgets in dashboard like ``Update shared double attribute``, ``Update shared integer attribute``,... It allows user to CRUD on the admin webpage and by API.

**Example**: Create a double share attribute of a device then connect it to the ``Update shared double attribute`` widget in dashboard

**Step 1**: In device share attributes, click Add button to create a share attribute:

* **Key**: The share attribute name for later used in ``Update shared double attribute`` widget in dashboard, e.g ``node_1_share_attributes``	
* **Value type**: Choose **Double**
* **Double value**: Start setting double value here

**Step 2**: In dashboard, from ``Input widgets`` choose ``Update shared double attribute``. In that widget, choose the share attribute key setup in step 1, e.g ``node_1_share_attributes`` in this case.

### Get client and shared attributes

In order to request client-side or shared device attributes to ThingsBoard server node, send ``PUBLISH`` message to the following topic:

```sh
v1/devices/me/attributes/request/$request_id
```

where ``$request_id`` is your integer request identifier. Before sending ``PUBLISH`` message with the request, client need to subscribe to

```sh
v1/devices/me/attributes/response/+
```

Pure command-line implementation for this are not available because subscribe and publish need to happen in the same mqtt session. So this script will never work:

```sh
#This script won't work
mosquitto_sub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/attributes/response/+" -u "TTf3zmVacJI4dUQsYQwh"
mosquitto_pub -d -h "thingsboard.sysats.tech" -t "v1/devices/me/attributes/request/1" -u "TTf3zmVacJI4dUQsYQwh" -m "{'clientKeys':'1,2', 'sharedKeys':'fw_title,fw_version'}"
```

For Node.js MQTT implementation to get client attributes ``1`` and ``2`` and shared attributes ``fw_title`` and ``fw_version`` of a device, check [the corresponding source code in Node.js](https://github.com/TranPhucVinh/Node.js/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#get-client-and-shared-attributes).

# Widget

Check [Widget document](Widget.md) for specific widgets implementations

# Rule chain

**Root rule chain** is the rule chain that define all operations of ThingsBoard and is chosen as root by default. Any rule chain chosen as root will have its rule deployed to ThingsBoard. If **root rule chain** is not chosen as root, operations like Telemetry can't be implemented.

Check [rule chain document](Rule%20chain) for other rule chain implementation.

# Device profile

Device profile ``default`` is applied to all devices by default with all protocol supported by ThingsBoard. Device profile ``default`` can't be deleted.

A new device profile can be created and supported edit. User can add this newly created device profile to a device.

Device profile defines 2 wildcard ``+`` and ``#``. ``+`` corresponds to ``*`` in Unix.

For **MQTT device profile**, check [MQTT device profile document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#mqtt-device-profile).
