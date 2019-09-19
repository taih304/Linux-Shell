``sudo lshw``: list hardware

``passwd username``: Change password

``du -h``: list out disk usage in MB

``df -h``: list size of hardware, and usage of percentage

### netstat

``netstat -tulpn``: Find Out Which Process Is Listening Upon a Port

### Cannot open /dev/ttyUSB0: Permission denied

```shell
sudo chmod -R 777 /dev/ttyUSB0
```

``df -i``: list all inode

### Error IUSE 100% in ``CentOS``

If error happen, CentOS will not allow user to ``yum install`` more file.

fix: ``sudo rm -rf /var/cache/*``
