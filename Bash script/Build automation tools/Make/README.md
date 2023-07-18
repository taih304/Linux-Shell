# [Fundamental concepts](Fundamental%20concepts.md)

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

``$@`` helps getting the target name:
```Makefile
target_1:
	@(echo $@)

target_2:
	@(echo $@)
```
``make target_1`` results in ``target_1``. ``make target_2`` results in ``target_2``

To run ``test.mak`` or ``test.mk`` with target ``main``: ``make -f test.mak main`` and ``make -f test.mk main``

[Fundamental concepts document](Fundamental%20concepts.md) also include:
* [Architecture of a Makefile](Fundamental%20concepts.md#architecture)
* [Run the very first makefile](Fundamental%20concepts.md#run-the-very-first-makefile)
* [Avoid echoing](Fundamental%20concepts.md#avoid-echoing)
* [Work with command]()
* [Prerequisites](Fundamental%20concepts.md#prerequisites): [File](Fundamental%20concepts.md#file-as-a-prerequisite), [target](Fundamental%20concepts.md#target-as-a-prerequisite), [both file and target](Fundamental%20concepts.md#file-and-target-are-both-prerequisites) as prerequisites
* [Send argument to Makefile]()
* [Variable]()

# $(MAKE)

``$(MAKE)`` will call make command.
```sh
test:
	@(echo $(MAKE))
```
``make test`` return ``make``.
# Work with multiple Makefile

Use ``include`` to include multiple Makefile

``test.mak``

```Makefile
target_1:
	@echo "target_1"

target_2:
	@echo "target_2"
```

``Makefile``

```Makefile
include test.mak

target_3:
	@echo "target_3aaa"

target_4:
	@echo $(MAKEFILE_LIST)
```

``$(MAKEFILE_LIST)`` will return all names of the Makefile called in the current ``Makefile``

``make target_4``: ``Makefile test.mak``

# [Syntax](Syntax.md)
* [$(MAKE)](#make), [MAKEFILE_LIST](#work-with-multiple-makefile)
* [Operator]()
* [-C option]()
* [Up to date error with .PHONY]()
* [lastword](), [dir](), [abspath]()
* [wildcard](), [wildcard with %]()

