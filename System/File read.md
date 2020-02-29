### Read and print out every line of file

```sh
while read textLine; do    
    echo $textLine    
done < test.csv
```

### cat

``cat [option] [file]``: display content of a file on terminal

``cat filename1.md filename2.md``: display the content of 2 files

Using ``cat`` to create a new file then enter the value for it: ``cat > filename1.md``.

After finishing, type ``Ctrl+D`` or ``Ctrl+C``.

### less

``less file_name``: Read a file, the opened filename will be opened to cover the current terminal window.

### gnome to open a file: 

```shell
gnome-open <!name of file>
```

### nautilus

``sudo nautilus``: Open the folder with root permission

### Open libreoffice doc

```shell
libreoffice --writer file.odt
```

or 

```shell
libreoffice --writer file.doc
```