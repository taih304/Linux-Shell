# cURL

## GET request

With HTTP server: ``curl -v -X GET example.com``

With HTTPS server: ``curl https://github.com``

Download an image from a HTTPS server: ``curl -o output_image_name.png image_URL``

E.g ``curl -o test.jpg https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

``-L``: ``curl -L`` is used for login option, check [.netrc](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/.netrc.md) for this implementation.
## Get data from Python HTTP server

HTTP server: ``Python/Application layer/HTTP/HTTP server.md``

Python HTTP server return ``Hello, World`` on Web browser.

Shell script: ``curl -v -X GET localhost:8000``

Output result to a file: ``curl -v -X GET localhost:8000 > temp.md``

File ``temp.md`` will have ``Hello, World``.

## Send data to a HTTP server

Check ``HTTP.md`` in ``Platforms interaction/ThingsBoard``

**Send data to a Python HTTP server**

HTTP server: Check ``HTTP server`` in ``HTTP server receives data from client`` in ``Python/Application layer/HTTP/HTTP server.md``

Send data ``hello``: ``curl -v -X GET -d "hello" 192.168.0.103:8000``

# Wget

Download content from a URL to a file: ``wget -O test.md github.com``

Download an image from a URL that purely returns that image to a file: ``wget -O test.png https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

``wget`` as a variable and store the downloaded file to a file: 

```sh
WGET=$(wget github.com -O -)
echo $WGET > test.md
```

# netcat

``-p``: Source port

With HTTP server:

``printf "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

``echo -e "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

With HTTPS server: ``nc`` doesn't support HTTPS

# Telnet
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

HTTP server: [Python HTTP server](https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/simple_http_server.c)

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
# Wireshark

Filter HTTP request: ``http.request.method == GET``
