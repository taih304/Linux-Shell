## hex
```sh
echo $((0x0a)) #10
```
```sh
echo $((16#A)) #10
echo $((16#a)) #10
```

```sh
a=b
echo $((16#$a)) #11
```

``xxd``: Hex dump commandline tool

``echo "00 12" | xxd -rp > message``: Create a 2-byte message payload of (LSB) 00 12 (MSB) and save it to a file ``message``.

Then ``xxd message`` will result in:

```
00000000: 12                                       .
```
