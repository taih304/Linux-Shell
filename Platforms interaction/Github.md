### Command

To undo git add before a commit, run ``git reset <file>`` for a specific file or ``git reset .`` for all files.
  
Specify specific branch to clone with ``-b``, this will help saving times when cloning the extremely large repository.

```sh
git clone --depth=1 -b rpi-5.10.y https://github.com/raspberrypi/linux
```

``git reset --hard``: Reset (i.e clear/delete) all changes have set

### Username login

``curl https://api.github.com/user -u user_name:password``

Example: ``curl https://api.github.com/user -u tranphucvinh:password``

**Output**: This will list out all the relate API URL belong to the user.
