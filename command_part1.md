### Delete with ``rm``

rm stands for remove: used to remove a file, not directory

``rm <name of file>``

``rm *`` : to remove everything on the directory

**rmdir:** remove directory

you can only use this command to remove an empty directory

**rm -r**

``rm -r`` is used to remove a non-empty directory

``rm -rv`` (or rm -r -v) : remove a non-empty directory with detailed information like: remove <name of file>

to remove sudo file: ``sudo rm -rv <name of file>``

**mv**

move a file from a directory to other

Rename: 

``mv <name_want_to_change> <name_wish_to_change>``

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

### Creating new document

```
touch <name of document. extednd>
```
```
touch index.html
```

### Text editor:

```
nano <name of file want to create>
```

```shell
nano index.html
```

**grep**

grep 'character' <file to lookup': look for character/strings in a specific file

**pipe**

| is used for pipe

e.g: 

```shell
echo "terrorist" | grep 't'
```

result: terrorist

ls | grep "t"

**result: (every folder has "t")**
```
Desktop
Documents
examples.desktop
get-pip.py
iot-starter-book
microbit-book
Pictures
sketchbook
Templates
```
grep -i "<!word>" <!file to search> : ignore the uppcase in search

### cat

``cat [option] [file]`` : display content of a file

``cat <name of file1> <name of file2>``: display the content of 2 file

cat > (name of file) : create a file

e.g: cat >terminal1 : create file terminal1

Then the terminal will wait for you to type the content of the file, after finishing, type Ctrl+D

**open file**: 

```shell
gnome-open <!name of file>
```

**sudo lshw**: list hardware

```shell
ls --help
man ls
```

#### Move file, copy file to different location

```shell
sudo nautilus
```

Open the folder with root permission, then just drop and drag

### Find Out Which Process Is Listening Upon a Port

```shell
netstat -tulpn
```
