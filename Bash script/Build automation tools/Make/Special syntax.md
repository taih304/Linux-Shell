# Up to date error with ``.PHONY``

If there is a file name ``test`` in the folder, running ``make test`` will result in error as

``make: 'test' is up to date.``

To avoid this problem you can explicitly declare the target to be phony by making it a prerequisite of the special target ``.PHONY``

```Makefile
.PHONY: test
test:
        @echo "Hello"
```	
# lastword
``$(lastword name)``:  With ``name`` is a string separated by whitespace, ``lastword`` will return its lastword.

```Makefile
main:
	@(echo $(lastword Hello, World!))
```
**Result**: ``World!``
