# [Fundamental concepts](Fundamental%20concepts.md)
* [Implementations of HTTP]()
* [HTTP with Non-Persistent Connections]()
* [HTTP with Persistent Connections]()
* [HTTP Message Format]()
* [Cookie]()
* [Web cache]()
* [REST](Fundamental%20concepts.md#rest)
# HTTP client

## cURL

### GET request

With HTTP server: ``curl -v -X GET example.com``

With HTTPS server: ``curl https://github.com``

Download an image from a HTTPS server: ``curl -o output_image_name.png image_URL``

E.g ``curl -o test.jpg https://vignette.wikia.nocookie.net/testwikia/images/4/44/png_image.png/revision/latest?cb=20200927143723``

``-L``: ``curl -L`` is used for login option, check [.netrc](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/Init%20script/.netrc.md) for this implementation.
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

``wget`` as a variable and store the downloaded file to a file: 

```sh
WGET=$(wget github.com -O -)
echo $WGET > test.md
```

## netcat

``-p``: Source port

With HTTP server:

``printf "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

``echo -e "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n" | nc example.com 80``

With HTTPS server: ``nc`` doesn't support HTTPS

## Wireshark

Filter HTTP request: ``http.request.method == GET``

## HTTrack

**HTTrack** is a free software allows you to download a World Wide Web site from the Internet to a local directory, building recursively all directories, getting HTML, images, and other files from the server to your computer.

Simply install httrack on Linux and type ``httrack`` on terminal to start the software.

With webstie that requires authentication, httrack will just only download the main site content (as it can't do authentication).

For example: httrack for ``https://smarthome-thesis-bku.herokuapp.com/`` will only download the main webpage that requires user to login

# HTTP server

**HTTPd**, which stands for HTTP daemon, is a background process to be a HTTP server.

## HTTP server with netcat

Start a HTTP server:

For only first time load:

```sh
echo -e "HTTP/1.1 200\r\n\r\n Hello, World !" | nc -l 8000
```

Start forever:

```sh
echo -e "HTTP/1.1 200\r\n\r\n Hello, World !" | nc -kl 8000
```

This will also print out the HTTP request from the HTTP client and return a string to the HTTP client.

```sh
while true;
do
   echo -e "HTTP/1.1 200\r\n\r\n Hello, World !" | nc -l 8000
done
```

To return environment variable: ``echo -e " HTTP/1.1 200\r\n\r\n$(date)" | nc 127.0.0.1 -kl 8000``

To return a HTML webpage: ``echo -e " HTTP/1.1 200\r\n\r\n$(cat index.html)" | nc 127.0.0.1 -kl 8000``

## HTTP server to print out the name of the routing perform by a HTTP client

```sh
while true;
do
    url=''
    echo -e "HTTP/1.1 200\r\n\r\n Hello, World !" | nc -l 8000 > text.temp
    url=$(awk '/GET/ {print $2}' text.temp)
    echo "url is $url"
done
```
# HTTPS

* [Get the valid certificate](HTTPS.md#get-the-valid-certificate), [case when valid certificate can't be gotten](HTTPS.md#cant-get-the-valid-certificate)
* [Wireshark](HTTPS.md#wireshark)
