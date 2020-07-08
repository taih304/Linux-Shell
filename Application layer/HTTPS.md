### Get the valid certificate

A valid digital certificate last for more than one year (the expire date can be checked easily)

Get the certificate: ``openssl s_client -connect demo.thingsboard.io:443 -showcerts``

Only the return certificate with ``Digital Signature Trust Co.,`` is valid, and can be used for HTTP client.

An example of a valid return certificate information:

```
1 s:C = US, O = Let's Encrypt, CN = Let's Encrypt Authority X3
   i:O = Digital Signature Trust Co., CN = DST Root CA X3
```

The valid certificate can also be get manually from Google Chrome:

Go to ``HTTPS URL`` -> ``Details`` -> ``Builtin Object Token_DST Root CA X3`` -> Export

### Can't get the valid certificate

``openssl`` sometimes can't get the valid certificate due to the proxy of the network, and its return certificate is invalid.

An example of an invalid return certificate information, due to Proxy:

```
0 s:/C=US/ST=somewhere/L=someplace/O=haproxy/OU=haproxy/CN=haproxy.selfsigned.invalid
i:/C=US/ST=somewhere/L=someplace/O=haproxy/OU=haproxy/CN=haproxy.selfsigned.invalid
```

**Example**: Get certificate from ``jsonplaceholder.typicode.com``

```sh
openssl s_client -connect jsonplaceholder.typicode.com:443 -servername jsonplaceholder.typicode.com -showcerts
```

If using: ``openssl s_client -connect jsonplaceholder.typicode.com:443 -showcerts``, there will be error: ``CONNECTED(00000003) 140035169920664:error:14077410:SSL routines:SSL23_GET_SERVER_HELLO:sslv3 alert handshake failure:s23_clnt.c:769:``
