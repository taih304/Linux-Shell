# ThingsBoard API reference

ThingsBoard API consists of two main parts: [device API](https://github.com/TranPhucVinh/ESP8266-Arduino-framework/blob/master/Platforms%20interaction/ThingsBoard/Device%20API.md) and server-side API.

Server-side API is available as REST API:

* Administration REST API - The server-side core APIs.
* Attributes query API - The server-side APIs provided by Telemetry Service.
* Timeseries query API - The server-side APIs provided by Telemetry Service.
* RPC API - The server-side APIs provided by RPC Service.
* REST Client
* Python REST Client
* Dart API Client

## Server-side API

### JWT Tokens

ThingsBoard uses JWT tokens for representing claims securely between the API client (browser, scripts, etc) and the platform. When you login to the platform, your username and password is exchanged to the pair of tokens. 

The main token is short-lived token you should use to perform the API calls. The refresh token is used to get new main token once it is expired. The expiration time of main and refresh tokens is configurable in system settings via JWT_TOKEN_EXPIRATION_TIME and JWT_REFRESH_TOKEN_EXPIRATION_TIME parameters. Default expiration time values are 2.5 hours and 1 week respectively.

Script to get a JWT

```sh
curl -X POST --header 'Content-Type: application/json' --header 'Accept: application/json' -d '{"username":"tranphucvinh96@gmail.com", "password":"iotdev_admin"}' 'http://THINGSBOARD_URL/api/auth/login'
```

## Examples

### Get all devices of a customer

**Step 1**: Login with customer account, then get customerID by ``/api/auth/user``

**Step 2**: In ``Device Controller``, get all devices information with ``/api/customer/{customerId}/deviceInfos{?deviceProfileId,page,pageSize,sortOrder,sortProperty,textSearch,type}``

* ``customerId``: customerId of the currently signed in customer
* ``pageSize``: Maximum amount of entities in a one page. E.g ``0``
* ``page``: Page to view in ``pageSize``. View page from ``0`` to ``pageSize-1``. E.g: ``page = 0`` to view all existed devices of a customer in the first page.

### Get all devices token of a customer

**Step 1**: Get ``deviceID`` by parsing the JSON returned from get all devices information API (Example **Get all devices of a customer**)

**Step 2**: Use ``deviceID`` to get access token from API ``/api/device/{deviceId}/credentials`` (Get Device Credentials: ``getDeviceCredentialsByDeviceId``)

### Work with device attributes

Create a new client attributes or update value for an existed attribute: ``/api/v1/{deviceToken}/attributes`` with POST method

E.g of a request body:

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


# Attributres

## Device attributes

**Server attributes** allow user to edit and update on the admin webpage but those attributes are not allowed to be edited or get by API on 
Device API Controller

**Client attributes** are not allowed user to create and edit on the admin webpage but those operation can be performed by API on 
Device API Controller

**Share attributes** are attributes with value that can be shared to the shared value input widgets in dashboard like ``Update shared double attribute``, ``Update shared integer attribute``,...

**Example**: Create a double share attribute of a device then connect it to the ``Update shared double attribute`` widget in dashboard

**Step 1**: In device share attributes, click Add button to create a share attribute:

* **Key**: The share attribute name for later used in ``Update shared double attribute`` widget in dashboard, e.g ``node_1_share_attributes``	
* **Value type**: Choose **Double**
* **Double value**: Start setting double value here

**Step 2**: In dashboard, from ``Input widgets`` choose ``Update shared double attribute``. In that widget, choose the share attribute key setup in step 1, e.g ``node_1_share_attributes`` in this case.

# Widget

Check [Widget document](Widget.md) for specific widgets implementations

# Rule chain

Root rule chain is the rule chain that define all operations of ThingsBoard and is chosen as root by default. Any rule chain chosen as root will have its rule deployed to ThingsBoard. If root rule chain is not chosen as root, operations like Telemetry can't be implemented.

Check [rule chain document](Rule%20chain) for other rule chain implementation.

# Device profile

Device profile ``default`` is applied to all devices by default with all protocol supported by ThingsBoard. Device profile ``default`` can't be deleted.

A new device profile can be created and supported edit. User can add this newly created device profile to a device.

Device profile defines 2 wildcard ``+`` and ``#``. ``+`` corresponds to ``*`` in Unix.

For **MQTT device profile**, check [MQTT device profile document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/ThingsBoard/MQTT.md#mqtt-device-profile).
