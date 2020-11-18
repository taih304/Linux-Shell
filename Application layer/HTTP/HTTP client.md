## HTTP client with cURL

### GET request

With HTTP server: ``curl -v -X GET arduino.vn``

With HTTPS server: ``curl https://github.com``

### Get data from Python HTTP server

HTTP server: ``Python/Application layer/HTTP/HTTP server.md``

Python HTTP server return ``Hello, World`` on Web browser.

Shell script: ``curl -v -X GET localhost:8000``

Output result to a file: ``curl -v -X GET localhost:8000 > temp.md``

File ``temp.md`` will have ``Hello, World``.

### Send data to a HTTP server

Check ``HTTP.md`` in ``Platforms interaction/ThingsBoard``

## HTTP client with Wget

Download content from a URL to a file: ``wget -O test.md github.com``

Download an image from a URL that purely returns that image to a file: ``wget -O test.png https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

## Wireshark

Filter HTTP request: ``http.request.method == GET``
