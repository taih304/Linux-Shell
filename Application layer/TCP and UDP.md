``nc``: arbitrary TCP and UDP connections and listens

### Example 1 

Receives data from another TCP client.

``nc -l 8000``: Start listening on port 8000. This will listen for only one connection on port 8000. After receiving and finishing its first connection, the command will stop.

Then other TCP client can starts sending data to it.

**TCP client**:

* Terminal console

In other terminal console: ``nc 127.0.0.1 8000``. This will listen to the IP ``127.0.0.1`` on port 8000. 

Then every thing typed in every console will be broad cast to the others.

``nc -kl 8000``: Forces ``nc`` to stay listening for another connection after its current connection is completed.

* ESP8266: For a TCP client that sends a string to netcat TCP client: Check ``TCP client.md`` in ``ESP8266-Arduino-framework/Application layer/``

* Web browser: Type ``localhost:8000`` on web browser, then ``nc -l 8000`` will print out the response.

### Example 2

Sending data to another TCP client.

``nc -l 8000 < data.csv``: TCP server sends ``data.csv`` to every TCP client which listens to it.

``nc 127.0.0.1 8000 < data.csv``: TCP client sends ``data.csv`` to every TCP client which it is listening to.

**Note**: Those commands just send the file only one time, even if putting with ``nc -kl``. To send the file forever:

```sh
while [ true ]
do
    nc -l 8000 < data.csv
done 
```
