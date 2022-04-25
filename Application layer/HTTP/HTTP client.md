## cURL

### GET request

With HTTP server: ``curl -v -X GET example.com``

With HTTPS server: ``curl https://github.com``

Download an image from a HTTPS server: ``curl -o output_image_name.png image_URL``

E.g ``curl -o test.jpg https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

### Get data from Python HTTP server

HTTP server: ``Python/Application layer/HTTP/HTTP server.md``

Python HTTP server return ``Hello, World`` on Web browser.

Shell script: ``curl -v -X GET localhost:8000``

Output result to a file: ``curl -v -X GET localhost:8000 > temp.md``

File ``temp.md`` will have ``Hello, World``.

### Send data to a HTTP server

Check ``HTTP.md`` in ``Platforms interaction/ThingsBoard``

**Send data to a Python HTTP server**

HTTP server: Check ``HTTP server`` in ``HTTP server receives data from client`` in ``Python/Application layer/HTTP/HTTP server.md``

Send data ``hello``: ``curl -v -X GET -d "hello" 192.168.0.103:8000``

## Wget

Download content from a URL to a file: ``wget -O test.md github.com``

Download an image from a URL that purely returns that image to a file: ``wget -O test.png https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

## netcat

With HTTP server:

``printf "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

``echo -e "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

With HTTPS server: ``nc`` doesn't support HTTPS

## Wireshark

Filter HTTP request: ``http.request.method == GET``
