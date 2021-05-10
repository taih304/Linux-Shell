``nc``: arbitrary TCP and UDP connections and listens

### Example 1 

TCP communication between 2 clients

``nc -l 8000``: Start listening on port 8000. This will listen for only one connection on port 8000. After receiving and finishing its first connection, the command will stop.

Then other TCP client (like ESP8266, ESP32 or another terminal console) can starts sending data to it.

For another TCP client in another terminal console 2: ``nc 127.0.0.1 8000``. This will listen to the IP ``127.0.0.1`` on port 8000. 

Then every thing typed in every console will be broad cast to the others.

``nc -kl 8000``: Forces ``nc`` to stay listening for another connection after its current connection is completed.

For a TCP client that sends a string to netcat TCP client: Check ``TCP client.md`` in ``ESP8266-Arduino-framework/Application layer/``

### Example 2

Sending data

``nc -l 8000 < data.csv``: TCP server sends ``data.csv`` to every TCP client which listens to it.

``nc 127.0.0.1 8000 < data.csv``: TCP client sends ``data.csv`` to every TCP client which it is listening to.