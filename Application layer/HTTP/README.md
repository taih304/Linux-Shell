# [Fundamental concepts](Fundamental%20concepts.md)
* [Implementations of HTTP]()
* [HTTP with Non-Persistent Connections]()
* [HTTP with Persistent Connections]()
* [HTTP Message Format]()
* [Cookie]()
* [Web cache]()
* [REST](Fundamental%20concepts.md#rest)
# [HTTP client](HTTP%20client.md)
* curl
* wget
* netcat
* telnet
* Wireshark
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
