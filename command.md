Linux Shell Command
===================

**pwd**
print working directory

=> print the current working directory

**ls**

print out all the folder in current directory

ref: s1ep1

* ls -l 

list in long format: show more detail of the file

you can see many information like rw-rw-r-- : stand for read-write/read-write....

take this for example:

-rw-rw-r-- 1 anonymous anonymous 450 Sep 23 04:17 command.md

start with -: mean it is a file

if start with d: it is a directory


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
