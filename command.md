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

**list all devices**

cd /dev/

ls

**NOTE**

you can combine:

ls -l -a

ls -la

ref: s1ep3

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

**File permission**

the typical file permission is; trwxrwxrwx

with t: type: - :a file
d: directory
l: symbolic link

the next 3 group is for the owner,the owners group, and all users.

if a "-" (dash) mean a permission (r,w,x) is denied

e.g:

-rw-rw-r-- :it is a file, owner and both read and write the file, owner group can read and write, all user can read the file

=> no user can execute the file

ref: s1ep4

**mkdir**

make a directory (a folder)

mkdir <name of folder>

**cp**

copy

for example, we have a folder terrorist

cp test terrorist

=> we copy the file test to folder terrorist

ref s2ep1

**rm**

rm stands for remove: used to remove a file, not directory

rm <name of file>

rm * : to remove everything on the directory

ref s2ep1

**rmdir**

remove directory

you can only use this command to remove an empty directory

**rm -r**

rm -r is used to remove a non-empty directory

rm -rv (or rm -r -v) : remove a non-empty directory with detailed information like: remove <name of file>

to remove sudo file: sudo rm -rv <name of file>

**mv**

move a file from a directory to other

ref s2ep1

**wildcard**

* : alias

? : every "?" stand for one character

s2 ep: usage of 

**wc**

word count. used to count words in a file

wc -w <name of file>

wc -w: print words count

wc -l :print newline count

to know all of wc, type "man wc"

**create new document**

touch <name of document. extednd>

e.g: touch index.html

**grep**

grep 'character' <file to lookup': look for character/strings in a specific file

**pipe**

| is used for pipe

e.g: 

echo "terrorist" | grep 't'
result: terrorist

ls | grep "t"

result: (every folder has "t")

Desktop
Documents
examples.desktop
get-pip.py
iot-starter-book
microbit-book
Pictures
sketchbook
Templates

grep -i "<word>" <file to search> : ignore the uppcase in search

**cat**

cat [option] [file] : display content of a file

cat <name of file1> <name of file2> ; display the content of 2 file

cat > (name of file) : create a file

e.g: cat >terminal1 : create file terminal1
Then the terminal will wait for you to type the content of the file, after finishing, type Ctrl+D

**open file**: gnome-open <name of file>
  
**sudo lshw**: list hardware
