Linux Shell Command
===================

**pwd**
print working directory

=> print the current working directory

**ls**

print out all the folder in current directory

ref: s1ep1

* ls -l 

list in long format: show more detail of the file/ list detail information

you can see many information like rw-rw-r-- : stand for read-write/read-write....

take this for example:

-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md

start with -: mean it is a file

if start with d: it is a directory

* ls -a
list all file and directory (including hidden files)

in the result, a file start with "." (dot) mean it is a hidden files

**NOTE**

you can combine:

ls -l -a

ls -la

**change permission**

4: for read
2: for write
1: execute

mode = 4+2+1 = 7: file can be read, write, execute

4+2: can be read and write
....

chmod: change mod

chmod <name of file/folder> mode

ref:s1ep2
