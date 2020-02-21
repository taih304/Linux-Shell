``Ctrl+Alt+F1``: enter textmode

``Ctrl+Alt+F7``: switch back to desktop

Add new user (this require admin privilege): 

``$ sudo useradd``

Issue ``User is not in the sudoers file. This incident will be reported.``

```bash
$ sudo nano /etc/sudoers
```

Go to ``#User privilege specification``, then add 

```
new_user_name ALL=(ALL:ALL) ALL
```

### Command

``who``: show how many user has log in the system

``date``

``hostname``

``shutdown``

``cd .local/share/Trash``: Go to trash folder
