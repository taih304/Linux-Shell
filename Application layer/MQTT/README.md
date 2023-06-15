MQTT is a publish/subscribe model that runs over **TCP/IP sockets** or **WebSockets**. 

MQTT over WebSockets can be secured with TLS/SSL. You should only need to run **MQTT over websockets** if you intend to publish/subscribe to messages directly from **within webapps** (in page) or any other applications that don't want to use the 1883/8883 port and want to go over HTTP/HTTPS instead - this could be so that there is less of a chance of being blocked by a firewall (e.g. in a corporate network), as most firewalls will let HTTP traffic through.

Commercialized cloud service nowadays supporting updating data by either using a [REST GET or POST]() request or using MQTT Publish method. You can retrieve data from those clouds by using a REST GET request or MQTT Subscribe.

## When to use MQTT, instead of REST ?

In these scenarios, it is useful to use MQTT to update data to a cloud service:
* Your device is power-constrained, and you want lower battery consumption to send data.
* Your device connectivity is intermittent, and you have limited bandwidth usage.
* You want immediate updates of data posted to a channel.
* You want messages pushed to you instead of needing to poll the server for new messages.