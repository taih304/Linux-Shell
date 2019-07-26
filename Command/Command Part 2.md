### Open libreoffice doc

```shell
libreoffice --writer file.odt
```

or 

```shell
libreoffice --writer file.doc
```

### Cannot open /dev/ttyUSB0: Permission denied

```shell
sudo chmod -R 777 /dev/ttyUSB0
```