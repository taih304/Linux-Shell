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