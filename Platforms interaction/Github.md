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

**Output**: This will list out all user information.

**Note**: If not setting up **Personal access token**, use the login password for the ``password`` parameter. If setting up **Personal access token** (for later used with [.netrc file](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/.netrc.md), use that **Personal access token** for the ``password`` parameter.

### .netrc for Github

Authentication step can be setup by .netrc file, check [.netrc document with the example for Github](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/.netrc.md#setup-netrc-for-github).
