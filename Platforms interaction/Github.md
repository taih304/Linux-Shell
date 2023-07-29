# Command

## git reset

``git reset <file>``: Undo a previously git add file
  
``git reset --hard``: Reset (i.e clear/delete) all changes have set

Delete the most recent commit, keeping the work you've done: ``git reset --soft HEAD~1``

Delete the most recent commit, **destroying the work** you've done: ``git reset --hard HEAD~1``

## git clone

For an extremely large repository like [raspberrypi/linux](https://github.com/raspberrypi/linux), this cloning method will help saving memory space:

```sh
git clone --depth=1 -b rpi-5.10.y https://github.com/raspberrypi/linux
```

``--depth=1`` will clone that Git repo with the latest commit.

``git clone --progress``: Progress status is reported on the standard error stream by default when it is attached to a terminal, unless ``--quiet`` is specified. This flag forces progress status even if the standard error stream is not directed to a terminal.

## git remote

``git remote show origin``: Show origins of the cloned repository, like the Git repo URL.

## git show

View date of git commit ``cd329de``:

```sh
git show -s --format=%ci cd329de
```

Result: ``2023-04-08 13:16:44 +0700``

# Examples

## Set up specific version for local project when using a public repository

To set up a local project in PC which use a public repository, to use a specific version of that repository, check [the ESP-IDF implementation for this as this example set up the local project on PC to use a specific repository version of the ESP-IDF official Github](https://github.com/TranPhucVinh/ESP-IDF/blob/master/Environment/README.md#set-up-project-to-use-a-specific-repository-version-of-esp-idf-official-github).

## Switch from branch rpi-4.9.y to rpi-5.15.y of [raspberrypi/linux](https://github.com/raspberrypi/linux)

```sh
# In repo raspberrypi/linux branch rpi-4.9.y
tranphucvinh@tranphucvinh:~/Documents/Gitlab/linux$ git fetch --depth=1 origin rpi-5.15.y #Fetch branch rpi-5.15.y with the latest commit
tranphucvinh@tranphucvinh:~/Documents/Gitlab/linux$ git checkout FETCH_HEAD # Check out to the branch has fetched
tranphucvinh@tranphucvinh:~/Documents/Gitlab/linux$ git branch #List all existed branch
* (HEAD detached at FETCH_HEAD)
  rpi-4.9.y
tranphucvinh@tranphucvinh:~/Documents/Gitlab/linux$ git checkout -b rpi-5.15.y
Switched to a new branch 'rpi-5.15.y'
```

# Username login

``curl https://api.github.com/user -u user_name:password``

Example: ``curl https://api.github.com/user -u tranphucvinh:password``

**Output**: This will list out all user information.

**Note**: If not setting up **Personal access token**, use the login password for the ``password`` parameter. If setting up **Personal access token** (for later used with [.netrc file](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/.netrc.md), use that **Personal access token** for the ``password`` parameter.

# .netrc for Github

Authentication step can be setup by .netrc file, check [.netrc document with the example for Github](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/.netrc.md#setup-netrc-for-github).
