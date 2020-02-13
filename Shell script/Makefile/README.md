### Step by step

* **Step 1**: Go to the folder that you wanna create a Makefile
* **Step 2**: Create a Makefile
* **Step 3**: Makefile architecture

    ```
    target: prerequisites
        <TAB> recipe
    ```    
    Where target is like a function name

    **Example**

    ```Makefile
    hello:
	    echo "Hello"
    ```
* **Step 4**: Type ``make``

    **Result**: 

    ```
    echo "Hello"
    Hello
    ```

* **Step 5**: To print out only ``"Hello"``: 

    ```Makefile
    hello:
	    @echo "Hello"
    ```

* **Step 6**: To make a specific target/funtion: ``make target_name``