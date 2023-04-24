Telnet is a network protocol used to virtually access a computer and to provide a two-way, collaborative and text-based communication channel between two machines.

Telnet has no security so all of its data is not encrypted so they can be eavesdropped easily. Telnet is later replaced by SSH, an application layer protocol which requires login with username and password, as well as encrypt the data while transfering.

Telnet can be used to perform HTTP request

Netcat HTTP simple server:

```sh
echo -e "HTTP/1.1 200\r\n\r\n Hello, World !" | nc -l 8000
```

Get HTTP response by telnet

```
telnet 127.0.0.1 8000
```

Result

```
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
HTTP/1.1 200

Hello, World !
Connection closed by foreign host.
```
Send a HTTP request to a HTTP server with multiple routes

HTTP server: https://github.com/TranPhucVinh/Python/blob/master/Application%20layer/HTTP/HTTP%20server/Introduction.md#print-out-hello-world https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/simple_http_server.c

For a HTTP request with telnet, after setting the address, like ``telnet 127.0.0.1 8000``, start typing the HTTP request like ``GET / HTTP/1.1``.

The whole operation with the returned value will be:

```
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
GET / HTTP/1.1
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 30

Text responsed from TCP serverConnection closed by foreign host.
```
