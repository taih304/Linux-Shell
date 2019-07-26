```sh
#!/bin/sh
echo "hello world"
```

#!/bin/sh : cho biết đường dẫn chạy shell nào để biên dịch, một số trình biên dịch bỏ qua câu lênh này, vẫn chạy được

Can be both ``#!bin/sh`` and ``#!bin/bash``

### Conditional state

```sh
a=9
b=10
if [ $a -gt $b ] 
then 
	echo "A is greater than B" 
else 
	echo "A is less than B" 
fi
```

```
A is less than B
```
