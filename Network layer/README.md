### Proxy

Error when installing other package on Linux or Linux Docker

For example, install ``Node.js`` on Debian docker container

```
E: Failed to fetch http://deb.debian.org/debian/pool/main/n/nodejs/nodejs_4.8.2~dfsg-1_amd64.deb
Hash Sum mismatch
```

This might be a proxy error

To set up proxy from terminal

```shell
export http_proxy=http://10.10.10.10:8080
```

To unset proxy: ``unset http_proxy`` (follow the command above)
