### stty

``stty`` displays or changes the characteristics of the terminal.

```
stty [-F DEVICE | --file=DEVICE] [SETTING]...
```

**Example**

View existed config information of ``ttyS0`` of Raspberry Pi

```
stty -F /dev/ttyS0
```

**Result**

```
speed 115200 baud; line = 0;
min = 1; time = 0;
-brkint -icrnl -imaxbel iutf8
-isig -icanon -iexten -echo -echoe -echok -echoctl -echnoke
```

### /dev/null

``echo a > /dev/null``: Redirect the standard output but you'll still see any errors. Exit status ``0``

``ecsdasdas &> /dev/null``: Redirect all output, including errors. Exit status ``127``
