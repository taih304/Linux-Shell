# hex
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
Variable
```sh
a=$((0x0a))
echo $a #10
```
``xxd``: Hex dump commandline tool

``echo "00 48" | xxd -rp > message``: Create a 2-byte message payload of (LSB) 00 12 (MSB) and save it to a file ``message``.

Then ``xxd message`` will result as:

```
00000000: 48                                       H
```

Different with ``-r -p``:

```
echo "00 48" | xxd -r -p > message
```

Result ``xxd messaage``:

```
00000000: 0048                                     .H
```
# binary: Define a variable with binary is not supported in Bash
```sh
# This is not supported in Bash
a=0b1 # Wrong, give compilation error
```
# float

**float** isn't supported by Bash, use [bc](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Bash%20script/Arithmetic%20expression.md#bc) for Floating-Point Arithmetic

```sh
result=$(echo "scale=3; 10 / 3" | bc)
echo "Result of division: $result"
```

```sh
a=10
b=3
result=$(echo "scale=3; $a/$b" | bc)
echo "a/b: $result"
```
**scale=3** sets the number of decimal places to three for the result of the division.

