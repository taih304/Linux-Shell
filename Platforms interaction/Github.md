### Command

Specify specific branch to clone with ``-b``, this will help saving times with the repository is extremely large:

```sh
git clone --depth=1 -b rpi-5.10.y https://github.com/raspberrypi/linux
```

### Username login

``curl https://api.github.com/user -u user_name:password``

Example: ``curl https://api.github.com/user -u tranphucvinh:password``

**Output**: This will list out all the relate API URL belong to the user.