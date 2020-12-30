``Make`` is a build automation tool. Its file format can be ``Makefile`` or ``makefile``.

To run makefile, take those steps

* **Step 1**: Go to the folder that you wanna create a ``Makefile`` then create a ``Makefile``.
* **Step 2**: Run with command ``make``

A ``Makefile`` name can be name with ``name.mak`` for several makefile to be used for a project, E.g: ``makefile1.mak``, ``makefile2.mak``, ``makefile3.mak``,...

``test.mak``

```Makefile
main:
	@echo "Hello"

test:
	@echo "test script"
```

To run ``test.mak`` with target ``main``: ``make -f test.mak main``