### HTTP server with netcat

Start a HTTP server (only first time load)

```sh
echo -e "HTTP/1.1 200\r\n\r\n hello world test again" | nc -l 8000
```

Start forever

```sh
while true;
do
   echo -e "HTTP/1.1 200\r\n\r\n hello world test again" | nc -l 8000
done
```

``echo -e``: enable interpretation of backslash escapes