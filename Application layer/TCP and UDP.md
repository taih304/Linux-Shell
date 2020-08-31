``nc``: arbitrary TCP and UDP connections and listens

### Communication between 2 terminal console

**Console 1**: (TCP server)

``nc -l 8000``: Start listening on port 8000

**Console 2**: (TCP client)

``nc 127.0.0.1 8000``: Listen to 127.0.0.1 on port 8000

Then every thing typed in every console will be broad cast to the others.

### Sending data

``nc -l 8000 < data.csv``: TCP server sends ``data.csv`` to every TCP client which listens to it.

``nc 127.0.0.1 8000 < data.csv``: TCP client sends ``data.csv`` to every TCP server which it is listening to.