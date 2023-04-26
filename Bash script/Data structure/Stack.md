# pushd and popd

Linux and [Windows](https://github.com/TranPhucVinh/Windows-Batch) support a stack to store the directories implemented with ``cd`` command.

``pushd dir_name`` will ``cd dir_name`` and push ``dir_name`` into the directory stack

``popd`` will ``cd ..`` and pop out the last member of the directory stack

```sh
tranphucvinh@tranphucvinh:~$ pushd # When first run, there is no folder inside the stack
bash: pushd: no other directory
tranphucvinh@tranphucvinh:~$ pushd Documents/ # Stack now has 2 folder ~/Documents and ~
~/Documents ~
tranphucvinh@tranphucvinh:~/Documents$ pushd Github/ # Stack now has 2 folder ~/Documents, ~ and ~/Documents/Github
~/Documents/Github ~/Documents ~
tranphucvinh@tranphucvinh:~/Documents/Github$ popd # pop out the last member ~/Documents/Github, stack now has 2 member 
~/Documents ~
tranphucvinh@tranphucvinh:~/Documents$ popd # pop out the last member ~/Documents, stack now has 1 member 
~
tranphucvinh@tranphucvinh:~$ popd # pop out the last member
bash: popd: directory stack empty
```
