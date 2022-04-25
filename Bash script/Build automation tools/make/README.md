``Make`` is a build automation tool which only runs on Unix-alike OS. Its file format can be ``Makefile`` or ``makefile``.

To run makefile, take those steps

* **Step 1**: Go to the folder that you wanna create a ``Makefile`` then create a ``Makefile``.
* **Step 2**: Run with command ``make``

A ``Makefile`` name can be name with ``mak`` or ``mk`` for several makefile to be used for a project, E.g: ``makefile1.mak``, ``makefile2.mak``, ``makefile3.mak``, ``makefile1.mk``,...

``test.mak`` or ``test.mk``

```Makefile
main:
	@echo "Hello"

test:
	@echo "test script"
```

To run ``test.mak`` or ``test.mk`` with target ``main``: ``make -f test.mak main`` and ``make -f test.mk main``
